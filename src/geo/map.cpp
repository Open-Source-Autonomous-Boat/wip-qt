
#include "geo/map.h"

#include <qquickwindow.h>

#include <QQuickItem>
#include <QQuickRenderControl>

#include "geo/render.h"
#include "utils/cleaner.h"

MapDisplay::MapDisplay() : render(nullptr) {
  this->connect(this, &QQuickItem::windowChanged, this,
                &MapDisplay::HandleWindowChanged);
  this->setFlag(QQuickItem::ItemHasContents);
  return;
}

void MapDisplay::HandleWindowChanged(QQuickWindow *win) {
  if (win) {
    this->connect(win, &QQuickWindow::beforeSynchronizing, this,
                  &MapDisplay::Sync, Qt::DirectConnection);
    this->connect(win, &QQuickWindow::sceneGraphInvalidated, this,
                  &MapDisplay::Cleanup, Qt::DirectConnection);
    win->setColor(Qt::black);
  }
}

void MapDisplay::Sync() {
  if (!this->render) {
    this->render = new MapDisplayRender();
    this->connect(this->window(), &QQuickWindow::beforeRendering, this->render,
                  &MapDisplayRender::Init, Qt::DirectConnection);
    this->connect(this->window(), &QQuickWindow::beforeRenderPassRecording,
                  this->render, &MapDisplayRender::Paint, Qt::DirectConnection);
  }
  this->render->SetViewPortSize((this->window()->size() / 2) *
                                (this->window()->devicePixelRatio() / 2));
  this->render->SetWindow(this->window());
}

void MapDisplay::Cleanup() { delete this->render; }

void MapDisplay::releaseResources() {
  this->window()->scheduleRenderJob(
      new CleanJob<MapDisplayRender>(this->render),
      QQuickWindow::BeforeSynchronizingStage);
  this->render = nullptr;
};

MapDisplay::~MapDisplay() = default;
