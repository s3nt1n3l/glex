#include <boost/python.hpp>
#include "common.h"
#include "Camera.h"


using namespace boost::python;

PythonBindings::PythonBindings(){

}

BOOST_PYTHON_MODULE(libglex){
	class_<Camera>("Camera")
				.def("CameraSpeed", &Camera::Camera);

}
