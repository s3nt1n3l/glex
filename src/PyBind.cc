#include <boost/python.hpp>
#include "common.h"
#include "Camera.h"
#include "GameAssetManager.h"
#include "GameWorld.h"


using namespace boost::python;

PythonBindings::PythonBindings(){

}

BOOST_PYTHON_MODULE(glex){
	class_<Camera>("Camera")
			.def("Main", &Camera::Camera);
			.def("UpdateCameraPosition", &Camera::UpdateCameraPosition);
	class_<GameAssetManager>("GameAssetManager")
			.def("Main", &GameAssetManager::GameAssetManager);
			.def("Draw", &GameAssetManager::Draw);
	class_<GameWorld>("GameWorld")
			.def("Draw", &GameWorld::Draw);
			.def("UpdateCameraPosition", &GameWorld::UpdateCameraPosition);

}
