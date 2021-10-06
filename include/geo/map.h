#include <QColor>
#include <QDebug>
#include <QQuickItem>
#include <QSGFlatColorMaterial>
#include <QSGGeometryNode>
#include <QSGMaterial>
#include <QSGTexture>
#include <QSGTextureProvider>
#include <QtQuick>
#include <memory>
#pragma once

class MapDisplay : public QQuickItem {
  Q_OBJECT;
  QML_ELEMENT;

 public:
  MapDisplay(QQuickItem* parent = nullptr);

 private:
  bool flag_geo_changed = true;

 protected:
  QSGNode* updatePaintNode(QSGNode* old, UpdatePaintNodeData*) override;
  void geometryChange(const QRectF& new_geo, const QRectF& old_geo) override;
  QQmlEngine* engine;

 signals:
};

// Shaders for map
class MapShader : public QSGMaterialShader {
 public:
  MapShader();
  bool updateUniformData(RenderState& state, QSGMaterial* new_material,
                         QSGMaterial* old_material) override;
};

// Material for map
/*
 * FIXME: Shaders do not show!
 */
class MapMaterial : public QSGMaterial {
 public:
  MapMaterial();
  QSGMaterialType* type() const override;
  int compare(const QSGMaterial* other) const override;
  QSGMaterialShader* createShader(
      QSGRendererInterface::RenderMode) const override;
  struct {
    bool dirty;
  } uniform;
};

// This handles rendering functions and lives in the rendering thread
class MapNode : public QSGGeometryNode {
 public:
  MapNode();
  void ChangeRectBounds(const QRectF& bounds);
  void SetSegments(const QRectF rect);

 private:
  MapMaterial* m_mat;
  QSGGeometry* m_geo;
  QSGGeometryNode m_node;
};
