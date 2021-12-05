#include "cesdevice.h"

CESDevice::CESDevice()
{
    //default values
    current = 100;      //default value for current
    frequency = 0;
    time = 0;
    attached = false;

}

CESDevice::~CESDevice(){

}




int CESDevice::getTime(){
    return time;
}

QTime CESDevice::getClock(){
    clock = QTime::currentTime();
    return clock;
}

QString CESDevice::getWaveForm(){
    return waveForm;
}

float CESDevice::getFreq(){
    return frequency;
}

bool CESDevice::getAttached(){
    return attached;
}

void CESDevice::setTime(int i){
    time = i;
    return;
}

void CESDevice::setWaveForm(QString s){
    waveForm = s;
    return;
}

void CESDevice::setFreq(float f){
    frequency = f;
    return;
}

void CESDevice::setAttached(bool b){
    attached = b;
    return;
}







