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
  vertices[0].set(rect.bottomLeft().x(), rect.topLeft().y());
  vertices[1].set(rect.bottomLeft().x(), rect.bottomRight().x());
  vertices[2].set(rect.topLeft().x(), rect.topRight().x());
  vertices[3].set(rect.bottomRight().x(), rect.topRight().y());
  node->markDirty(QSGNode::DirtyGeometry | QSGNode::DirtyMaterial);
  return node;
}

void MapDisplay::geometryChange(const QRectF& new_geo, const QRectF& old_geo) {
  this->flag_geo_changed = false;
  this->update();
  QQuickItem::geometryChange(new_geo, old_geo);
}

/* MapShader Class */

MapShader::MapShader() {
  this->setShaderFileName(VertexStage, ":/geo/shader/map.vert.qsb");
  this->setShaderFileName(FragmentStage, ":/geo/shader/map.frag.qsb");
};

/* MapMaterial Class */

MapMaterial::MapMaterial(){};
MapMaterial::~MapMaterial(){};
QSGMaterialType* MapMaterial::type() const {
  static QSGMaterialType type;
  return &type;
}

int MapMaterial::compare(const QSGMaterial* other) const {
  Q_ASSERT(other && this->type() == other->type());
  const auto* other_2 = static_cast<const MapMaterial*>(other);
  return other_2 == this ? 0 : 1;
}

QSGMaterialShader* MapMaterial::createShader(
    QSGRendererInterface::RenderMode) const {
  return new MapShader();
}

/* MapNode Class */

MapNode::MapNode() {
  // Material
  auto* mat = new MapMaterial();
  this->setMaterial(mat);
  this->setFlag(QSGGeometryNode::OwnsMaterial, true);
  // Geometry
  auto* geo = get_geo_data::GetRectShape();
  this->setGeometry(geo);
  this->setFlag(QSGGeometryNode::OwnsGeometry, true);
}

void MapNode::ChangeRectBounds(const QRectF& bounds) {
  QSGGeometry::updateTexturedRectGeometry(this->geometry(), bounds,
                                          QRectF(0, 0, 0, 0));
  this->markDirty(QSGNode::DirtyGeometry);
}

void MapNode::SetSegments(const QRectF rect) {
}
