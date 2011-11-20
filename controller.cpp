#include "controller.h"
#include "stone.h"

#include "QPixmap"
#include "QPainter"

int Controller::counter=0;

Controller::Controller(QWidget *parent) :
        QWidget(parent),mcurrentStone(new line())
{
    //Initialisieren des Arrays
    for(uint i=0;i<=mheigth;i++){
        for(uint j=0;j<=mwidth;j++){
              mfield[i][j]=0;
        }
    }
}

QPixmap Controller::init(void){
    QPixmap pixMap(mwidth*mraseterSize,mheigth*mraseterSize);

    QPainter painter(&pixMap);
    painter.setBrush(QBrush(Qt::gray));

    for(uint i=0;i<=mheigth;i++){
        for(uint j=0;j<=mwidth;j++){
            painter.drawRect(j*mraseterSize, i*mraseterSize, mraseterSize, mraseterSize);
        }
    }

    return pixMap;
}

void Controller::setStone(Stone* stone){

    for(int i=0;i<4;i++){
        for(int j=0;j<4;j++){
            if(stone->mStone[i][j]==1){
                mfield[i][j] = 0;
            }
        }
    }
}


QPixmap Controller::draw(void)
{
    //setStone(mcurrentStone);
    /*
    counter+=1;

    mfield[counter-1][3] = 0;
    mfield[counter-1][4] = 0;
    mfield[counter-1][5] = 0;

    if(counter>20){
        counter=0;
    }

    mfield[counter][3] = 1;
    mfield[counter][4] = 1;
    mfield[counter][5] = 1;
    */

    QPixmap pixMap =  init();
    QPainter painter(&pixMap);
    painter.setBrush(QBrush(Qt::blue));

    for(uint i=0;i<=mheigth;i++){
        for(uint j=0;j<=mwidth;j++){
            if(mfield[i][j]==1)
            {
                painter.drawRect(j*mraseterSize, i*mraseterSize, mraseterSize, mraseterSize);
            }

        }
    }

    return pixMap;

}
