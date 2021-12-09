#include "cesdevice.h"

CESDevice::CESDevice()
{
    //default values
    turnedOn = false;
    frequency = 0;
    time = 0;
    waveForm = "None";
    attached = false;
    powerLevel = 0;     //default value for current when device is off, 100 when not off
    lastTreatment = new Recording();
    batteryPower = 100;


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

float CESDevice::getBattery(){
    return batteryPower;
}

int CESDevice::getTimer(){
    return timer;
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

void CESDevice::setBattery(float f){
    batteryPower = f;
    return;
}

void CESDevice::turnOnOff(){
    turnedOn = !turnedOn;
}

void CESDevice::clearHistory(){
    history.clear();

}

void CESDevice::addEntry(Recording* r){
    // need to make a copy of r to put in history, r doesn't change
    Recording* entry = new Recording();
    entry->setRCurrent(r->getRCurrent());
    entry->setRFrequency(r->getRFrequency());
    entry->setRWaveForm(r->getRWaveForm());
    entry->setRStart(r->getRStart());
    entry->setREnd(r->getREnd());
    entry->setRDuration(r->getRDuration());

    history.append(entry);

}








