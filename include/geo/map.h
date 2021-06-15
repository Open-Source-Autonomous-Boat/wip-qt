//#include <GL/gl.h>
#include <QObject>
#include <QOpenGLFunctions>
#include <QQuickItem>
#include <QQuickWindow>
#include <QSGGeometryNode>
#include <QtQml>
#if defined(__WIN32)
#include <windows.h>
#endif

#include "geo/render.h"

#pragma once

class MapDisplay : public QQuickItem {
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
