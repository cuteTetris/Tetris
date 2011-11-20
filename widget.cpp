#include "widget.h"

#include "QLabel"
#include "QHBoxLayout"
#include "QVBoxLayout"
#include "QLCDNumber"
#include "QMenuBar"
#include "QMenu"
#include "QAction"
#include "QWidget"
#include "QTimer"


Widget::Widget(QWidget *parent)
    : QMainWindow(parent), mcentralWidget(new QWidget(parent)), mcontroller(new Controller(parent))
{

   QMenuBar* myMenuBar = this->menuBar();

   //DateiMenü
   QMenu* dataMenu = new QMenu("Datei",this);
   QAction* newGame = new QAction("Neu",this);
   QAction* closeGame = new QAction("Beenden", this);

   dataMenu->addAction(newGame);
   dataMenu->addAction(closeGame);
   myMenuBar->addMenu(dataMenu);

   QGridLayout* gridLayout = new QGridLayout(this);
   gridLayout->setVerticalSpacing(50);
   //gridLayout->setHorizontalSpacing(200);

   mField = new QLabel(this);
   mField->setText("Feld");
   gridLayout->addWidget(mField,0,0,4,1,0);

   QLabel *nextStoneLabel = new QLabel(this);
   nextStoneLabel->setText("naechster Stein");
   mNextStoneField = new QLabel(this);
   gridLayout->addWidget(nextStoneLabel,0,1);

   gridLayout->addWidget(mNextStoneField,1,1);

   QLabel *scoreLabel = new QLabel(this);
   scoreLabel->setText("Naechster Stein");
   mScore = new QLCDNumber(5,this);

   gridLayout->addWidget(scoreLabel,2,1);
   gridLayout->addWidget(mScore,3,1);

   //mField->setPixmap(mcontroller->init());
   mcentralWidget->setLayout(gridLayout);

   this->setCentralWidget(mcentralWidget);

   QTimer *timer = new QTimer(this);
   connect(timer, SIGNAL(timeout()), this, SLOT(draw()));
   timer->start(1000);

}

void Widget::draw(){
    mField->setPixmap(mcontroller->draw());
    this->repaint();
}

Widget::~Widget()
{

}
