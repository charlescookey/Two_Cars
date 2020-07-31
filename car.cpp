#include "car.h"

#include <QtDebug>
#include <QPixmap>


Car::Car(int x, int y,QString z)
{
    //constructor that takes an argument to instantiate the car with a position
    setPixmap(QPixmap(z));
    setPos(x , y);
}

void Car::move()
{
    //toggles the postion state left and right and moves the car left or right
    if(position == false){
        setPos(x()+100 , y());
        position = true;

    }else{
        setPos(x()-100 , y());
        position = false;
    }

}
