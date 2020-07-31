#include "scoreboard.h"
#include <QFont>

ScoreBoard::ScoreBoard(QGraphicsItem *parent):QGraphicsTextItem(parent),score(0)
{
    setDefaultTextColor(Qt::red);//later change itto white
    setPlainText(QString::number(score));
    setFont(QFont("times",25));
    setPos(350,20);
}

void ScoreBoard::increaseScore()
{
    score++;
    setPlainText(QString::number(score));
}

int ScoreBoard::getScore()
{
    return score;
}
