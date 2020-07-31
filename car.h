#ifndef CAR_H
#define CAR_H


#include <QGraphicsPixmapItem>
#include <QBrush>
#include <QGraphicsScene>


class Car:public QGraphicsPixmapItem
{
public:
    Car(int ,int,QString);
    void move();
private:
    bool position;
};

#endif // CAR_H
