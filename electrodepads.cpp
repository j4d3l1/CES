#include "electrodepads.h"
#include "ui_electrodepads.h"

ElectrodePads::ElectrodePads(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::ElectrodePads)
{
    ui->setupUi(this);

    //default values
    attached = false;



    //connectiing attach and detach slots
    connect(ui->attach, SIGNAL(released()), this, SLOT(slotAttach()));
    connect(ui->detach, SIGNAL(released()), this, SLOT(slotDetach()));

}

ElectrodePads::~ElectrodePads()
{
    delete ui;
}

bool ElectrodePads::getAttached(){
    if (attached){
        qDebug() << "elec getAttached called is returning true";
    }else{
        qDebug() << "elec getAttached called is returning false";
    }
    return attached;
}

void ElectrodePads::slotAttach(){
    qDebug() << "the electrodePads are attached";
    attached = true;
    if (attached){
        qDebug() << "attached is true";
    }else{
        qDebug() << "attached is false";
    }
    return;
}

void ElectrodePads::slotDetach(){
    qDebug() << "the electrodePads are detached";
    attached = false;
    if (attached){
        qDebug() << "attached is true";
    }else{
        qDebug() << "attached is false";
    }
    return;
}
