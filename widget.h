#ifndef WIDGET_H
#define WIDGET_H

#include <QtGui/QMainWindow>
#include "controller.h"


class QLabel;
class QLCDNumber;
class QWidget;
class QTimer;

class Widget : public QMainWindow
{
    Q_OBJECT

public:
    Widget(QWidget *parent = 0);
    ~Widget();

private:
    QLabel* mField;
    QLabel* mNextStoneField;
    QLCDNumber* mScore;
    QWidget* mcentralWidget;
    //QTimer* timer;
    Controller* mcontroller;

private Q_SLOTS:
   void draw(void);

};

#endif // WIDGET_H
