#ifndef SRC_CAMERA_H
#define SRC_CAMERA_H

#include <glm/ext.hpp>
#include "common.h"

///definition of the Camera class, defines many of the variables used to calculate camera position

class Camera{
  public:
    Camera();
    glm::mat4 UpdateCameraPosition( Input input_Direction, int MouseX, int MouseY);
  private:

    float CameraPositionX;
    float CameraPositionY;
    float CameraPositionZ;

    glm::vec3 cameraPosition;
    glm::vec3 Direction;
    glm::vec3 Right;
    glm::vec3 Up;

    float HorizontalAngle;
    float VerticalAngle;

    float DeltaTimeX;
    float DeltaTimeY;

    float MouseCameraSpeed;
    float KeyCameraSpeed;

};

#endif
