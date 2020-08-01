#include "landingpage.h"
#include "ui_landingpage.h"
#include <QPalette>
#include <QtDebug>
#include <QMessageBox>

//
//
//do clean up
//remove all the qt debig stuff we used.
//
//figure out how you will run the sublission
//
//abeg no too waste time
//
//you're well, god Charles
//
LandingPage::LandingPage(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::LandingPage)
{
    ui->setupUi(this);
    //ui->centralwidget->setStyle();

    picture = new QPixmap(400,650);
    painter = new QPainter(picture);

    painter->fillRect(0,0,400,650,QColor(28,36,43));
    painter->fillRect(195,0,10,650,Qt::white);
    int interval =0;
    for(int i = 0;i<11;i++){
        painter->fillRect(98,interval,4,40,Qt::white);
        painter->fillRect(298,interval,4,40,Qt::white);
        interval+=60;
    }
    painter->fillRect(90,40,300,80,QColor(28,36,43));

    QPalette palette;
    palette.setBrush((this)->backgroundRole() , QBrush(*picture));
    (this)->setPalette(palette);


}

LandingPage::~LandingPage()
{
    delete painter;
    delete picture;
    delete ui;
}

void LandingPage::GamePageEnded()
{
      qDebug()<<"i recieved the signal that the game has ended";
}

void LandingPage::on_pushButton_clicked()
{
    gg.show();
    gg.start();

    return;
}

void LandingPage::on_pushButton_2_clicked()
{
    message = QString("This game has two cars that move between two lanes\n"
                     "You would use the left and the right arrow keys to control the cars\n"
                      "The left arrow key controls the left car while the right arrow key controls the right car, "
                      "\nThe aim of the game is to avoid the sqaures and not miss the circles, "
                      "\nIf you miss a single circle or if any car collides with a sqaure, that's game over"
                      "\nSurvive for as long as you can!");
    QMessageBox::information(this,"HOW TO PLAY!",message);
}

void LandingPage::on_pushButton_3_clicked()
{
    message = QString("This game is based off the game \"2 cars\" developed by \"Ketchapp\""
                      "\nI decided to recreate the game as my Udaciy C++ Nanodegree Capstone Project"
                      "\nThe original game by Ketchapp is no longer on play store though, "
                      "\nI used Qt entirely to re-create this game"
                      "\nIf you want to reach me, below are my details"
                      "\nName\t\tCharles Iroegbu"
                      "\nemail\t\tcharlesiroegbu99@gmail.com"
                      "\nDepending on when you see the game i intend on adding sound effects and some themes"
                      "\n\nThank you for playing my game.");
    QMessageBox::information(this,"ABOUT THIS GAME!",message);
}
