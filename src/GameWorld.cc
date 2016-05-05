#include "GameWorld.h"

using namespace std;

GameWorld::GameWorld (ApplicationMode mode) : asset_manager(std::make_shared<GameAssetManager>(mode)) {
	asset_manager->AddAsset(std::make_shared<CubeAsset>(1, 1, 1));
	asset_manager->AddAsset(std::make_shared<CubeAsset>(-1, 1, 1));
	asset_manager->AddAsset(std::make_shared<CubeAsset>(-3, 1, 1));
	asset_manager->AddAsset(std::make_shared<CubeAsset>(1, -1, 1));
	asset_manager->AddAsset(std::make_shared<CubeAsset>(1, -3, 1));
	asset_manager->AddAsset(std::make_shared<CubeAsset>(1, 1, -1));
	asset_manager->AddAsset(std::make_shared<CubeAsset>(1, 1, -3));
	asset_manager->AddAsset(std::make_shared<CubeAsset>(1, -3, -3));
	asset_manager->AddAsset(std::make_shared<CubeAsset>(-3, 1, -3));
	asset_manager->AddAsset(std::make_shared<CubeAsset>(-3, -3, 1));
	asset_manager->AddAsset(std::make_shared<CubeAsset>(-3, -3, -3));
	asset_manager->AddAsset(std::make_shared<CubeAsset>(-3, -1, 1));
	asset_manager->AddAsset(std::make_shared<CubeAsset>(-3, -1, 1));
	asset_manager->AddAsset(std::make_shared<CubeAsset>(-1, -1, 1));
	asset_manager->AddAsset(std::make_shared<CubeAsset>(-1, -3, 1));
	asset_manager->AddAsset(std::make_shared<CubeAsset>(-3, 1, -1));
	asset_manager->AddAsset(std::make_shared<CubeAsset>(-1, 1, -3));
	asset_manager->AddAsset(std::make_shared<CubeAsset>(-3, -1, -1));
	asset_manager->AddAsset(std::make_shared<CubeAsset>(-1, -1, -1));
	asset_manager->AddAsset(std::make_shared<CubeAsset>(-1, 1, -1));
	asset_manager->AddAsset(std::make_shared<CubeAsset>(-1, -3, -1));
}
 
 void GameWorld::Draw() {
         asset_manager->Draw();

 }
 
 
/* void GameWorld::UpdateCameraPosition(Input input_Direction, float MouseX, float MouseY) {
   asset_manager->UpdateCameraPosition(input_Direction, MouseX, MouseY);
   }*/
