#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    //instantiate the model
    model = new CESDevice();

    //set up mode
    mode = POWER_OFF;

    //setup display UI
    display = new Display();
    ui->displayHolder->addWidget(display);

    //display timer set up
    displayTimer = new QTimer(this);
    connect(displayTimer, SIGNAL(timeout()), this, SLOT(displayTimerSlot()));
    displayTimer->start(1000);

    //idle timer set up
    idleCounter = 0;

    //hooking up attach/detach toggle
    connect(ui->attachToggle, SIGNAL(pressed()), this, SLOT(slotAttachToggle()));

    //hooking up time select buttons
    connect(ui->time20, SIGNAL(released()), this, SLOT(slotTime20()));
    connect(ui->time40, SIGNAL(released()), this, SLOT(slotTime40()));
    connect(ui->time60, SIGNAL(released()), this, SLOT(slotTime60()));

    //hooking up waveform selected buttons
    connect(ui->alpha, SIGNAL(released()), this, SLOT(slotAlpha()));
    connect(ui->beta, SIGNAL(released()), this, SLOT(slotBeta()));
    connect(ui->gamma, SIGNAL(released()), this, SLOT(slotGamma()));

    //hooking up frequency select buttons
    connect(ui->freq5, SIGNAL(released()), this, SLOT(slotFreq5()));
    connect(ui->freq77, SIGNAL(released()), this, SLOT(slotFreq77()));
    connect(ui->freq100, SIGNAL(released()), this, SLOT(slotFreq100()));

    //hooking up setTreatment to start treatment button
    connect(ui->startTreatment, SIGNAL(released()), this, SLOT(slotTreatment()));

    //hooking up powerOnOff button
    connect(ui->onOffToggle, SIGNAL(released()), this, SLOT(slotOnOffPower()));

    //hooking up upPowerLevel and downPowerLevel buttons
    connect(ui->powerLevelUpButton, SIGNAL(released()), this, SLOT(slotUpPower()));
    connect(ui->powerLevelDownButton, SIGNAL(released()), this, SLOT(slotDownPower()));


    //hooking up record and do not record buttons
    //they are default invisible
    ui->recordButton->setVisible(false);
    ui->dontRecordButton->setVisible(false);
    ui->startRecordedTreatment->setVisible(false);
    connect(ui->recordButton, SIGNAL(released()), this, SLOT(slotRecord()));
    connect(ui->dontRecordButton, SIGNAL(released()), this, SLOT(slotDontRecord()));
    connect(ui->startRecordedTreatment, SIGNAL(released()), this, SLOT(slotRepeatTreatment()));

}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::displayTimerSlot(){

    if(mode == IDLE || mode == RECORDING){
        idleCounter++;
    }

    //if no buttons have been pushed for 30min, turn off power
    if((mode == IDLE || mode == RECORDING) && idleCounter > 30){
        ui->statusMessage->setText("Device has not been used in 30 minues, powering off.");
        mode = POWER_OFF;
    }

    if(mode == IDLE){
        if(!model->getHistory()->empty()){
            ui->startRecordedTreatment->setVisible(true);
        }
    }

    //if state isnt RECORDING, make record buttons unavailable so can't record
    if(mode != RECORDING){
        ui->recordButton->setVisible(false);
        ui->dontRecordButton->setVisible(false);
    }

    // draining battery
    if(mode != POWER_OFF){
        // battery should just be constantly draining if state isnt power_off
        model->setBattery(model->getBattery() - 0.4);     // decrease battery by 0.4 each time, 1 is too fast

        //if the battery reaches 5% or below, can display warning in an ifblock here
        if (model->getBattery() < 5 && model->getBattery() > 2){
            ui->statusMessage->setText("WARNING! BATTERY LEVEL BELOW 5%!");
        }

        if(model->getBattery() <= 2){       // if the battery reaches %2, power_off
            slotOnOffPower();       // turn off device
            ui->onOffToggle->setChecked(false);     // uncheck on off toggle
            ui->onOffToggle->setVisible(false);
        }
    }

    // if someone presses power off at any point, reset everything to default
    if(mode == POWER_OFF){
        model->setFreq(0);
        model->setTime(0);
        model->setWaveForm("None");
        model->setPowerLevel(0);        // power level is 0 when powerred off
        ui->onOffToggle->setChecked(false);     // uncheck on off toggle
    }

    // checking attachment status if in session
    if (mode == IN_SESSION){
        if (model->getAttached() == false){
            detachCounter++;
            if (detachCounter >= 5){   // according to extension, if the electrodes are detached for 5 seconds, current/powerLevel goes to 100s

                // resetting CESDevice
                model->setFreq(0);
                model->setTime(0);
                model->setWaveForm("None");
                model->setPowerLevel(100);      // 100 when not powered off

                // changing state
                mode = IDLE;

                ui->statusMessage->setText("Electrodes were detached for over 5 seconds during treatment, back to IDLE");
            }
        }
        if (model->getAttached() == true){
            detachCounter = 0;                  // if attached, reset detachCounter back to 0
            ui->statusMessage->setText("Treatment in progress.");
        }
    }

    if(mode == IN_SESSION){
        // timer counting down, when it reaches 0, record endtime for lastTreatment
            // also when it reaches 0, reset freq, wavelength, and time for cesDevice back to default 0, None, 0
            // also set timer back to nothing
        model->setTimer(model->getTimer() - 1); // decrement timer by 1

        if (model->getTimer() == 0){    // when treatment timer gets to 0

            // capturing variables for lastTreatment recording
            model->getLastTreatment()->setREnd(QDateTime::currentDateTime());   // setting cesdevice's lastTreatment's end time
            model->getLastTreatment()->setRCurrent(model->getPowerLevel());     // setting cesdevice's lastTreatment's current/power level

            // resetting CESDevice
            model->setFreq(0);
            model->setTime(0);
            model->setWaveForm("None");
            model->setPowerLevel(100);      // 100 when not powered off

            // changing state
            mode = RECORDING;          // state is now RECORDING
            ui->statusMessage->setText("Select record or do not record.");
            ui->recordButton->setVisible(true);
            ui->dontRecordButton->setVisible(true);

        }

    }

    display->displayAll(model);
}


