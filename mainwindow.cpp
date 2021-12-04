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




