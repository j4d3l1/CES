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
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::displayTimerSlot(){
    qDebug() << "\n";
    qDebug() << "displayTimer...";
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

void MainWindow::slotTreatment(){
    if (model->getFreq() == 0){     // 0 is the default freq when nothings been selected
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
    }

    mode = IN_SESSION;
    qDebug() << "starting treatment now";
    //treatment() can go here
}





