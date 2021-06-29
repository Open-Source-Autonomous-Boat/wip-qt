#version 440


layout(location = 0) in vec4 vertex_object;

void main() {
  gl_Position = vertex_object;
}
