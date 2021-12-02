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

class CESDevice
{
public:
    CESDevice();

    void signalLowBattery();




private:
    bool onOff;
    int current;
    double frequency;
    QString waveForm;
    int batteryPower;
    int countDownCycle;
    QDateTime timeStart;
    QDateTime timeEnd;
    //Recording lastTreatment;        // requires Recording class to be defined

    void treatment();

public slots:
    //void slotSetTreatment();
    //void slotUpPower();     // increases power by 50
    //void slotDownPower();   // decreases power by 100
    //void slotOnOffPower();
    //void slotRecord();

};

#endif // CESDEVICE_H
