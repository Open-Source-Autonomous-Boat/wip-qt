#include "geo/render.h"
#include <GL/gl.h>
#include <qguiapplication.h>

#include <QOpenGLContext>  // Basically <gl/GL.h> but for QT
#include <QOpenGLShaderProgram>

/*
 * I copied the whole thing from documentation <3
 */

MapDisplayRender::MapDisplayRender(): shader(nullptr) {
};

void MapDisplayRender::SetViewPortSize(const QSize& size) {
  this->view_port_size = size;
}

void MapDisplayRender::SetWindow(QQuickWindow* win) { this->window = win; }

void MapDisplayRender::Init() {
  if (!this->shader) { // This does not seem to be called
    QSGRendererInterface* ren_int = this->window->rendererInterface();
    Q_ASSERT(ren_int->graphicsApi() == QSGRendererInterface::OpenGL ||
             ren_int->graphicsApi() == QSGRendererInterface::OpenGLRhi);
    initializeOpenGLFunctions();
    this->shader = new QOpenGLShaderProgram();
    this->shader->addCacheableShaderFromSourceCode(
        QOpenGLShader::Vertex,
        "attribute highp vec4 vertices;"
        "varying highp vec2 coords;"
        "void main() {"
        "    gl_Position = vertices;"
        "    coords = vertices.xy;"
        "}");
    this->shader->addCacheableShaderFromSourceCode(
        QOpenGLShader::Fragment,
        "uniform lowp float t;"
        "varying highp vec2 coords;"
        "void main() {"
        "    lowp float i = 1. - (pow(abs(coords.x), 4.) + pow(abs(coords.y), "
        "4.));"
        "    i = smoothstep(t - 0.8, t + 0.8, i);"
        "    i = floor(i * 20.) / 20.;"
        "    gl_FragColor = vec4(coords * .5 + .5, i, i);"
        "}");

    this->shader->bindAttributeLocation("vertices", 0);
    this->shader->link();
  }
}

void MapDisplayRender::Paint() {
  this->window->beginExternalCommands();
  this->shader->bind();
  this->shader->enableAttributeArray(0);
  float values[] = {-1, -1, 1, -1, -1, 1, 1, 1};
  glBindBuffer(GL_ARRAY_BUFFER, 0);
  this->shader->setAttributeArray(0, GL_FLOAT, values, 2);
  this->shader->setUniformValue("t", 2);
  glViewport(0, 0, this->view_port_size.width(), this->view_port_size.height());
  glDisable(GL_DEPTH_TEST);
  glEnable(GL_BLEND);
  glBlendFunc(GL_SRC_ALPHA, GL_ONE);
  glDrawArrays(GL_TRIANGLE_STRIP, 0, 4);
  this->shader->disableAttributeArray(0);
  this->shader->release();
  this->window->endExternalCommands();
}

MapDisplayRender::~MapDisplayRender() {
  if (this->shader) {
    delete this->shader;
  }
};
