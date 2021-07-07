#include "geo/shapes.h"

#include <qsggeometry.h>

#include <QDebug>
#include <QSGGeometry>

QSGGeometry* get_geo_data::GetRectShape() {
  struct rect_shape rect;
  return new QSGGeometry(QSGGeometry::defaultAttributes_Point2D(),
                         rect.seg_count);
}
