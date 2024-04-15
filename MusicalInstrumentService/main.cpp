#include <QApplication>
#include "Headers/Application/Application.h"

int main(int argc, char *argv[]) {
    QApplication a(argc, argv);


    Application app;

    return a.exec();
}
