#ifndef GAMEPAGE_H
#define GAMEPAGE_H

#include <QWidget>
#include <QRandomGenerator>
#include <QTimer>

#include <QMediaPlayer>
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
    void start(bool);
    int getCurrentscore(){return current_score;}

signals:
    void gameEnded();

private:
    Ui::GamePage *ui;

    //dont worry there's a corresponding call to delete for all these "new" to aoid a memory leak

    MyScene *ss = new MyScene();
    ScoreBoard *sb = new ScoreBoard();
    QTimer *timer = new QTimer();

    QMediaPlayer *music = nullptr;
    QMediaPlaylist *playlist = nullptr;

    int topPositions[4] = {30,130,230,330};
    int circleOrSquare;
    int whichPosition;

    bool gameAlreadyEnded{false};
    int current_score{0};
    bool musicState;

private slots:
    void spawnCirclesandSquares();
    void EndGame(int);
    void IncreaseScore();
};

#endif // GAMEPAGE_H
