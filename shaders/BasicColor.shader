#shader vertex
#version 330 core

layout(location = 0) in vec4 v_position;
layout(location = 1) in vec4 v_normal;
layout(location = 2) in vec4 v_tangent;
layout(location = 3) in vec2 v_uv;
layout(location = 4) in vec4 v_color;

out vec4 o_color;

void main(){
   gl_Position = v_position;
   o_color = v_color;
}

#shader fragment
#version 330 core

layout(location = 0) out vec4 color;

in vec4 o_color;

void main(){
   color = vec4(1.0f, 1.0f, 1.0f, 1.0f);
}