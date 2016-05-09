#include "CubeAsset.h"

CubeAsset::CubeAsset(GLfloat x, GLfloat y, GLfloat z): model_matrix(glm::mat4(1.0)){
  // model coordinates, origin at centre.
  GLfloat vertex_buffer [] {
  	x-0.5, 	 y-0.5,   z-0.5
    , 	x-0.5,   (y+0.5), z-0.5
    ,   (x+0.5), y-0.5,   z-0.5
    ,   (x+0.5), (y+0.5), z-0.5
    ,   x-0.5,   y-0.5,   (z+0.5)
    ,   x-0.5,   (y+0.5), (z+0.5)
    ,   (x+0.5), y-0.5,   (z+0.5)
    ,   (x+0.5), (y+0.5), (z+0.5)
  };

GLfloat g_color_buffer[] = {
     0.350f, 0.450f, 0.550f,
     0.350f, 0.450f, 0.550f,
     0.350f, 0.450f, 0.550f,
     0.350f, 0.450f, 0.550f,
     0.350f, 0.450f, 0.550f,
     0.350f, 0.450f, 0.550f,
     0.350f, 0.450f, 0.550f,
     0.350f, 0.450f, 0.550f
};
	color_buffer_length = sizeof(g_color_buffer);
  element_buffer_length = 36;
  GLuint element_buffer []  {
    0, 1, 2
    , 1, 3, 2
    , 0, 1, 4
    , 1, 4, 5
    , 4, 5, 6
    , 5, 6, 7
    , 0, 2, 4
    , 2, 4, 6
    , 2, 3, 6
    , 3, 6, 7
    , 1, 3, 5
    , 3, 5, 7
  };

  // create buffer
  glGenBuffers(1, &vertex_buffer_token);

  // immediately bind the buffer and transfer the data
  glBindBuffer(GL_ARRAY_BUFFER, vertex_buffer_token);
  glBufferData(GL_ARRAY_BUFFER, sizeof(GLfloat) * 24, vertex_buffer, GL_STATIC_DRAW);

  glGenBuffers(1, &color_buffer_token);
  glBindBuffer(GL_ARRAY_BUFFER, color_buffer_token);
  glBufferData(GL_ARRAY_BUFFER, color_buffer_length, g_color_buffer, GL_STATIC_DRAW);

  glGenBuffers(1, &element_buffer_token);
  glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, element_buffer_token);
  glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(GLuint) * element_buffer_length, element_buffer, GL_STATIC_DRAW);
}

CubeAsset::~CubeAsset() {
}

#ifdef DEBUG
#define checkGLError() checkError(__FILE__, __LINE__)
#else
// define symbol to be nothing
#define checkGLError()
#endif

void checkError(std::string file, int line) {
  GLenum gl_error = glGetError();
  if(GL_NO_ERROR != gl_error) {
    std::cerr << "GL error in " << file << " at line " << line << " error: " << gl_error << std::endl;
    exit(-1);
  }
}

void CubeAsset::Draw(GLuint program_token) {
  if(!glIsProgram(program_token)) {
    std::cerr << "Drawing Cube with invalid program" << std::endl;
    return;
  }
  GLint validation_ok;
  glValidateProgram(program_token);
  glGetProgramiv(program_token, GL_VALIDATE_STATUS, &validation_ok);
  if(!validation_ok) {
    GLint maxLength = 0;
    glGetProgramiv(program_token, GL_INFO_LOG_LENGTH, &maxLength);

    //The maxLength includes the NULL character
    std::vector<char> errorLog(maxLength);
    glGetProgramInfoLog(program_token, maxLength, &maxLength, &errorLog[0]);

    std::cerr << "Invalid program " << program_token << " with error code " << validation_ok << std::endl;
    for(auto c: errorLog) {
      std::cerr << c;
    }
    exit(-1);
  }
  
  GLuint position_attrib = glGetAttribLocation(program_token, "position");
  GLuint model_uniform = glGetUniformLocation(program_token, "model");
  checkGLError();

  
  glUseProgram(program_token);
  checkGLError();

  glUniformMatrix4fv(model_uniform, 1, false, glm::value_ptr(model_matrix));
  rotateX(45.0f);
  // use the previously transferred buffer as the vertex array.  This way
  // we transfer the buffer once -- at construction -- not on every frame.
  glEnableVertexAttribArray(0);
  glBindBuffer(GL_ARRAY_BUFFER, vertex_buffer_token);
  glVertexAttribPointer(
                        0,		               /* attribute */
                        3,                             /* size */
                        GL_FLOAT,                      /* type */
                        GL_FALSE,                      /* normalized? */
                        0,                             /* stride */
                        (void*)0                       /* array buffer offset */
                        );
  glEnableVertexAttribArray(1);
  checkGLError();

  glBindBuffer(GL_ARRAY_BUFFER, color_buffer_token);
  glVertexAttribPointer(
                        1,		               /* attribute */
                        3,                             /* size */
                        GL_FLOAT,                      /* type */
                        GL_FALSE,                      /* normalized? */
                        0,                             /* stride */
                        (void*)0                       /* array buffer offset */
                        );

  glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, element_buffer_token);
  glDrawElements(
                 GL_TRIANGLES,
                 element_buffer_length,
                 GL_UNSIGNED_INT,
                 (GLvoid*) 0
                 );
  checkGLError();

  glDisableVertexAttribArray(position_attrib);
}

void CubeAsset::rotateX(float angle) {

    glm::vec3 unit_x_axis(1.0,0.0,0.0);
    glm::vec3 unit_y_axis(0.0,1.0,0.0);
    glm::mat4 id(model_matrix);
    model_matrix = glm::rotate(id, 45.0f, unit_x_axis);
  }

