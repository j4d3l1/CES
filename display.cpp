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
    qDebug() << "displayAll was called";
    displayAttached(d);
    displayClock(d);
    displayFreq(d);
    return;
}

void Display::displayAttached(CESDevice *d){
    qDebug() << "displayAttached was called";
    if(d->getAttached()){
        ui->isAttached->setText("ATTACHED");
    }else{
        ui->isAttached->setText("DETACHED");
    }
    return;
}

void Display::displayTime(CESDevice *d){
    QTime time = QTime::currentTime();
    QString text = time.toString("hh:mm");

    if ((time.second() % 2) == 0)
          text[2] = ' ';
    ui->timerDisplay->display(text);
}

void Display::displayClock(CESDevice *d){
    QTime time = d->getClock();
    QString text = time.toString("hh:mm");

    if ((time.second() % 2) == 0)
          text[2] = ' ';
    ui->clockDisplay->display(text);
}

void Display::displayFreq(CESDevice *d){
    qDebug() << "displayFreq was called";
    float f = d->getFreq();
    QString s = QString::number(f);
    ui->frequencySelected->setText(s);
    return;
}
