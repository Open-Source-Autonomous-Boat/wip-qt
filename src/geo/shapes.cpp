#include "geo/shapes.h"
#include <qsggeometry.h>

#include <QSGGeometry>


QSGGeometry* ShapeFrame::GetQSGGeometryObject() {
  return new QSGGeometry(QSGGeometry::defaultAttributes_Point2D(), this->total_verts);
}

void RectShape::Set(float data[5]) {
  this->x = data[0];
  this->y = data[1];
  this->r = data[2];
  this->g = data[3];
  this->b = data[4];
  this->a = data[5];
}
