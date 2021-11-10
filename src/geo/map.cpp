#include "geo/map.h"

#include "geo/shapes.h"

/* MapDisplay Class */

MapDisplay::MapDisplay(QQuickItem* parent) : QQuickItem(parent) {
  // QQmlEngine* test_engine = qmlEngine(this);
  this->setFlag(ItemHasContents, true);
  /* ERROR: connection issue */
  // if (test_engine == nullptr) {
  //   qWarning() << "Failed to load engine";
  //   return;
  // }
  // QQmlComponent grid_comp(
  //     test_engine, QUrl::fromLocalFile("../qml/snippets/GridWrapper.qml"));
  // auto* grid_obj = qobject_cast<QQuickItem*>(grid_comp.create());
  // QQmlEngine::setObjectOwnership(grid_obj, QQmlEngine::CppOwnership);
  // grid_obj->setParentItem(this);
  // grid_obj->setParent(test_engine);
};

QSGNode* MapDisplay::updatePaintNode(QSGNode* old, UpdatePaintNodeData*) {
  auto* node = static_cast<MapNode*>(old);
  QQmlEngine* test_engine = qmlEngine(this);
  if (test_engine == nullptr) {
    qDebug() << "Failed to get engine!";
  }
  QQmlComponent grid_comp(
      test_engine, QUrl("qrc:/qml/snippets/GridWrapper.qml"));
  if (grid_comp.status() != QQmlComponent::Ready) {
    if (grid_comp.status() == QQmlComponent::Error) {
      qDebug() << grid_comp.errorString();
    }
  }
  auto* grid_obj = qobject_cast<QQuickItem*>(grid_comp.create());
  grid_obj->moveToThread(this->thread());
  // QQmlEngine::setObjectOwnership(grid_obj, QQmlEngine::CppOwnership);
  // grid_obj->setParentItem(this);
  // grid_obj->setParent(test_engine);

  if (!node) {
    node = new MapNode();
  }
  if (this->flag_geo_changed) {
    node->ChangeRectBounds(this->boundingRect());
    this->flag_geo_changed = false;
  }
  const QRectF rect = this->boundingRect();
  auto* vertices = node->geometry()->vertexDataAsPoint2D();
  vertices[0].set(rect.bottomLeft().x(), rect.bottomLeft().y());
  vertices[1].set(rect.bottomRight().x(), rect.bottomRight().y());
  vertices[2].set(rect.topLeft().x(), rect.topLeft().y());
  vertices[3].set(rect.topRight().x(), rect.topRight().y());
  node->markDirty(QSGNode::DirtyGeometry);
  return node;
}

void MapDisplay::geometryChange(const QRectF& new_geo, const QRectF& old_geo) {
  this->flag_geo_changed = false;
  this->update();
  QQuickItem::geometryChange(new_geo, old_geo);
}

/* MapShader Class */

MapShader::MapShader() {
  setShaderFileName(VertexStage, QLatin1String(":/geo/shader/map.vert.qsb"));
  setShaderFileName(FragmentStage, QLatin1String(":/geo/shader/map.frag.qsb"));
};

bool MapShader::updateUniformData(RenderState& state, QSGMaterial* new_material,
                                  QSGMaterial* old_material) {
  bool changed = false;
  QByteArray* buf = state.uniformData();
  Q_ASSERT(buf->size() >= 64);

  if (state.isMatrixDirty()) {
    const QMatrix4x4 m = state.combinedMatrix();
    std::memcpy(buf->data(), m.constData(), 64);
    changed = true;
  }
  auto* cus_masterial = static_cast<MapMaterial*>(new_material);
  if (old_material != new_material || cus_masterial->uniform.dirty) {
    cus_masterial->uniform.dirty = false;
    changed = true;
  }
  return changed;
}

/* MapMaterial Class */

MapMaterial::MapMaterial(){};

QSGMaterialType* MapMaterial::type() const {
  static QSGMaterialType type;
  return &type;
}

int MapMaterial::compare(const QSGMaterial* o) const {
  Q_ASSERT(o && this->type() == o->type());
  const auto* other = static_cast<const MapMaterial*>(o);
  return other == this ? 0 : 1;
}

QSGMaterialShader* MapMaterial::createShader(
    QSGRendererInterface::RenderMode) const {
  return new MapShader;
}

/* MapNode Class */

MapNode::MapNode() {
  // Material
  this->m_mat = new MapMaterial();
  this->setMaterial(this->m_mat);
  this->setFlag(QSGGeometryNode::OwnsMaterial, true);
  // Geometry
  this->m_geo = get_geo_data::GetRectShape();
  QSGGeometry::updateTexturedRectGeometry(this->m_geo, QRect(), QRect());
  this->setGeometry(this->m_geo);
  this->setFlag(QSGGeometryNode::OwnsGeometry, true);
}

void MapNode::ChangeRectBounds(const QRectF& bounds) {
  QSGGeometry::updateTexturedRectGeometry(this->geometry(), bounds,
                                          QRectF(0, 0, 0, 0));
  this->markDirty(QSGNode::DirtyGeometry);
}
