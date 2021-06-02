#include <QGuiApplication>
#include <QQmlApplicationEngine>

#include "main.h"
#include "initial.h"
#include "utils/apps.h"

int main(int argc, char *argv[]) {
        auto* app = app_utils::CreateApp(argc, argv);
        InitialWindow win;
        return app->exec();
}
