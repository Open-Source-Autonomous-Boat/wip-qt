#include <qsggeometry.h>
#include <QSGGeometry>
#pragma once

class ShapeFrame {
 public:
  virtual void Set(float data[]);
  QSGGeometry* GetQSGGeometryObject();
private:
  int total_verts;
};

class RectShape : public ShapeFrame {
 public:
  void Set(float data[5]) override;
 private:
  float x = 0; // X-coord
  float y = 0; // Y-coord
  float r = 0; // Red (RGBA)
  float g = 0; // Green (RGBA)
  float b = 0; // Blue (RGBA)
  float a = 0; // Alpha (RGBA)
private:
  const int total_verts = 4;
};
