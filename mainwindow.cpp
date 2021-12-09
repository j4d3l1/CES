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

}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::displayTimerSlot(){        // treatment logic in here?
    qDebug() << "\n";
    //qDebug() << "displayTimer...";

    // draining battery
    if(mode != POWER_OFF){
        // battery should just be constantly draining if state isnt power_off
        model->setBattery(model->getBattery() - 0.4);     // decrease battery by 0.4 each time, 1 is too fast

        //if the battery reaches 10% or below, can display warning in an ifblock here

        if(model->getBattery() <= 0){       // if the battery reaches 0, power_off
            mode = POWER_OFF;
        }
    }

    // checking attachment status
    if (model->getAttached() == false){
        detachCounter++;
        if (detachCounter >= 5){            // according to extension, if the electrodes are detached for 5 seconds, current/powerLevel goes to 100s
            model->setPowerLevel(100);
            qDebug() << "electrodes were detached for more than 5 seconds, resetting power level to 100";
        }
    }
    if (model->getAttached() == true){
        detachCounter = 0;                  // if attached, reset detachCounter back to 0
    }

    //treatment logic in here???
    if(mode == IN_SESSION){
        //if the electrodes are detached, go back to idle, reset freq, waveform, time, and timer to 0
        //else
            //timer counting down

    }

    display->displayAll(model);
}


void MainWindow::slotAttachToggle(){
    qDebug() << "toggled";
    model->setAttached(!model->getAttached());
    if (model->getAttached()){
        qDebug() << "attached is true";
    }else{
        qDebug() << "attached is false";
    }
    //return;
}

void MainWindow::slotTime20(){
    if(mode == IDLE){
        model->setTime(20);
        if(model->getTime() == 20){
            qDebug() << "time is now 20";
        }
    }
    return;
}

void MainWindow::slotTime40(){
    if(mode == IDLE){

        model->setTime(40);
        if(model->getTime() == 40){
            qDebug() << "time is now 40";
        }
    }
    return;
}

void MainWindow::slotTime60(){
    if(mode == IDLE){

        model->setTime(60);
        if(model->getTime() == 60){
            qDebug() << "time is now 60";
        }
    }
    return;
}

void MainWindow::slotAlpha(){
    if(mode == IDLE){

        model->setWaveForm("Alpha");
        if(model->getWaveForm() == "Alpha"){
            qDebug() << "waveForm is now alpha";
        }
    }
    return;
}


void MainWindow::slotBeta(){
    if(mode == IDLE){

        model->setWaveForm("Beta");
        if(model->getWaveForm() == "Beta"){
            qDebug() << "waveForm is now beta";
        }
    }
    return;
}

void MainWindow::slotGamma(){
    if(mode == IDLE){
        model->setWaveForm("Gamma");
        if(model->getWaveForm() == "Gamma"){
            qDebug() << "waveForm is now gamma";
        }
    }
    return;
}

void MainWindow::slotFreq5(){
    if(mode == IDLE){
        model->setFreq(0.5);
        if(model->getFreq() == 0.5){
            qDebug() << "frequency is now 0.5";
        }
    }
    return;
}

void MainWindow::slotFreq77(){
    if(mode == IDLE){
        model->setFreq(77);
        if(model->getFreq() == 77){
            qDebug() << "frequency is now 77";
        }
    }
    return;
}

void MainWindow::slotFreq100(){
    if(mode == IDLE){
        model->setFreq(100);
        if(model->getFreq() == 100){
            qDebug() << "frequency is now 100";
        }
    }
    return;

}

void MainWindow::slotUpPower(){
    if(mode == IN_SESSION){
        model->setPowerLevel(model->getPowerLevel() + 50);
        qDebug() << "increased power level by 50";
    }
    return;

}

void MainWindow::slotDownPower(){
    if(mode == IN_SESSION){
        model->setPowerLevel(model->getPowerLevel() - 100);
        qDebug() << "decreased power level by 100";
    }
    return;

}

void MainWindow::slotTreatment(){
    if(mode == IDLE){
        if (model->getFreq() == 0){     // 0 is the default freq when nothings been selected
            ui->errorMessages->setText("cannot start treatment, no frequency chosen");
            qDebug() << "cannot start treatment, no frequency chosen";
            return;
        } else if (model->getTime() == 0){  // 0 is default time when nothings been selected
            qDebug() << "cannot start treatment, no time chosen";
            return;
        } else if (model->getWaveForm() != "Alpha" &&
                   model->getWaveForm() != "Beta" &&
                   model->getWaveForm() != "Gamma"){
            qDebug() << "cannot start treatment, no waveForm chosen";
            return;
        } else if(model->getAttached() == false){
            qDebug() << "cannot start treatment, electrodes not attached";
            return;
        }


        mode = IN_SESSION;
        qDebug() << "starting treatment now";

        // CAPTURE WAVEFORM, FREQUENCY, DURATION, AND TIMESTART HERE!!! FOR CESDevice's LastTreatment
        // CAPTURE current, endtime, at the end of the treatment - inside displayTimer?
        Recording* last = model->getLastTreatment();
        last->setRFrequency(model->getFreq());
        last->setRWaveForm(model->getWaveForm());
        last->setRDuration(model->getTime());
        last->setRStart(QDateTime::currentDateTime());
        return;
    }

    qDebug() << "cannot start treatment, device is not in IDLE";
    //model->treatment() can go here??
        // at end of treatment, the display freq and time should go back to 0, and selected wavelength should be blank again
}

void MainWindow::slotOnOffPower(){
    model->turnOnOff();
    if(model->getTurnedOn()){
        mode = IDLE;
        qDebug() << "Turned on device";
    } else {
        mode = POWER_OFF;
        qDebug() << "Turned off device";

    }
}


