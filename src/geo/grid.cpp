#include "geo/grid.h"

#include "geo/shapes.h"

/* GridDisplay Class */

GridDisplay::GridDisplay(QQuickItem* parent)
    : QQuickItem(parent), m_engine(qmlEngine(this)) {
  this->setFlag(ItemHasContents, true);
}

QSGNode* GridDisplay::updatePaintNode(QSGNode* old, UpdatePaintNodeData*) {
  auto* node = static_cast<GridNode*>(old);

  if (!node) {
    node = new GridNode();
  }
  if (this->flag_geo_changed) {
    node->ChangeRectBounds(this->boundingRect());
    this->flag_geo_changed = false;
  }
  const QRectF rect = this->boundingRect();
  auto* vertices = node->geometry()->vertexDataAsPoint2D();
  int size_width = this->property("width").toInt();
  int size_height = this->property("height").toInt();
  vertices[0].set(0, size_height);
  vertices[1].set(size_width, size_height);
  vertices[2].set(0, 0);
  vertices[3].set(size_width, 0);
  node->markDirty(QSGNode::DirtyGeometry);
  return node;
}

void GridDisplay::geometryChange(const QRectF& new_geo, const QRectF& old_geo) {
  this->flag_geo_changed = false;
  this->update();
  QQuickItem::geometryChange(new_geo, old_geo);
}

/* GridShader Class */

GridShader::GridShader() {
  setShaderFileName(VertexStage, QLatin1String(":/geo/shader/grid.vert.qsb"));
  setShaderFileName(FragmentStage, QLatin1String(":/geo/shader/grid.frag.qsb"));
};

bool GridShader::updateUniformData(RenderState& state,
                                   QSGMaterial* new_material,
                                   QSGMaterial* old_material) {
  bool changed = false;
  QByteArray* buf = state.uniformData();
  Q_ASSERT(buf->size() >= 64);

  if (state.isMatrixDirty()) {
    const QMatrix4x4 m = state.combinedMatrix();
    std::memcpy(buf->data(), m.constData(), 64);
    changed = true;
  }
  auto* cus_material = static_cast<GridMaterial*>(new_material);
  if (old_material != new_material || cus_material->uniform.dirty) {
    cus_material->uniform.dirty = false;
    changed = true;
  }
  return changed;
}

/* GridMaterial Class */

GridMaterial::GridMaterial(){};

QSGMaterialType* GridMaterial::type() const {
  static QSGMaterialType type;
  return &type;
}

int GridMaterial::compare(const QSGMaterial* o) const {
  Q_ASSERT(o && this->type() == o->type());
  const auto* other = static_cast<const GridMaterial*>(o);
  return other == this ? 0 : 1;
}

QSGMaterialShader* GridMaterial::createShader(
    QSGRendererInterface::RenderMode) const {
  return new GridShader;
}

/* GridNode Class */

GridNode::GridNode() {
  // Material
  this->m_mat = new GridMaterial();

  this->setMaterial(this->m_mat);
  this->setFlag(QSGGeometryNode::OwnsMaterial, true);
  // Geometry
  this->m_geo = get_geo_data::GetRectShape();
  QSGGeometry::updateTexturedRectGeometry(this->m_geo, QRect(), QRect());
  this->setGeometry(this->m_geo);
  this->setFlag(QSGGeometryNode::OwnsGeometry, true);
}

void GridNode::ChangeRectBounds(const QRectF& bounds) {
  QSGGeometry::updateTexturedRectGeometry(this->geometry(), bounds,
                                          QRectF(0, 0, 0, 0));
  this->markDirty(QSGNode::DirtyGeometry);
}
