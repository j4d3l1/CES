#include "electrodepads.h"
#include "ui_electrodepads.h"

ElectrodePads::ElectrodePads(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::ElectrodePads)
{
    ui->setupUi(this);



    //connectiing attach and detach slots
    connect(ui->attach, SIGNAL(released()), this, SLOT(slotAttach()));
    connect(ui->detach, SIGNAL(released()), this, SLOT(slotDetach()));

}

ElectrodePads::~ElectrodePads()
{
    delete ui;
}

void ElectrodePads::slotAttach(){
    qDebug() << "the electrodePads are attached";
    attached = true;
}

void ElectrodePads::slotDetach(){
    qDebug() << "the electrodePads are detached";
    attached = false;
}
