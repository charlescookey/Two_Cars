/********************************************************************************
** Form generated from reading UI file 'gamepage.ui'
**
** Created by: Qt User Interface Compiler version 5.13.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_GAMEPAGE_H
#define UI_GAMEPAGE_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGraphicsView>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_GamePage
{
public:
    QHBoxLayout *horizontalLayout;
    QGraphicsView *graphicsView;

    void setupUi(QWidget *GamePage)
    {
        if (GamePage->objectName().isEmpty())
            GamePage->setObjectName(QString::fromUtf8("GamePage"));
        GamePage->resize(410, 610);
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(GamePage->sizePolicy().hasHeightForWidth());
        GamePage->setSizePolicy(sizePolicy);
        horizontalLayout = new QHBoxLayout(GamePage);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        graphicsView = new QGraphicsView(GamePage);
        graphicsView->setObjectName(QString::fromUtf8("graphicsView"));
        graphicsView->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        graphicsView->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);

        horizontalLayout->addWidget(graphicsView);


        retranslateUi(GamePage);

        QMetaObject::connectSlotsByName(GamePage);
    } // setupUi

    void retranslateUi(QWidget *GamePage)
    {
        GamePage->setWindowTitle(QCoreApplication::translate("GamePage", "Form", nullptr));
    } // retranslateUi

};

namespace Ui {
    class GamePage: public Ui_GamePage {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_GAMEPAGE_H
