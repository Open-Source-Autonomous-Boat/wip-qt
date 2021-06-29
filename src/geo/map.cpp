#include "geo/map.h"

#include <qglobal.h>
#include <qquickitem.h>
#include <qsggeometry.h>
#include <qsgmaterial.h>
#include <qsgmaterialshader.h>
#include <qsgmaterialtype.h>
#include <qsgnode.h>
#include <qsgrendererinterface.h>

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
    qDebug() << "Getting new node";
    node = new MapNode();
  }
  if (this->flag_geo_changed) {
    node->ChangeRectBounds(this->boundingRect());
    this->flag_geo_changed = false;
  }
  return node;
}

void MapDisplay::geometryChange(const QRectF& new_geo, const QRectF& old_geo) {
  this->flag_geo_changed = false;
  this->update();
  QQuickItem::geometryChange(new_geo, old_geo);
}

/* MapShader Class */

MapShader::MapShader() {
  qDebug() << "I have no shaders";
  setShaderFileName(VertexStage, QString("qrc:/geo/shader/map.vert.qsb"));
  //setShaderFileName(FragmentStage, QString("qrc:/geo/shader/map.frag"));
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
  auto* mat = new MapMaterial();
  this->setMaterial(mat);
  this->setFlag(OwnsMaterial, true);
  auto* geo = get_geo_data::GetRectShape();
  QSGGeometry::updateTexturedRectGeometry(geo, QRect(), QRect());
  this->setGeometry(geo);
  this->setFlag(OwnsGeometry, true);
}

void MapNode::ChangeRectBounds(const QRectF& bounds) {
  QSGGeometry::updateTexturedRectGeometry(this->geometry(), bounds,
                                          QRectF(0, 0, 1, 1));
  this->markDirty(QSGNode::DirtyGeometry);
}
