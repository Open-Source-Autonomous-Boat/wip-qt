#version 460

layout(location = 0) in vec4 vertex_object;
layout(location = 1) in vec2 atex_coord;
layout(location = 0) out vec2 vtex_coord; 

void main() {
  gl_Position = vertex_object;
  vtex_coord = atex_coord;
}
