#include "cesdevice.h"

CESDevice::CESDevice()
{
    current = 100;      //default value for current
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


