#include "myscene.h"
#include <QKeyEvent>


MyScene::MyScene()
{
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

    addPixmap(*picture);
    addItem(lcar);
    addItem(rcar);
    //adding both cars to the scenne
}

void MyScene::keyPressEvent(QKeyEvent *event)
{
    //left button to control left car and riht button to control right car
    if(event->key()  == Qt::Key_Left)
        lcar->move();
    if(event->key() == Qt::Key_Right)
        rcar->move();

}

