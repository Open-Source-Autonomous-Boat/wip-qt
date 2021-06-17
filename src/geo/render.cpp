#include "geo/render.h"

#include <GL/gl.h>
#include <qguiapplication.h>

#include <QOpenGLContext>  // Basically <gl/GL.h> but for QT
#include <QOpenGLShaderProgram>

#include "geo/map.h"

/*
 * I copied the whole thing from documentation <3
 */

QQuickFramebufferObject::Renderer* GeneralFBORender::GetRender() const {
  return new MapDisplayRender();
}
