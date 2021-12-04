#include "cesdevice.h"

CESDevice::CESDevice()
{
    current = 100;      //default value for current
    frequency = 0;
    time = 0;
    elecpad = new ElectrodePads();

}

CESDevice::~CESDevice(){
    delete elecpad;
}

bool CESDevice::getAttached(){

    if (elecpad->getAttached()){
        qDebug() << "ces getAttached called is returning true";
    }else{
        qDebug() << "ces getAttached called is returning false";
    }
    return elecpad->getAttached();
}


int CESDevice::getTime(){
    return time;
}


QString CESDevice::getWaveForm(){
    return waveForm;
}

float CESDevice::getFreq(){
    return frequency;
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







