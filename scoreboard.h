#ifndef SCOREBOARD_H
#define SCOREBOARD_H

#include <QGraphicsTextItem>
class ScoreBoard :public QGraphicsTextItem
{
public:
    ScoreBoard(QGraphicsItem *parent = 0);
    void increaseScore();
    int getScore();
    void resetScore();
private:
    int score;
};

#endif // SCOREBOARD_H
