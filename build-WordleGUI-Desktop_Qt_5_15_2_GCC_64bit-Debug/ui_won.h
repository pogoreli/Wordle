/********************************************************************************
** Form generated from reading UI file 'won.ui'
**
** Created by: Qt User Interface Compiler version 5.15.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_WON_H
#define UI_WON_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Won
{
public:
    QWidget *widget;
    QVBoxLayout *verticalLayout;
    QLabel *label;
    QHBoxLayout *horizontalLayout;
    QPushButton *pushButton;
    QPushButton *pushButton_2;

    void setupUi(QDialog *Won)
    {
        if (Won->objectName().isEmpty())
            Won->setObjectName(QString::fromUtf8("Won"));
        Won->resize(295, 85);
        widget = new QWidget(Won);
        widget->setObjectName(QString::fromUtf8("widget"));
        widget->setGeometry(QRect(10, 10, 269, 64));
        verticalLayout = new QVBoxLayout(widget);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        label = new QLabel(widget);
        label->setObjectName(QString::fromUtf8("label"));
        label->setStyleSheet(QString::fromUtf8("font: 20pt \"Sans Serif\";"));

        verticalLayout->addWidget(label);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        pushButton = new QPushButton(widget);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));

        horizontalLayout->addWidget(pushButton);

        pushButton_2 = new QPushButton(widget);
        pushButton_2->setObjectName(QString::fromUtf8("pushButton_2"));

        horizontalLayout->addWidget(pushButton_2);


        verticalLayout->addLayout(horizontalLayout);


        retranslateUi(Won);

        QMetaObject::connectSlotsByName(Won);
    } // setupUi

    void retranslateUi(QDialog *Won)
    {
        Won->setWindowTitle(QCoreApplication::translate("Won", "Dialog", nullptr));
        label->setText(QCoreApplication::translate("Won", "You won this round!", nullptr));
        pushButton->setText(QCoreApplication::translate("Won", "New game", nullptr));
        pushButton_2->setText(QCoreApplication::translate("Won", "Exit", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Won: public Ui_Won {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WON_H