void MainWindow::slotAttachToggle(){
    idleCounter = 0;

    model->setAttached(!model->getAttached());
}

void MainWindow::slotTime20(){
    idleCounter = 0;

    if(mode == IDLE){
        model->setTime(20);
    }
    return;
}

void MainWindow::slotTime40(){
    idleCounter = 0;

    if(mode == IDLE){
        model->setTime(40);
    }
    return;
}

void MainWindow::slotTime60(){
    idleCounter = 0;

    if(mode == IDLE){
        model->setTime(60);
    }
    return;
}

void MainWindow::slotAlpha(){
    idleCounter = 0;

    if(mode == IDLE){
        model->setWaveForm("Alpha");
    }
    return;
}


void MainWindow::slotBeta(){
    idleCounter = 0;

    if(mode == IDLE){
        model->setWaveForm("Beta");
    }
    return;
}

void MainWindow::slotGamma(){
    idleCounter = 0;

    if(mode == IDLE){
        model->setWaveForm("Gamma");
    }
    return;
}

void MainWindow::slotFreq5(){
    idleCounter = 0;

    if(mode == IDLE){
        model->setFreq(0.5);
    }
    return;
}

void MainWindow::slotFreq77(){
    idleCounter = 0;

    if(mode == IDLE){
        model->setFreq(77);
    }
    return;
}

void MainWindow::slotFreq100(){
    idleCounter = 0;

    if(mode == IDLE){
        model->setFreq(100);
    }
    return;

}

