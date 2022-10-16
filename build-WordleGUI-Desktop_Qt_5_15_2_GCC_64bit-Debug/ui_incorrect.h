/********************************************************************************
** Form generated from reading UI file 'incorrect.ui'
**
** Created by: Qt User Interface Compiler version 5.15.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_INCORRECT_H
#define UI_INCORRECT_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Incorrect
{
public:
    QWidget *widget;
    QVBoxLayout *verticalLayout;
    QLabel *label;
    QPushButton *pushButton;

    void setupUi(QDialog *Incorrect)
    {
        if (Incorrect->objectName().isEmpty())
            Incorrect->setObjectName(QString::fromUtf8("Incorrect"));
        Incorrect->resize(381, 90);
        widget = new QWidget(Incorrect);
        widget->setObjectName(QString::fromUtf8("widget"));
        widget->setGeometry(QRect(10, 10, 359, 62));
        verticalLayout = new QVBoxLayout(widget);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        label = new QLabel(widget);
        label->setObjectName(QString::fromUtf8("label"));
        label->setStyleSheet(QString::fromUtf8("font: 20pt \"Sans Serif\";"));

        verticalLayout->addWidget(label);

        pushButton = new QPushButton(widget);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));

        verticalLayout->addWidget(pushButton);


        retranslateUi(Incorrect);

        QMetaObject::connectSlotsByName(Incorrect);
    } // setupUi

    void retranslateUi(QDialog *Incorrect)
    {
        Incorrect->setWindowTitle(QCoreApplication::translate("Incorrect", "Dialog", nullptr));
        label->setText(QCoreApplication::translate("Incorrect", "This word is not on the list", nullptr));
        pushButton->setText(QCoreApplication::translate("Incorrect", "OK", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Incorrect: public Ui_Incorrect {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_INCORRECT_H
