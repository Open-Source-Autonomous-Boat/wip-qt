#include "geo/render.h"

#include <QOpenGLContext>  // Basically <gl/GL.h> but for QT
#include <QOpenGLShaderProgram>

/*
 * I copied the whole thing from documentation <3
 */

MapDisplayRender::MapDisplayRender(){};

void MapDisplayRender::SetViewPortSize(const QSize& size) {
  this->view_port_size = size;
}

void MapDisplayRender::SetWindow(QQuickWindow* win) { this->window = win; }

void MapDisplayRender::Init() {
  if (!this->shader) {
    QSGRendererInterface* ren_int = this->window->rendererInterface();
    Q_ASSERT(ren_int->graphicsApi() == QSGRendererInterface::OpenGL ||
             ren_int->graphicsApi() == QSGRendererInterface::OpenGLRhi);
    initializeOpenGLFunctions();
    this->shader = new QOpenGLShaderProgram();
  }
}

void MapDisplayRender::Paint() {
  this->window->beginExternalCommands();
  this->shader->bind();
  this->shader->enableAttributeArray(0);
  glBindBuffer(GL_ARRAY_BUFFER, 0);
  glViewport(0, 0, this->view_port_size.width(), this->view_port_size.height());
  this->shader->disableAttributeArray(0);
  this->shader->release();
  this->window->endExternalCommands();
}

MapDisplayRender::~MapDisplayRender() = default;
