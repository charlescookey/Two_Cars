#include "landingpage.h"
#include "ui_landingpage.h"
#include <QPalette>
#include <QMessageBox>
#include <QSettings>

#include <QMediaPlaylist>

LandingPage::LandingPage(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::LandingPage)
{
    ui->setupUi(this);

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


    connect(&gg,SIGNAL(gameEnded()),this,SLOT(ReWriteHighScore()));

    QSettings settings("Halo-Tech","Two-Cars");//company name and app name to save the setting(highscore in this context)
    settings.beginGroup("ScoreSystem");
    QString a = settings.value("highscore",QString::number(0)).toString();
    settings.endGroup();

    highscore = a.toInt();

    ui->label_2->setText(QString("Highscore: "+QString::number(highscore)));
    ui->label_2->setStyleSheet("#label_2{color : white;font: 12px;}");
    //starts here


    QMediaPlaylist *playlist = new QMediaPlaylist();
    playlist->addMedia(QUrl("qrc:/songs_and_effects/500_Miles.mp3"));
    playlist->setPlaybackMode(QMediaPlaylist::Loop);

    music = new QMediaPlayer();
    music->setPlaylist(playlist);
    music->play();

    ui->radioButton->setChecked(true);
    ui->radioButton->setStyleSheet("#radioButton{color : white;font: bold 14px;}");
    musicState = false;
}

LandingPage::~LandingPage()
{
    QSettings settings("Halo-Tech","Two-Cars");//company name and app name to save the setting(highscore in this context)
    settings.beginGroup("ScoreSystem");
    //settings.setValue("highscore",QString::number(highscore));
    settings.setValue("highscore",QString::number(0));
    settings.endGroup();
    delete music;
    delete painter;
    delete picture;
    delete ui;
}

void LandingPage::on_pushButton_clicked()
{
    gg.show();
    gg.start(musicState);

    hide();
    music->stop();

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
                      "\nThe songs and effects were donlaoded from the following sites"
                      "\n->freesoundeffects.com"
                      "\n->cutepup.club"
                      "\n->noisesforfun.com"
                      "\nThe song choice was inspired by Marshall Eriksen's fiero"
                      "\n\nThank you for playing my game.");
    QMessageBox::information(this,"ABOUT THIS GAME!",message);
}

void LandingPage::ReWriteHighScore()
{
    show();
    if(!musicState)
        music->play();

    if(gg.getCurrentscore()>highscore){
        highscore = gg.getCurrentscore();
        ui->label_2->setText(QString("Highscore: "+QString::number(highscore)));
    }
}

void LandingPage::on_radioButton_clicked()
{
    if(musicState){
        musicState = false;
        music->play();
    }else{
        musicState = true;
        music->stop();
    }

}
