#ifndef CAMERA_H
#define CAMERA_H
#include "Body.h"
#include <SDL.h>
#include "Matrix.h"

class Camera : Body{
private:
	int width;
	int height;
	
public:
	Camera();
	Camera(int width_, int height_);
	~Camera();
	void Render(SDL_Surface* surface, MATH::Matrix4 projection);
	void SetY(int y_);
};

#endif



