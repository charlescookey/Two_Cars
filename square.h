#ifndef SQUARE_H
#define SQUARE_H

#include <QGraphicsRectItem>
#include <QObject>
#include <QTimer>


#include "car.h"
#include "Singleton.h"

class Square :public QObject ,public QGraphicsRectItem
{
    Q_OBJECT
public:
    Square();
    Square(int);
    ~Square();
signals:
    void ColidedWithSquare(int);
private:
    QTimer *timer;
private slots:
    void move();
};
typedef Singleton<Square> EmmitterS;

#endif // SQUARE_H
