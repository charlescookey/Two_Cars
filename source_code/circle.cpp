#include "circle.h"

#include <QGraphicsScene>

Circle::Circle()
{
    //left balbk but not deleted so the singleton clas can use it
}

Circle::Circle(int x)
{
    //constructor to instantiate the circles at the parameters x and  starts its timer
    setRect(x,0,40,40);
    setBrush(QBrush(Qt::white,Qt::SolidPattern));
    setPen(QPen(QColor(28,36,43)));

    timer = new QTimer;
    connect(timer, SIGNAL(timeout()),this ,SLOT(move()));
    timer->start(50);
}

Circle::~Circle()
{
    delete timer;
}

void Circle::move()
{
    QList<QGraphicsItem *>colliding_items = collidingItems();
        for(auto a : colliding_items){
            if(typeid(*(a)) == typeid(Car)){
                scene()->removeItem(this);
                delete this;

                EmmitterC::Instance()->CollidedWithCircle();
                return;
            }
        }

    //to make the circle continue moving down as soon as its created
    setPos(x(),y()+20);//15 at first release
    //this 10 is what should increase ast the gae gets longer so the iteams falls faster creting the illusion of increase speed.
    //and probalbly the rate of items looool.

    if(y() >= scene()->height()){
        scene()->removeItem(this);
        delete this;//to delete to avoid memory leaks

        EmmitterC::Instance()->ReachedTheEnd(2);
    }
}

