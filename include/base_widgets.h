#include <QWidget>
#include <QTabWidget>
#include <qobject.h>
#include <qtabwidget.h>
#include <qtmetamacros.h>
#pragma once

class WindowClass: public QWidget {
        Q_OBJECT;
protected:
        virtual void _SetupWin() {};
        virtual void _SetupWidgets() {};
};

/* Why can't QT let use use Q_OBJECT in template functions... */

class TabWindowClass: public QTabWidget {
        Q_OBJECT;
protected:
        virtual void _SetupWin() {};
        virtual void _SetupWidgets() {};
        
};

