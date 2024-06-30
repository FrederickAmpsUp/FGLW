#version 330 core

layout(location = 0) in vec3 aPosition;
layout(location = 1) in vec3 aNormal;
layout(location = 2) in vec2 aTexCoord;

uniform mat4 proj;
uniform mat4 view;
uniform mat4 model;


out vec2 texcoord;

void main() {
    texcoord = aTexCoord;
    vec4 local = vec4(aPosition, 1.0);
    gl_Position = proj * view * model * local;
}