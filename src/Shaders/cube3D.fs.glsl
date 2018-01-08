#version 330 core

in vec3 vFragPosition;
in vec3 vFragNormale;
in vec2 vFragTexCoords;

out vec3 fFragColor;

uniform sampler2D uTexture;

void main() {
  fFragColor = vec3(0.0,1.0,0.0);//texture(uTexture, vFragTexCoords).rgb;
};