//#include <GL/gl.h>
#include <qqml.h>
#include <qquickframebufferobject.h>
#include <qtmetamacros.h>
#include <QObject>
#include <QOpenGLFunctions>
#include <QOpenGLShaderProgram>
#include <QQuickItem>
#include <QQuickWindow>
#include <QSGGeometryNode>
#include <QQuickFramebufferObject>
#include <QtQml>
#if defined(_WINDOWS)
#include <windows.h>
#endif

#pragma once

class GeneralFBORender: public QQuickFramebufferObject {
  Q_OBJECT;
  QML_NAMED_ELEMENT(Renderer);
public:
  Renderer* GetRender() const;
};

