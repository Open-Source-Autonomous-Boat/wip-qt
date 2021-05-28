#include <QWidget>
#include <QTabWidget>
#include <qobject.h>
#include <qtabwidget.h>
#include <qtmetamacros.h>
#pragma once

class WindowClass: public QWidget {
        Q_OBJECT;
public:
        WindowClass(QWidget *parent = nullptr) {
        };
protected:
        virtual void _setupWin() {};
        virtual void _setupWidgets() {};
};

class TabWindowClass: public QTabWidget {
        Q_OBJECT;
public:
        TabWindowClass(QTabWidget *parent = nullptr) {};
protected:
        virtual void _setupWin() {};
        virtual void _setupWidgets() {};
        
};

