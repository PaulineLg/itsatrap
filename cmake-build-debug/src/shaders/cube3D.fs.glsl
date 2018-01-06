#version 330 core

in vec3 vFragPosition;
in vec3 vFragNormale;
in vec2 vFragTexCoords;

out vec3 fFragColor;

uniform sampler2D uTexture;

void main() {
  fFragColor = vFragNormale;//texture(uTexture, vFragTexCoords).rgb;
};