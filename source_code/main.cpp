#include "landingpage.h"
#include "gamepage.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    LandingPage p;
    p.show();

//    GamePage hh;
//    hh.show();

    return a.exec();
}
