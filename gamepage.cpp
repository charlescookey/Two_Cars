#include "gamepage.h"
#include "ui_gamepage.h"

#include <QtDebug>

GamePage::GamePage(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::GamePage)
{
    ui->setupUi(this);

    ui->graphicsView->setScene(ss);
    ui->graphicsView->setFixedSize(400,650);//setting the graphics view to avoid sscaling
    ss->setSceneRect(0,0,400,650);//also setting the scene rect to avoid scaling
    ss->addItem(sb);

    connect(EmmitterC::Instance(),SIGNAL(CollidedWithCircle()),this,SLOT(IncreaseScore()));
    connect(EmmitterC::Instance(),SIGNAL(ReachedTheEnd()),this,SLOT(EndGame()));
    connect(EmmitterS::Instance(),SIGNAL(ColidedWithSquare()),this,SLOT(EndGame()));


    connect(timer , SIGNAL(timeout()),this,SLOT(spawnCirclesandSquares()));
    timer->start(1000);
}

GamePage::~GamePage()
{
    delete ui;
}

void GamePage::spawnCirclesandSquares()
{
    circleOrSquare = QRandomGenerator::global()->bounded(4);
    whichPosition = QRandomGenerator::global()->bounded(4);

    ///addd a case ehere the both sides get n ietm at the sam time lool

    if(circleOrSquare == 1){
        Circle *cc = new Circle(topPositions[whichPosition]);
        ss->addItem(cc);
    }else if(circleOrSquare == 2){
        Square *dd = new Square(topPositions[whichPosition]);
        ss->addItem(dd);
    }else{
        int inside = QRandomGenerator::global()->bounded(2);
        int side = QRandomGenerator::global()->bounded(2);
        if(inside ==0){
            Circle *cc = new Circle(topPositions[side]);
            ss->addItem(cc);
        }else{
            Square *dd = new Square(topPositions[side]);
            ss->addItem(dd);
        };
        inside = QRandomGenerator::global()->bounded(2);
        side = QRandomGenerator::global()->bounded(2);
        if(inside ==0){
            Circle *cc = new Circle(topPositions[side +2]);
            ss->addItem(cc);
        }else{
            Square *dd = new Square(topPositions[side +2]);
            ss->addItem(dd);
        };
    }
}

void GamePage::EndGame()
{
    closed();
}

void GamePage::IncreaseScore()
{
    sb->increaseScore();
}
