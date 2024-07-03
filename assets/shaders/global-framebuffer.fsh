#version 330 core

in vec2 uv;

uniform sampler2D framebuffer;

out vec4 FragColor;

void main() {
    vec3 col = texture(framebuffer, uv).rgb;

    FragColor = vec4(col, 1.0);
}