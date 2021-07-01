#include "geo/shapes.h"
#include <qsggeometry.h>

#include <QSGGeometry>


QSGGeometry* get_geo_data::GetRectShape() {
  return new QSGGeometry(QSGGeometry::defaultAttributes_Point2D(), 4);
}

