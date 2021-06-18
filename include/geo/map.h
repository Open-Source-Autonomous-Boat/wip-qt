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

class MapDisplay : public QQuickItem {
  Q_OBJECT;
  QML_ELEMENT;
public:
  MapDisplay();
  QSGNode* updatePaintNode(QSGNode* old, UpdatePaintNodeData*) override;
  
};

class MapShader : public QSGMaterialShader {
public:
  MapShader();
};

class MapMaterial : public QSGMaterial {
public:
  MapMaterial();
  ~MapMaterial();
  QSGMaterialType* type() const override;
  int compare(const QSGMaterial* other) const override;
  QSGMaterialShader* createShader(QSGRendererInterface::RenderMode) const override;
};


class MapNode: public QSGGeometryNode {
public:
  MapNode();
};
