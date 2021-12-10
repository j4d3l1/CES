#ifndef RECORDING_H
#define RECORDING_H

#include <QObject>
#include <QDateTime>

class Recording
{
public:
    Recording();
    ~Recording();
    QString toQString();

    //getters
    int getRCurrent();
    float getRFrequency();
    QString getRWaveForm();
    QDateTime getRStart();
    QDateTime getREnd();
    int getRDuration();

    //setters
    void setRCurrent(int);
    void setRFrequency(float);
    void setRWaveForm(QString);
    void setRStart(QDateTime);
    void setREnd(QDateTime);
    void setRDuration(int);

private:
    int rCurrent;
    float rFrequency;
    QString rWaveForm;
    QDateTime startTime;
    QDateTime endTime;
    int duration;

};

#endif // RECORDING_H
