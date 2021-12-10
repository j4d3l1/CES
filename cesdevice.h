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
#include <QString>

#include "recording.h"

class CESDevice
{

public:
    CESDevice();
    ~CESDevice();

    //getters
    bool getAttached();
    int getTime();
    QTime getClock();
    QString getWaveForm();
    float getFreq();
    bool getTurnedOn();
    int getPowerLevel();
    Recording* getLastTreatment();
    float getBattery();
    int getTimer();
    QVector<Recording*>* getHistory();

    //setters
    void setAttached(bool);
    void setTime(int);
    void setWaveForm(QString);
    void setFreq(float);
    void setPowerLevel(int);
    void setTimer(int);
    void setBattery(float);

    void clearHistory();          // empties history
    void addEntry(Recording*);    // adds a recording to history
    Recording* findRecording(QString);
    void turnOnOff();



private:
    bool turnedOn;
    int powerLevel;
    bool attached;
    float frequency;
    QString waveForm;
    float batteryPower;
    int time;
    int timer;
    QTime clock;
    QDateTime timeStart;
    QDateTime timeEnd;
    Recording *lastTreatment;
    QVector<Recording*> history;  // all past treatments

};

#endif // CESDEVICE_H
