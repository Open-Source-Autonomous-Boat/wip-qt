#include "geo/map.h"

#include <qglobal.h>
#include <qsggeometry.h>
#include <qsgmaterial.h>
#include <qsgmaterialshader.h>
#include <qsgmaterialtype.h>
#include <qsgnode.h>
#include <qsgrendererinterface.h>

#include <memory>

#include "geo/shapes.h"

/* MapDisplay Class */

MapDisplay::MapDisplay(){};

QSGNode* MapDisplay::updatePaintNode(QSGNode* old, UpdatePaintNodeData*) {
  auto* node = static_cast<MapNode*>(old);

  if (!node) {
    node = new MapNode();
  }
  return node;
}

/* MapShader Class */

MapShader::MapShader(){};

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
  std::unique_ptr<RectShape>rect_shape(new RectShape());
  auto* mat = new MapMaterial();
  this->setMaterial(mat);
  this->setFlag(OwnsMaterial, true);
  auto* geo = rect_shape.get()->GetQSGGeometryObject();
  QSGGeometry::updateTexturedRectGeometry(geo, QRect(), QRect());
  this->setGeometry(geo);
  this->setFlag(OwnsGeometry, true);
}
