// Copyright 2015 Klimov Viktor, https://github.com/Vitek1425/

#include "angulargauge.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    AngularGauge w;
    w.show();

    return a.exec();
}
