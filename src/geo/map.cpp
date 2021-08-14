#include "geo/map.h"

#include <qquickitem.h>
#include <qsggeometry.h>
#include <qsgmaterial.h>
#include <qsgmaterialshader.h>
#include <qsgmaterialtype.h>
#include <qsgnode.h>
#include <qsgrendererinterface.h>

#include <QColor>
#include <QDebug>
#include <QSGFlatColorMaterial>
#include <memory>

#include "geo/shapes.h"

/* MapDisplay Class */

MapDisplay::MapDisplay(QQuickItem* parent) : QQuickItem(parent) {
  this->setFlag(ItemHasContents, true);
};

QSGNode* MapDisplay::updatePaintNode(QSGNode* old, UpdatePaintNodeData*) {
  auto* node = static_cast<MapNode*>(old);

  if (!node) {
    node = new MapNode();
  }
  if (this->flag_geo_changed) {
    node->ChangeRectBounds(this->boundingRect());
    this->flag_geo_changed = false;
  }
  const QRectF rect = this->boundingRect();
  auto* vertices = node->geometry()->vertexDataAsPoint2D();
  vertices[2].set(rect.bottomLeft().x(), rect.bottomLeft().y());
  vertices[3].set(rect.bottomRight().x(), rect.bottomRight().y());
  vertices[0].set(rect.topLeft().x(), rect.topLeft().y());
  vertices[1].set(rect.topRight().x(), rect.topRight().y());
  node->markDirty(QSGNode::DirtyGeometry);
  return node;
}

void MapDisplay::geometryChange(const QRectF& new_geo, const QRectF& old_geo) {
  this->flag_geo_changed = false;
  this->update();
  QQuickItem::geometryChange(new_geo, old_geo);
}

/* MapShader Class FIXME: Shaders do not show */

MapShader::MapShader() {
  setShaderFileName(VertexStage, QLatin1String(":/geo/shader/map.vert.qsb"));
  setShaderFileName(FragmentStage, QLatin1String(":/geo/shader/map.frag.qsb"));
};

bool MapShader::updateUniformData(RenderState& state, QSGMaterial* new_material,
                                  QSGMaterial* old_material) {
  bool changed = false;
  QByteArray* buf = state.uniformData();
  Q_ASSERT(buf->size() >= 64);

  if (state.isMatrixDirty()) {
    const QMatrix4x4 m = state.combinedMatrix();
    std::memcpy(buf->data(), m.constData(), 64);
    changed = true;
  }
  auto* cus_masterial = static_cast<MapMaterial*>(new_material);
  if (old_material != new_material || cus_masterial->uniform.dirty) {
    cus_masterial->uniform.dirty = false;
    changed = true;
  }
  return changed;
}

/* MapMaterial Class */

MapMaterial::MapMaterial(){};

QSGMaterialType* MapMaterial::type() const {
  static QSGMaterialType type;
  return &type;
}

int MapMaterial::compare(const QSGMaterial* o) const {
  Q_ASSERT(o && this->type() == o->type());
  const auto* other = static_cast<const MapMaterial*>(o);
  return other == this ? 0 : 1;
}

QSGMaterialShader* MapMaterial::createShader(
    QSGRendererInterface::RenderMode) const {
  return new MapShader;
}

/* MapNode Class */

MapNode::MapNode() {
  // Material
  auto* mat = new MapMaterial();
  this->setMaterial(mat);
  this->setFlag(QSGGeometryNode::OwnsMaterial, true);
  // Geometry
  auto* geo = get_geo_data::GetRectShape();
  QSGGeometry::updateTexturedRectGeometry(geo, QRect(), QRect());
  this->setGeometry(geo);
  this->setFlag(QSGGeometryNode::OwnsGeometry, true);
}

void MapNode::ChangeRectBounds(const QRectF& bounds) {
  QSGGeometry::updateTexturedRectGeometry(this->geometry(), bounds,
                                          QRectF(0, 0, 0, 0));
  this->markDirty(QSGNode::DirtyGeometry);
}
