#ifndef LANDINGPAGE_H
#define LANDINGPAGE_H

#include <QMainWindow>
#include <QPainter>
#include <QBrush>
#include <QFile>

#include <QMediaPlayer>

#include "gamepage.h"

namespace Ui {
class LandingPage;
}

class LandingPage : public QMainWindow
{
    Q_OBJECT

public:
    explicit LandingPage(QWidget *parent = nullptr);
    ~LandingPage();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();

    void ReWriteHighScore();

    void on_radioButton_clicked();

private:
    Ui::LandingPage *ui;
    QPixmap *picture = nullptr;
    QPainter *painter = nullptr;
    QMediaPlayer *music = nullptr;

    GamePage gg;

    QString message;

    int highscore;

    bool musicState;
};

#endif // LANDINGPAGE_H
