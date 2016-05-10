#ifndef BOUNDINGBOX_H
#define BOUNDINGBOX_H

#include <memory>
#include <iostream>
#include <utility>
#include <ostream>

#include <Vector> 
#include <GL/gl.h>
#include <glm/glm.hpp>
#include <glm/ext.hpp>

class BoundingBox{

	public:
	BoundingBox();

	// GetModel();
	
	void Scale();
	void Rotate();
	void CollisionD();

	void TranslateX();
	void TranslateY();
	void TranslateZ();

	bool TranslateCheck();
	bool RotationCheck
	bool ScaleCheck();
	
private:
	////////////
	bool Bscale;

	////////////
	bool BRotate 

	////////////
	bool BTranslate
	
};
#endif 
