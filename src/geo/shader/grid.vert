#version 460

layout(location = 0) in vec4 vertex_object;
layout(location = 1) in vec2 atex_coord;
layout(location = 0) out vec2 vtex_coord; 

layout(std140, binding=0) uniform buf {
  mat4 qt_matrix; // offset 0
} ubuf;

void main() {
  gl_Position = ubuf.qt_matrix * vertex_object;
  vtex_coord = atex_coord;
}
