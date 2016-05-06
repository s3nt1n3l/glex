#include "Camera.h"
#include <glm/ext.hpp>

/// this class will initialise the variables for the camera/player, it will also create a view matrix based on the position of the camera.

Camera::Camera() {

  cameraPosition = glm::vec3(0.0f, 0.0f, 0.0f);
  Direction = glm::vec3(0,0,0);
  Right = glm::vec3(0,0,0);
  Up = glm::vec3(0,0,0);

  HorizontalAngle = 0;
  VerticalAngle = 0;

  DeltaTimeX = 1;
  DeltaTimeY = 1;

  CameraSpeed = 0.20;

}

///Updates camera depending on the user input, will change the view matrix.

    glm::mat4 Camera::UpdateCameraPosition( Input input_Direction, int MouseX, int MouseY) {
      DeltaTimeX = -MouseX;
      DeltaTimeY = -MouseY;

      HorizontalAngle += 0.01 * DeltaTimeX;

///the following if statement will give the player x axis restriction, this is to insure that you can't turn the camera upside down

  if((VerticalAngle + (0.01 * DeltaTimeY)) < 1 && (VerticalAngle + (0.01 * DeltaTimeY)) > -1) {
    VerticalAngle += 0.01 * DeltaTimeY;
  }

///calculate of directions of view

    Direction = glm::vec3(cos(VerticalAngle) * sin(HorizontalAngle),sin(VerticalAngle),cos(VerticalAngle) * cos(HorizontalAngle));
    Right = glm::vec3(sin(HorizontalAngle - 3.14/2.0f),0,cos(HorizontalAngle - 3.14/2.0f));
    Up = glm::cross(Right, Direction);

///update current position of the camera/player depending on the users input

      if( input_Direction == UP ) {
          cameraPosition += glm::vec3(cos(VerticalAngle) * sin(HorizontalAngle),0,cos(VerticalAngle) * cos(HorizontalAngle))* CameraSpeed;
      } else if( input_Direction == DOWN ) {
          cameraPosition -= glm::vec3(cos(VerticalAngle) * sin(HorizontalAngle),0,cos(VerticalAngle) * cos(HorizontalAngle))* CameraSpeed;
      } else if( input_Direction == LEFT) {
          cameraPosition -= Right * CameraSpeed;
      } else if( input_Direction == RIGHT) {
          cameraPosition += Right * CameraSpeed;
  }

///return of view matrix

 return glm::lookAt(cameraPosition, cameraPosition + Direction,Up);
}
