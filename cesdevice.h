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

#include "recording.h"

class CESDevice
{
    // if add in the Q_OBJECT macro here, get an undefined reference to vtable for CESDevice error
    // i don't know how to fix that so I moved all the slots to MainWindow
public:
    CESDevice();
    ~CESDevice();

    //void signalLowBattery();


    //getters
    bool getAttached();
    int getTime();
    QTime getClock();
    QString getWaveForm();
    float getFreq();
    bool getTurnedOn();
    int getPowerLevel();
    Recording* getLastTreatment();

    //setters
    void setAttached(bool);
    void setTime(int);
    void setWaveForm(QString);
    void setFreq(float);
    void setPowerLevel(int);
    void setTimer(int);

    void turnOnOff();



private:
    bool turnedOn;
    bool attached;
    int current;
    float frequency;
    QString waveForm;
    int powerLevel;
    int batteryPower;
    int countDownCycle;
    int time;
    int timer;
    QTime clock;
    QDateTime timeStart;
    QDateTime timeEnd;
    Recording *lastTreatment;

    //void treatment();

public slots:
    // i don't think this class can handle any slots
    // I can't put the macro in this class without getting a weird error
    //void slotSetTreatment();
    //void slotUpPower();     // increases power by 50
    //void slotDownPower();   // decreases power by 100
    //void slotRecord();


};

#endif // CESDEVICE_H
