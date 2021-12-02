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
#include "electrodepads.h"
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

    CESDevice* getModel();

private:
    Ui::MainWindow *ui;

    //UI elements
    Display *display;
    ElectrodePads *electrodePads;

    //state of controller
    //Mode mode;            // need to define enum Mode first
    CESDevice *model;
    QTimer *timer;

    //functions
    void signalIdle();
    void updateDisplay();

private slots:      // slot functions need to be defined in cpp before they can be uncommented
    //bool slotSetTreatment(double, QString, int);




};
#endif // MAINWINDOW_H
