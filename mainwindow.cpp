#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    //instantiate the model
    model = new CESDevice();

    //setup display UI
    display = new Display();
    ui->displayHolder->addWidget(display);

    //setup electrode pad UI
    electrodePads = new ElectrodePads();
    ui->electrodePadHolder->addWidget(electrodePads);

    //display timer set up
    displayTimer = new QTimer(this);
    connect(displayTimer, SIGNAL(timeout()), this, SLOT(displayTimerSlot()));
    displayTimer->start(1000);

    //hooking up time select buttons
    connect(ui->time20, SIGNAL(released()), this, SLOT(slotTime20()));
    connect(ui->time40, SIGNAL(released()), this, SLOT(slotTime40()));
    connect(ui->time60, SIGNAL(released()), this, SLOT(slotTime60()));

    //hooking up waveform selected buttons
    connect(ui->alpha, SIGNAL(released()), this, SLOT(slotAlpha()));
    connect(ui->beta, SIGNAL(released()), this, SLOT(slotBeta()));
    connect(ui->gamma, SIGNAL(released()), this, SLOT(slotGamma()));

    //hooking up frequency select

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

void MainWindow::slotTime20(){
    model->setTime(20);
    if(model->getTime() == 20){
        qDebug() << "time is now 20";
    }
    return;
}

void MainWindow::slotTime40(){
    model->setTime(40);
    if(model->getTime() == 40){
        qDebug() << "time is now 40";
    }
    return;
}

void MainWindow::slotTime60(){
    model->setTime(60);
    if(model->getTime() == 60){
        qDebug() << "time is now 60";
    }
    return;
}

void MainWindow::slotAlpha(){
    model->setWaveForm("Alpha");
    if(model->getWaveForm() == "Alpha"){
        qDebug() << "waveForm is now alpha";
    }
    return;
}


void MainWindow::slotBeta(){
    model->setWaveForm("Beta");
    if(model->getWaveForm() == "Beta"){
        qDebug() << "waveForm is now beta";
    }
    return;
}

void MainWindow::slotGamma(){
    model->setWaveForm("Gamma");
    if(model->getWaveForm() == "Gamma"){
        qDebug() << "waveForm is now gamma";
    }
    return;
}



