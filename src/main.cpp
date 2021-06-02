#include <QGuiApplication>
#include <QQmlApplicationEngine>

#include "main.h"
#include "initial.h"
#include "utils/apps.h"

int main(int argc, char *argv[]) {
        InitialWindow win(argc, argv);
        return win.exec();
}
