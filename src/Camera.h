#ifndef SRC_CAMERA_H
#define SRC_CAMERA_H

#include <glm/ext.hpp>
#include "common.h"

/*
 * This defines the variables used in the camera class, it also interfaces with the other classes needed.
 */

class Camera{
  public:
    Camera();
    glm::mat4 UpdateCameraPosition( Input input_Direction, int MouseX, int MouseY);
  private:

    glm::vec3 cameraPosition;
    glm::vec3 Direction;
    glm::vec3 Right;
    glm::vec3 Up;

    float HoriAngle;
    float VertAngle;

    float DeltaTimeX;
    float DeltaTimeY;

    float MouseCameraSpeed;
    float KeyCameraSpeed;

};

#endif
