#ifndef DISPLAY_H
#define DISPLAY_H

#include <QWidget>
#include "cesdevice.h"


namespace Ui {
class Display;
}

class Display : public QWidget
{
    Q_OBJECT

public:
    explicit Display(QWidget *parent = nullptr);
    ~Display();

    void displayAll(CESDevice*);

private:
    Ui::Display *ui;

    void displayClock(CESDevice*);
    void displayCountDown(CESDevice*);  // this displays the timer counting down from time selected to 0
    void displayAttached(CESDevice*);
    void displayFreq(CESDevice*);       // this displays the frequency selected
    void displayTime(CESDevice*);       // this displays the time selected
    void displayWaveForm(CESDevice*);   // this displays the waveForm selected
    void displayPowerLevel(CESDevice*);
    void displayBattery(CESDevice*);



};

#endif // DISPLAY_H
