#include "landingpage.h"
#include "ui_landingpage.h"
#include <QPalette>
#include <QtDebug>

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
    delete ui;
}

void LandingPage::GamePageEnded()
{
      qDebug()<<"i recieved the signal that the game has ended";
}

void LandingPage::on_pushButton_clicked()
{
//    this->setEnabled(false);

//    if(!gg)
//        gg = new GamePage(this);
//    gg->show();
//    gg->raise();
//    gg->isActiveWindow();

    return;
}
