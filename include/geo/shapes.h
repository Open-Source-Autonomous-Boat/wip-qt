#include <qsggeometry.h>

#include <QSGGeometry>
#pragma once

struct rect_shape {
  float x;  // X coordinate
  float y;  // Y coordinate
  float r;  // Red
  float g;  // Green
  float b;  // Blue
  float a;  // Alpha
  const int seg_count = 4;
  void set(float n_x, float n_y, float n_r, float n_g, float n_b, float n_a) {
    this->x = n_x;
    this->y = n_y;
    this->r = n_r;
    this->g = n_g;
    this->b = n_b;
    this->a = n_a;
  }
};

namespace get_geo_data {
QSGGeometry* GetRectShape();
}
