#include <qqml.h>
#include <qquickitem.h>
#include <qsgmaterial.h>
#include <qsgmaterialshader.h>
#include <qsgmaterialtype.h>
#include <qsgnode.h>
#include <qsgrendererinterface.h>
#include <qsgtexture.h>
#include <qtmetamacros.h>

#include <QQuickItem>
#include <QSGGeometryNode>
#include <QSGMaterial>
#include <QSGTexture>
#include <QSGTextureProvider>
#include <QtQuick>
#pragma once

class MapDisplay : public QQuickItem {
  Q_OBJECT;
  Q_PROPERTY(
      QQuickItem* source READ source WRITE setsource NOTIFY sourceChanged);
  QML_ELEMENT;

 public:
  MapDisplay(QQuickItem* parent = nullptr);
  QQuickItem* source() const { return this->m_source; };
  void setsource(QQuickItem* a_source);

 private:
  bool flag_geo_changed = true;
  QQuickItem* m_source;
  bool m_source_changed = false;

 protected:
  QSGNode* updatePaintNode(QSGNode* old, UpdatePaintNodeData*) override;
  void geometryChange(const QRectF& new_geo, const QRectF& old_geo) override;

 signals:
  void sourceChanged();
};

// Shaders for map
class MapShader : public QSGMaterialShader {
 public:
  MapShader();
  bool updateUniformData(RenderState& state, QSGMaterial* new_material,
                         QSGMaterial* old_material) override;
  void updateSampledImage(QSGMaterialShader::RenderState& state, int binding,
                          QSGTexture** texture, QSGMaterial* new_material,
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
  struct {
    QSGTexture* texture1 = nullptr;
  } state;
};

// This handles rendering functions and lives in the rendering thread
class MapNode : public QSGGeometryNode {
 public:
  MapNode();
  void ChangeRectBounds(const QRectF& bounds);
  void SetSegments(const QRectF rect);
  void preprocess() override;

 private:
  MapMaterial* m_mat;
  QSGGeometry* m_geo;
  QSGGeometryNode m_node;
  QPointer<QSGTextureProvider> texture1;
};
