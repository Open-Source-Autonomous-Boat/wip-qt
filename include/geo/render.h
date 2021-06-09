//#include <GL/gl.h>
#include <QQuickItem>
#include <QObject>
#include <QtQml>
#include <QSGGeometryNode>
#include <QOpenGLFunctions>
#include <QQuickWindow>
#include <QOpenGLShaderProgram>
#if defined(_WINDOWS)
#include <windows.h>
#endif

#pragma once

//class MapDisplayRender : public QQuickItem, protected QOpenGLFunctions {
//  Q_OBJECT;

// public:
//  MapDisplayRender();
//  ~MapDisplayRender();
//  void SetViewPortSize(const QSize& size);
//  void SetWindow(QQuickWindow* win);
// public slots:
//  void Init();
//  void Paint();

// private:
//  QSize view_port_size;
//  QOpenGLShaderProgram* shader;
//  QQuickWindow* window;
//};
