#include "Camera.h"
#include <glm/ext.hpp>

/* This Class contains the initialisation of the camera and handles all the matrix creation for the view in game.
 * In addition to calculating looking direction with the mouse it can traverse 3 dimentions using the W,A,S,D,LCTRL,SPACE keys.
 */

Camera::Camera() {

  cameraPosition = glm::vec3(0.0f, 0.0f, 0.0f);
  Direction = glm::vec3(0,0,0);
  Right = glm::vec3(0,0,0);
  Up = glm::vec3(0,0,0);

  HoriAngle = 0;
  VertAngle = 0;

  DeltaTimeX = 1;
  DeltaTimeY = 1;

  MouseCameraSpeed = 0.001;
  KeyCameraSpeed = 0.30;

}

///Changes the view matrix by taking the users input and reacting accordingly

    glm::mat4 Camera::UpdateCameraPosition( Input input_Direction, int MouseX, int MouseY) {
      DeltaTimeX = -MouseX;
      DeltaTimeY = -MouseY;

      HoriAngle += 0.01 * DeltaTimeX;

///This 'if' will stop the player from flipping the camera

  if((VertAngle + (MouseCameraSpeed * DeltaTimeY)) < 1 && (VertAngle + (0.01 * DeltaTimeY)) > -1) {
    VertAngle += 0.01 * DeltaTimeY;
  }

///Calculations for point of view

    Direction = glm::vec3(cos(VertAngle) * sin(HoriAngle),sin(VertAngle),cos(VertAngle) * cos(HoriAngle));
    Right = glm::vec3(sin(HoriAngle - 3.14/2.0f),0,cos(HoriAngle - 3.14/2.0f));
    Up = glm::cross(Right, Direction);

///Updates the current camera position based on the registered input detected

      if( input_Direction == UP ) {
          cameraPosition += glm::vec3(cos(VertAngle) * sin(HoriAngle),0,cos(VertAngle) * cos(HoriAngle))* KeyCameraSpeed;
      } else if( input_Direction == DOWN ) {
          cameraPosition -= glm::vec3(cos(VertAngle) * sin(HoriAngle),0,cos(VertAngle) * cos(HoriAngle))* KeyCameraSpeed;
      } else if( input_Direction == LEFT) {
          cameraPosition -= Right * KeyCameraSpeed;
      } else if( input_Direction == RIGHT) {
          cameraPosition += Right * KeyCameraSpeed;
      } else if(input_Direction == JUMP){
    	  cameraPosition += Up * KeyCameraSpeed;
      }	else if(input_Direction == CROUCH){
    	  cameraPosition -= Up * KeyCameraSpeed;
  }

///return of view matrix

 return glm::lookAt(cameraPosition, cameraPosition + Direction, Up);
}
