#version 460

layout(location = 0) in vec4 vertex_object;
layout(location = 1) in vec2 texture_coord;

layout(location = 0) out vec2 out_texture_coord;

void main() {
  gl_Position = vertex_object;
  out_texture_coord = texture_coord;
}
