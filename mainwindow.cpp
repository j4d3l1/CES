#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    //setup display UI
    display = new Display();
    ui->displayHolder->addWidget(display);

    //setup electrode pad UI
    electrodePads = new ElectrodePads();
    ui->electrodePadHolder->addWidget(electrodePads);


}

MainWindow::~MainWindow()
{
    delete ui;
}

CESDevice* MainWindow::getModel(){
    return model;
}

