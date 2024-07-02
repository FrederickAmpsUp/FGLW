#version 330 core

in vec2 texcoord;

out vec4 FragColor;

uniform sampler2D tex0;
uniform sampler2D tex1;

void main() {
    vec3 texel0 = texture(tex0, texcoord).rgb;
    vec3 texel1 = texture(tex1, texcoord).rgb;

    FragColor = vec4(texel0 + texel1, 1.0);
}