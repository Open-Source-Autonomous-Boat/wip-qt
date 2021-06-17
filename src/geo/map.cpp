#if defined(_WINDOWS)
#include <windows.h>
#endif
#include <GL/gl.h>
#include <qopenglcontext.h>
#include <qopenglframebufferobject.h>
#include <qopenglfunctions.h>

#include <QOpenGLFramebufferObjectFormat>
#include <QOpenGLFunctions>

#include "geo/map.h"
#include "geo/render.h"
#include "utils/cleaner.h"

MapDisplayRender::MapDisplayRender() = default;

void MapDisplayRender::render() {
  QOpenGLFunctions* func = QOpenGLContext::currentContext()->functions();
  func->glClearColor(((int)this->color++ % 255) / 255, 0, 0, 1);
  func->glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT | GL_STENCIL_BUFFER_BIT);
  this->update();
}

QOpenGLFramebufferObject* MapDisplayRender::createFramebufferObject(const QSize& size) {
  QOpenGLFramebufferObjectFormat format;
  format.setAttachment(QOpenGLFramebufferObject::CombinedDepthStencil);
  format.setSamples(4);
  return new QOpenGLFramebufferObject(size, format);
}
