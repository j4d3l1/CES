#include "recording.h"

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
