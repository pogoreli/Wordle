/********************************************************************************
** Form generated from reading UI file 'gameover.ui'
**
** Created by: Qt User Interface Compiler version 5.15.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_GAMEOVER_H
#define UI_GAMEOVER_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_GameOver
{
public:
    QWidget *widget;
    QVBoxLayout *verticalLayout;
    QLabel *label;
    QLabel *cv;
    QHBoxLayout *horizontalLayout;
    QPushButton *pushButton;
    QPushButton *pushButton_2;

    void setupUi(QDialog *GameOver)
    {
        if (GameOver->objectName().isEmpty())
            GameOver->setObjectName(QString::fromUtf8("GameOver"));
        GameOver->resize(290, 116);
        widget = new QWidget(GameOver);
        widget->setObjectName(QString::fromUtf8("widget"));
        widget->setGeometry(QRect(20, 10, 249, 93));
        verticalLayout = new QVBoxLayout(widget);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        label = new QLabel(widget);
        label->setObjectName(QString::fromUtf8("label"));
        label->setStyleSheet(QString::fromUtf8("font: 20pt \"Sans Serif\";"));

        verticalLayout->addWidget(label);

        cv = new QLabel(widget);
        cv->setObjectName(QString::fromUtf8("cv"));
        cv->setStyleSheet(QString::fromUtf8("font: 14pt \"Sans Serif\";"));

        verticalLayout->addWidget(cv);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        pushButton = new QPushButton(widget);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));

        horizontalLayout->addWidget(pushButton);

        pushButton_2 = new QPushButton(widget);
        pushButton_2->setObjectName(QString::fromUtf8("pushButton_2"));

        horizontalLayout->addWidget(pushButton_2);


        verticalLayout->addLayout(horizontalLayout);


        retranslateUi(GameOver);

        QMetaObject::connectSlotsByName(GameOver);
    } // setupUi

    void retranslateUi(QDialog *GameOver)
    {
        GameOver->setWindowTitle(QCoreApplication::translate("GameOver", "Dialog", nullptr));
        label->setText(QCoreApplication::translate("GameOver", "Game over!", nullptr));
        cv->setText(QCoreApplication::translate("GameOver", "The correct word is: apple", nullptr));
        pushButton->setText(QCoreApplication::translate("GameOver", "New game", nullptr));
        pushButton_2->setText(QCoreApplication::translate("GameOver", "Exit", nullptr));
    } // retranslateUi

};

namespace Ui {
    class GameOver: public Ui_GameOver {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_GAMEOVER_H
