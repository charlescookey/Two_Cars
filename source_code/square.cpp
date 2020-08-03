#include "square.h"

#include <QGraphicsScene>

Square::Square()
{
}

Square::Square(int x)
{
    //instaniate at the parametr x
    //as soon as its created the timer starts
    setRect(x,0,40,40);
    setBrush(QBrush(Qt::white,Qt::SolidPattern));
    setPen(QPen(QColor(28,36,43)));
    timer = new QTimer();
    connect(timer ,SIGNAL(timeout()),this,SLOT(move()));
    timer->start(50);
}

Square::~Square()
{
    delete timer;
}

void Square::move()
{
    QList<QGraphicsItem *>colliding_items = collidingItems();
        for(auto a : colliding_items){
            if(typeid(*(a)) == typeid(Car)){
                scene()->removeItem(this);
                delete this;

                EmmitterS::Instance()->ColidedWithSquare(1);
                //send signal to increase score
                return;
            }
        }

    //this is the slot the timer is conncted to so as sooon as its created it starts movung down
    setPos(x(),y()+20);//15 at first release
    //same idea with the circle , shuld increammntally increase sasb the game goes on gor longer lool

    if(y() >= scene()->height()){
        scene()->removeItem(this);
        delete this;//deleying this instance as soon as it leaves the scope of the scene manually to avid memory leaks
    }
}
