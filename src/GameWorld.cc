#include "GameWorld.h"

using namespace std;

GameWorld::GameWorld (ApplicationMode mode) : asset_manager(std::make_shared<GameAssetManager>(mode)) {
asset_manager->AddAsset(std::make_shared<CubeAsset>(1, 1, 1));
asset_manager->AddAsset(std::make_shared<CubeAsset>(3, 1, 1));
asset_manager->AddAsset(std::make_shared<CubeAsset>(-1, 1, 1));
asset_manager->AddAsset(std::make_shared<CubeAsset>(-3, 1, 1));
asset_manager->AddAsset(std::make_shared<CubeAsset>(1, -1, 1));
asset_manager->AddAsset(std::make_shared<CubeAsset>(1, -3, 1));
asset_manager->AddAsset(std::make_shared<CubeAsset>(1, 1, -1));
asset_manager->AddAsset(std::make_shared<CubeAsset>(1, 1, -3));
}
 
float cam_x = 0.0;
float cam_y = 0.0;
 
glm::vec3 Cam_Pos = glm::vec3(0, 0, 0);
glm::vec3 Movement_Z;
glm::vec3 Movement_X;  
 
 
void GameWorld::Cam_Control(char key) {

        glm::vec3 Camera_Position = glm::vec3(0, 2, 0);
        glm::vec3 Movement_Z;
        glm::vec3 Movement_X;
		
   if ( key == 'w' ) {        // Pressing w moves you forward
         Cam_Pos =  Cam_Pos + Movement_Z;
  }
   if ( key == 'a' ) {        // Pressing a moves you left
         Cam_Pos = Cam_Pos - Movement_X;
  }
   if ( key == 's' ) {        // Pressing s moves you back
         Cam_Pos = Cam_Pos - Movement_Z;
  }
   if ( key == 'd' ) {        // Pressing d moves you right
         Cam_Pos = Cam_Pos + Movement_X;
  }
   if (key == '^') {
		cam_y += 0.5f * 0.1;
  }
   if (key == '<') {
		cam_x += 0.5f * 0.1;
  }
   if (key == 'v') {
		cam_y -= 0.5f * 0.1;
  }
   if (key == '>') {
		cam_x -= 0.5f * 0.1;
  }
 }
 
 void GameWorld::Draw() {
         asset_manager->Draw();
 
         glm::vec3 direction(
 		cos(cam_y) * sin(cam_x),
 		sin(cam_y),
 		cos(cam_y) * cos(cam_x)
 	);
 
 	glm::vec3 Movement_Direction(
 		1 * 0,
 		0,
 		1 * 1
 	);
 	Movement_Z = Movement_Direction;
 
 	Movement_X = glm::vec3(
 		sin(0.0 - 3.14f/2.0f),
 		0,
 		cos(0.0 - 3.14f/2.0f)
 	);
 
 	glm::vec3 vup = glm::cross(Movement_X, direction);
 	glm::mat4 Cam_Projection = glm::perspective(45.0f, 4.0f / 3.0f, 0.1f, 100.0f);
 	glm::mat4 Cam_View = glm::lookAt(
 		Cam_Pos,
 		Cam_Pos + direction,
 		vup
 	);
 	glm::mat4 Cam_Model(1.0f);
 
 	glUniformMatrix4fv(0, 1, GL_FALSE, &Cam_Projection[0][0]);
 	glUniformMatrix4fv(1, 1, GL_FALSE, &Cam_View[0][0]);
 	glUniformMatrix4fv(2, 1, GL_FALSE, &Cam_Model[0][0]);
 }
