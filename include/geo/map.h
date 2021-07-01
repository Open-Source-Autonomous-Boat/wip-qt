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

/*
 * I don't know wtf I am doing
 */

// This handles gui functions and lives in the gui thread
class MapDisplay : public QQuickItem {
  Q_OBJECT;
  QML_ELEMENT;
public:
  MapDisplay(QQuickItem* parent=nullptr);
  QSGNode* updatePaintNode(QSGNode* old, UpdatePaintNodeData*) override;
  void geometryChange(const QRectF &new_geo, const QRectF &old_geo) override;
private:
  bool flag_geo_changed = true;
};

// Shaders for ~~Minecraft~~ map
class MapShader : public QSGMaterialShader {
public:
  MapShader();
};


// Material for map
class MapMaterial : public QSGMaterial {
public:
  MapMaterial();
  ~MapMaterial();
  QSGMaterialType* type() const override;
  int compare(const QSGMaterial* other) const override;
  QSGMaterialShader* createShader(QSGRendererInterface::RenderMode) const override;
};


// This handles rendering functions and lives in the rendering thread
class MapNode: public QSGGeometryNode {
public:
  MapNode();
  void ChangeRectBounds(const QRectF &bounds);
  void SetSegments();
};
