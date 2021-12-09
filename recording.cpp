#include "recording.h"

/*
Recording::Recording(int current, int frequency, QString wave, QDateTime start, QDateTime end)
{
    // instead of setting everything in constructor, maybe have alot of setters instead?
    // because don't know all this information at time of constructor call
    // and different functions may have different information about lastTreatment, cant call in same place
    rCurrent = current;
    rFrequency = frequency;
    rWaveForm = wave;
    startTime = start;
    endTime = end;
    duration = start.secsTo(end);
}
*/

Recording::Recording(){

}

Recording::~Recording(){

}

int Recording::getRCurrent(){
    return rCurrent;
}

float Recording::getRFrequency(){
    return rFrequency;
}

QString Recording::getRWaveForm(){
    return rWaveForm;
}

QDateTime Recording::getRStart(){
    return startTime;
}

QDateTime Recording::getREnd(){
    return endTime;
}

int Recording::getRDuration(){
    return duration;
}


void Recording::setRCurrent(int i){
    rCurrent = i;
    return;
}

void Recording::setRFrequency(float f){
    rFrequency = f;
    return;
}

void Recording::setRWaveForm(QString s){
    rWaveForm = s;
    return;
}

void Recording::setRStart(QDateTime t){
    startTime = t;
    return;
}

void Recording::setREnd(QDateTime t){
    endTime = t;
    return;
}

void Recording::setRDuration(int i){
    duration = i;
    return;
}

QString Recording::toQString(){
    QString s = "Start: " +  startTime.toString()
            + " End: " + endTime.toString()
            + " Duration: " + QString::number(duration)
            + " Frequency: " + QString::number(rFrequency)
            + " WaveForm: " + rWaveForm
            + " PowerLevel: " + QString::number(rCurrent);
    return s;
}
