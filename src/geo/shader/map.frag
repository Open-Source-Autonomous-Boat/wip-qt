#version 460

layout(location = 0) out vec4 frag_color;

layout(std140, binding=0) uniform buf {
  mat4 qt_matrix; // offset 0
} ubuf;

void main() {
  frag_color = vec4(0.0, 0.0, 1.0, 0.8);
}