void MainWindow::slotUpPower(){
    idleCounter = 0;

    if(mode == IN_SESSION){
        model->setPowerLevel(model->getPowerLevel() + 50);

        if(model->getPowerLevel() > 500){
            ui->statusMessage->setText("WARNING! POWER LEVEL ABOVE 500");
        }

        if(model->getPowerLevel() > 700){
            slotOnOffPower();       // turn off device
            ui->onOffToggle->setChecked(false);     // uncheck on off toggle
            ui->statusMessage->setText("POWER LEVEL TOO HIGH, POWERING OFF");
        }
    }
    return;

}

void MainWindow::slotDownPower(){
    idleCounter = 0;

    if(mode == IN_SESSION){
        model->setPowerLevel(model->getPowerLevel() - 100);
    }
    if(model->getPowerLevel() < 0){
        model->setPowerLevel(0);
    }
    return;

}

void MainWindow::slotTreatment(){
    idleCounter = 0;

    if(mode == IDLE){
        if (model->getFreq() == 0){     // 0 is the default freq when nothings been selected
            ui->statusMessage->setText("Cannot start treatment, no frequency chosen.");
            return;
        } else if (model->getTime() == 0){  // 0 is default time when nothings been selected
            ui->statusMessage->setText("Cannot start treatment, no time chosen.");
            return;
        } else if (model->getWaveForm() != "Alpha" &&
                   model->getWaveForm() != "Beta" &&
                   model->getWaveForm() != "Gamma"){
             ui->statusMessage->setText("Cannot start treatment, no waveForm chosen.");
            return;
        } else if(model->getAttached() == false){
            ui->statusMessage->setText("Cannot start treatment, electrodes not attached.");
            return;
        }


        // preparing to start treatment:
        ui->statusMessage->setText("Treatment in progress.");
        // CAPTURE WAVEFORM, FREQUENCY, DURATION, AND TIMESTART HERE!!! FOR CESDevice's LastTreatment
        // CAPTURE current, endtime, at the end of the treatment - inside displayTimer?
        Recording* last = model->getLastTreatment();
        last->setRFrequency(model->getFreq());
        last->setRWaveForm(model->getWaveForm());
        last->setRDuration(model->getTime());
        last->setRStart(QDateTime::currentDateTime());

        // setting timer to time
        model->setTimer(model->getTime());

        mode = IN_SESSION;
        return;
    }
    ui->statusMessage->setText("Cannot start treatment, device is not in IDLE.");
}

void MainWindow::slotOnOffPower(){
    idleCounter = 0;

    model->turnOnOff();
    if(model->getTurnedOn()){
        mode = IDLE;
        model->setPowerLevel(100);
        ui->statusMessage->setText("Device is on."); // Clear status message when device is on/off
    } else {
        mode = POWER_OFF;
        model->setPowerLevel(0);
        ui->statusMessage->setText("Device is off.");
    }
}

void MainWindow::slotRecord(){
    idleCounter = 0;

    model->addEntry(model->getLastTreatment());
    ui->historySelector->addItem(model->getLastTreatment()->toQString());
    mode = IDLE;
}

void MainWindow::slotDontRecord(){
    idleCounter = 0;
    mode = IDLE;
}

void MainWindow::slotRepeatTreatment(){
    idleCounter = 0;

    if(mode == IDLE){
        QString selected = ui->historySelector->currentText();
        Recording* treatment = model->findRecording(selected);
        if(treatment != NULL){
            if(model->getAttached() == false){
                ui->statusMessage->setText("Cannot start treatment, electrodes not attached.");
                return;
            }

            ui->statusMessage->setText("Repeating Treatment in progress.");

            //update the model
            model->setFreq(treatment->getRFrequency());
            model->setWaveForm(treatment->getRWaveForm());
            model->setTime(treatment->getRDuration());
            model->setPowerLevel(treatment->getRCurrent());

            //update the last treatment
            Recording* last = model->getLastTreatment();
            last->setRFrequency(treatment->getRFrequency());
            last->setRWaveForm(treatment->getRWaveForm());
            last->setRDuration(treatment->getRDuration());
            last->setRStart(QDateTime::currentDateTime());

            model->setTimer(treatment->getRDuration());
            mode = IN_SESSION;
        }
    }
}

