#include <QQuickItem>
#include <QSGGeometryNode>
#include <QSGMaterial>
#include <QSGTexture>
#include <QSGTextureProvider>
#include <QtQuick>
#include <QtQml>
#include <QQmlEngine>
#pragma once

class GridDisplay : public QQuickItem {
  Q_OBJECT;
  QML_ELEMENT;

 public:
  GridDisplay(QQuickItem* parent = nullptr);

 private:
  bool flag_geo_changed = true;

 protected:
  QSGNode* updatePaintNode(QSGNode* old, UpdatePaintNodeData*) override;
  void geometryChange(const QRectF& new_geo, const QRectF& old_geo) override;
  QQmlEngine* m_engine;

 signals:
  void onClick();
};

// Shaders for map
class GridShader : public QSGMaterialShader {
 public:
  GridShader();
  bool updateUniformData(RenderState& state, QSGMaterial* new_material,
                         QSGMaterial* old_material) override;
};

// Material for map
/*
 * FIXME: Shaders do not show!
 */
class GridMaterial : public QSGMaterial {
 public:
  GridMaterial();
  QSGMaterialType* type() const override;
  int compare(const QSGMaterial* other) const override;
  QSGMaterialShader* createShader(
      QSGRendererInterface::RenderMode) const override;
  struct {
    bool dirty;
  } uniform;
};

// This handles rendering functions and lives in the rendering thread
class GridNode : public QSGGeometryNode {
 public:
  GridNode();
  void ChangeRectBounds(const QRectF& bounds);
  void SetSegments(const QRectF rect);

 private:
  GridMaterial* m_mat;
  QSGGeometry* m_geo;
  QSGGeometryNode m_node;
};
