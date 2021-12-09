#include "cesdevice.h"

CESDevice::CESDevice()
{
    //default values
    turnedOn = false;
    current = 100;      //default value for current
    frequency = 0;
    time = 0;
    waveForm = "None";
    attached = false;
    powerLevel = 0;
    lastTreatment = new Recording();

}

CESDevice::~CESDevice(){
    //delete lastTreatment;
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

bool CESDevice::getTurnedOn(){
    return turnedOn;
}

int CESDevice::getPowerLevel(){
    return powerLevel;
}

Recording* CESDevice::getLastTreatment(){
    return lastTreatment;
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

void CESDevice::setPowerLevel(int i){
    powerLevel = i;
    return;
}

void CESDevice::setTimer(int i){
    timer = i;
    return;
}

void CESDevice::turnOnOff(){
    turnedOn = !turnedOn;
}








