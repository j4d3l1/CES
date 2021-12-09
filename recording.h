#ifndef RECORDING_H
#define RECORDING_H

#include <QObject>
#include <QDateTime>

class Recording
{
public:
    //Recording(int current, int frequency, QString wave, QDateTime start, QDateTime end);
    Recording();
    ~Recording();
    QString stringToLabel();

    //setters
    void setRCurrent(int);
    void setRFrequency(int);
    void setRWaveForm(QString);
    void setRStart(QDateTime);
    void setREnd(QDateTime);
    void setRDuration(int);

private:
    int rCurrent;
    int rFrequency;
    QString rWaveForm;
    QDateTime startTime;
    QDateTime endTime;
    int duration;

};

#endif // RECORDING_H
