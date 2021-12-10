#include "display.h"
#include "ui_display.h"

Display::Display(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Display)
{
    ui->setupUi(this);
}

Display::~Display()
{
    delete ui;
}


void Display::displayAll(CESDevice *d){
    displayAttached(d);
    displayClock(d);
    displayFreq(d);
    displayTime(d);
    displayWaveForm(d);
    displayPowerLevel(d);
    displayBattery(d);
    displayCountDown(d);
    return;
}

void Display::displayAttached(CESDevice *d){
    if(d->getAttached()){
        ui->isAttached->setText("ATTACHED");
    }else{
        ui->isAttached->setText("DETACHED");
    }
    return;
}

void Display::displayCountDown(CESDevice *d){
    int i = d->getTimer();
    ui->timerDisplay->display(i);
    return;
}

void Display::displayClock(CESDevice *d){
    QTime time = d->getClock();
    QString text = time.toString("hh:mm");

    if ((time.second() % 2) == 0)
          text[2] = ' ';
    ui->clockDisplay->display(text);
}

void Display::displayFreq(CESDevice *d){
    float f = d->getFreq();
    QString s = QString::number(f);
    ui->frequencySelected->setText(s);
    return;
}

void Display::displayTime(CESDevice *d){        // just shows the time selected
    int i = d->getTime();
    QString s = QString::number(i);
    ui->timeSelected->setText(s);
    return;
}

void Display::displayWaveForm(CESDevice *d){
    QString s = d->getWaveForm();
    ui->waveformSelected->setText(s);
    return;
}

void Display::displayPowerLevel(CESDevice *d){
    int i = d->getPowerLevel();
    QString s = QString::number(i);
    ui->powerLevelDisplay->setText(s);
    return;
}

void Display::displayBattery(CESDevice *d){
    float f = d->getBattery();
    ui->batteryDisplay->setValue(f);
    return;
}


