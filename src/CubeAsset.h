#ifndef CUBEASSET_H
#define CUBEASSET_H

#include <vector>

#include <GL/gl.h>
#include <glm/glm.hpp>
#include <glm/ext.hpp>

#include "GameAsset.h"

class CubeAsset : public GameAsset {
 public:
   CubeAsset(float x, float y, float z);
  ~CubeAsset();
  virtual void Draw(GLuint);
  void rotateX(float);
 

 private:
  GLuint element_buffer_length;
  GLuint vertex_buffer_token, element_buffer_token;
  glm::mat4 model_matrix;
};

#endif // CUBEASSET_H
