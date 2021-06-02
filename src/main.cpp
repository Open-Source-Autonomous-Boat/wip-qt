#include <QGuiApplication>

#include "main.h"
#include "widgets/initial.h"
#include "utils/apps.h"

int main(int argc, char *argv[]) {
        auto* app = app_utils::CreateApp(argc, argv);
        InitialWindow win;
        return app->exec();
}
