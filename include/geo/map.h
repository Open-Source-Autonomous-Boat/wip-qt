//#include <GL/gl.h>
#include <qopenglframebufferobject.h>
#include <qquickframebufferobject.h>
#include <QObject>
#include <QOpenGLFunctions>
#include <QOpenGLFramebufferObject>
#include <QOpenGLFramebufferObjectFormat>
#include <QQuickItem>
#include <QQuickWindow>
#include <QSGGeometryNode>
#include <QtQml>
#if defined(__WIN32)
#include <windows.h>
#endif

#include "geo/render.h"

#pragma once


class MapDisplay {};

class MapDisplayRender: public GeneralFBORender::Renderer {
public:
  MapDisplayRender();
  void render() override;
  QOpenGLFramebufferObject* createFramebufferObject(const QSize& size) override;
  MapDisplay map;
private:
  float color = 0.0;
};



