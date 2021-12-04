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
    /* something is wrong with this function, if you run the code, and press the attach
     * and detach buttons, you'll see that they change the bool attached in electrodepads.cpp
     * but this getAttached always returns the default value of that bool attached.
     * I don't know why this ia happening. It's as if once the timer starts the bool attached
     * can't be changed but this shouldn't be the case
     * the cesDevice getattached and the display displayAttached relies on this function
    */
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
