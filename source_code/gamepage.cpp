#include "gamepage.h"
#include "ui_gamepage.h"
#include <QMessageBox>

#include <QMediaPlaylist>

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
    connect(EmmitterC::Instance(),SIGNAL(ReachedTheEnd(int)),this,SLOT(EndGame(int)));
    connect(EmmitterS::Instance(),SIGNAL(ColidedWithSquare(int)),this,SLOT(EndGame(int)));


    connect(timer , SIGNAL(timeout()),this,SLOT(spawnCirclesandSquares()));

    playlist = new QMediaPlaylist();
    playlist->addMedia(QUrl("qrc:/songs_and_effects/car_start.mp3"));
    playlist->addMedia(QUrl("qrc:/songs_and_effects/SHA.mp3"));
    playlist->setPlaybackMode(QMediaPlaylist::Loop);

    music = new QMediaPlayer();



}

GamePage::~GamePage()
{
    delete ss;
    delete playlist;
    delete music;
    //delete sb; //this is acc taken care of as sb(scoreboard) was passed into ss(the graphics scene)
    delete timer;
    delete ui;
}

void GamePage::start(bool m)
{
    musicState = m;
    if(!musicState){
        music->setPlaylist(playlist);
        music->play();
    }
    timer->start(900);
    sb->resetScore();
    gameAlreadyEnded =  false;
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

void GamePage::EndGame(int a)
{
    if(gameAlreadyEnded)//this is incase the car still collides or circle reaches the end afeter the game has ended;
        return;
    if(!musicState){
        music->stop();
        music->setMedia(QUrl("qrc:/songs_and_effects/car_hit.wav"));
        music->play();
    }
    current_score = sb->getScore();
    gameAlreadyEnded = true;
    timer->stop();
    QString message{};

    if(a == 1){
        message = "You hit a Square";
    }else{
        message = "You missed a Circle";
    }

    QMessageBox box(QMessageBox::Critical,"GAME OVER!",message,QMessageBox::Ok);
            if(box.exec() == QMessageBox::Ok){
                gameEnded();
                music->stop();
                close();

            }
}

void GamePage::IncreaseScore()
{
    if(!gameAlreadyEnded)
        sb->increaseScore();
}
