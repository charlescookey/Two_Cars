#ifndef MYSCENE_H
#define MYSCENE_H

#include <QGraphicsScene>

#include "car.h"
#include <QPainter>
#include <QPixmap>

class MyScene :public QGraphicsScene
{
public:
    MyScene();
protected:
    void keyPressEvent(QKeyEvent *event) override;
private:
    Car *lcar = new Car(20,530,":/images/lcar.png");
    Car *rcar = new Car(220,530,":/images/rcar.png");
    QPainter *painter = nullptr;
    QPixmap *picture = nullptr;

    //remeber to delete all the timer objects as that in fact is a memory leak lool

};

#endif // MYSCENE_H
