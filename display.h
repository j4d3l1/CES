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

    void displayAll(CESDevice);

private:
    Ui::Display *ui;

    void displayTreatment(CESDevice);
    void displayTime(CESDevice);
    void displayPowerLevel(CESDevice);
    void displayBattery(CESDevice);
    void displayAttached(CESDevice);

};

#endif // DISPLAY_H
