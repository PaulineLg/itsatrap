#version 330 core

layout(location = 0) in vec3 aVertexPosition;
layout(location = 1) in vec3 aVertexNormale;
layout(location = 2) in vec2 aVertexTexCoords;

uniform mat4 uMVPMatrix;
uniform mat4 uMVMatrix;
uniform mat4 uNormalMatrix;

out vec3 vFragPosition;
out vec3 vFragNormale;
out vec2 vFragTexCoords;

void main() {
  vFragPosition = vec3(uMVMatrix * vec4(aVertexPosition, 1));
  vFragNormale = vec3(uMVMatrix * vec4(aVertexNormale, 0));
  vFragTexCoords = aVertexTexCoords;

  gl_Position = vec4(uMVPMatrix * vec4(aVertexPosition, 1));
};