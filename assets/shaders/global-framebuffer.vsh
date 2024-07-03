#version 330 core

layout(location = 0) in vec2 aUV;

out vec2 uv;

void main() {
    gl_Position = vec4(aUV * 2.0 - 1.0, 0.0, 1.0);
    uv = aUV;
}