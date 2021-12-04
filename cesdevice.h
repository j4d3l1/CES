#ifndef CESDEVICE_H
#define CESDEVICE_H

#include <QMainWindow>
#include <QWidget>
#include <QPushButton>
#include <QObject>
#include <QLayout>
#include <QDebug>
#include <QVector>
#include <QThread>
#include <QTimer>
#include <QRandomGenerator>
#include <QDateTime>

#include "electrodepads.h"

class CESDevice
{
    // if add in the Q_OBJECT macro here, get an undefined reference to vtable for CESDevice error
    // i don't know how to fix that so I moved all the slots to MainWindow
public:
    CESDevice();
    ~CESDevice();

    //void signalLowBattery();

    bool getAttached();

    void setTime(int);
    void setWaveForm(QString);
    int getTime();
    QString getWaveForm();


private:
    bool onOff;
    int current;
    double frequency;
    QString waveForm;
    int batteryPower;
    int countDownCycle;
    int time;
    QDateTime timeStart;
    QDateTime timeEnd;
    ElectrodePads *elecpad;
    //Recording lastTreatment;        // requires Recording class to be defined

    //void treatment();

public slots:
    // i don't think this class can handle any slots
    // I can't put the macro in this class without getting a weird error
    //void slotSetTreatment();
    //void slotUpPower();     // increases power by 50
    //void slotDownPower();   // decreases power by 100
    //void slotOnOffPower();
    //void slotRecord();


};

#endif // CESDEVICE_H
