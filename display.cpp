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


