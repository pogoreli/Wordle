#include "wordlegui.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    WordleGUI w;
    w.show();
    return a.exec();
}
