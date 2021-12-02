#ifndef ELECTRODEPADS_H
#define ELECTRODEPADS_H

#include <QWidget>
#include <QMainWindow>
#include <QPushButton>
#include <QObject>
#include <QLayout>
#include <QDebug>
#include <QVector>
#include <QThread>
#include <QTimer>
#include <QRandomGenerator>

namespace Ui {
class ElectrodePads;
}

class ElectrodePads : public QWidget
{
    Q_OBJECT

public:
    explicit ElectrodePads(QWidget *parent = nullptr);
    ~ElectrodePads();

    void signalOff();

private:
    Ui::ElectrodePads *ui;

    bool attached;
    QTimer *timer;

private slots:      // slots need to be defined in cpp before can uncomment
    void slotAttach();
    void slotDetach();


};

#endif // ELECTRODEPADS_H
