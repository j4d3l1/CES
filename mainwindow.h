#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QWidget>
#include <QPushButton>
#include <QObject>
#include <QLayout>
#include <QDebug>
#include <QVector>
#include <QThread>
#include <QTimer>
#include <QRandomGenerator>

#include "display.h"
#include "cesdevice.h"


QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE
//hi
class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();



private:
    Ui::MainWindow *ui;

    //UI elements
    Display *display;

    //state of controller
    //Mode mode;            // need to define enum Mode first
    CESDevice *model;
    QTimer *displayTimer;

    //functions
    void signalIdle();
    void updateDisplay();

private slots:      // slot functions need to be defined in cpp before they can be uncommented

    void displayTimerSlot();

    void slotAttachToggle();

    void slotTime20();
    void slotTime40();
    void slotTime60();

    void slotAlpha();
    void slotBeta();
    void slotGamma();

    void slotFreq5();
    void slotFreq77();
    void slotFreq100();

    void slotTreatment();




};
#endif // MAINWINDOW_H
