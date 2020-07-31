#ifndef GAMEPAGE_H
#define GAMEPAGE_H

#include <QWidget>
#include <QRandomGenerator>
#include <QTimer>
#include "myscene.h"

#include "circle.h"
#include "square.h"
#include "scoreboard.h"
namespace Ui {
class GamePage;
}

class GamePage : public QWidget
{
    Q_OBJECT

public:
    explicit GamePage(QWidget *parent = nullptr);
    ~GamePage();

signals:
    void closed();

private:
    Ui::GamePage *ui;
    MyScene *ss = new MyScene();
    ScoreBoard *sb = new ScoreBoard();
    QTimer *timer = new QTimer();

    int topPositions[4] = {30,130,230,330};
    int circleOrSquare;
    int whichPosition;

private slots:
    void spawnCirclesandSquares();
    void EndGame();
    void IncreaseScore();
};

#endif // GAMEPAGE_H
