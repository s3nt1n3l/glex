#version 130

in vec3 position;
in vec3 color;

out vec3 frag_color;

uniform mat4 translateMatrix;
uniform mat4 viewMatrix;
uniform mat4 projectionMatrix;
uniform mat4 model;

void main() {
      gl_Position = projectionMatrix
              * viewMatrix
              * translateMatrix
	      * model
              * vec4(position, 1.0);
                  frag_color = color; //vec3(1.0f, 1.0f, 1.0);
}
