//#include <GL/gl.h>
#include <QQuickItem>
#include <QObject>
#include <QtQml>
#include <QSGGeometryNode>
#include <QOpenGLFunctions>
#include <QQuickWindow>
#if defined(__WIN32)
#include <windows.h>
#endif

#include "geo/render.h"

#pragma once


class MapDisplay: public QQuickItem {
  Q_OBJECT;
  QML_ELEMENT
  public:
  MapDisplay();
  ~MapDisplay();
public slots:
  void Sync();
  void Cleanup();
private slots:
  void HandleWindowChanged(QQuickWindow* win);
private:
  void releaseResources() override;
  MapDisplayRender* render;
};

