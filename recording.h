#ifndef RECORDING_H
#define RECORDING_H

#include <QObject>
#include <QDateTime>

class Recording
{
public:
    Recording(int current, int frequency, QString wave, QDateTime start, QDateTime end);
    QString stringToLabel();

private:
    int rCurrent;
    int rFrequency;
    QString rWaveForm;
    QDateTime startTime;
    QDateTime endTime;
    int duration;
};

#endif // RECORDING_H
