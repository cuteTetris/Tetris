#ifndef CONTROLLER_H
#define CONTROLLER_H

#include <QWidget>

#include "line.h"

class QPixmap;

class Controller : public QWidget
{
    Q_OBJECT
public:
    explicit Controller(QWidget *parent = 0);
    QPixmap draw(void);
    QPixmap init(void);
    void setStone(Stone* stone);

signals:

public slots:


private:
    static const uint mraseterSize=20;
    static const uint mwidth=10;
    static const uint mheigth=20;
    uint mfield[mheigth][mwidth];
    static int counter;
    Stone *mcurrentStone;

};

#endif // CONTROLLER_H
