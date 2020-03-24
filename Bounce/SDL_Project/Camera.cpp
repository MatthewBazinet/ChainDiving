#include "Camera.h"
#include "MMath.h"
#include "Matrix.h"

Camera::Camera() {
	
}

Camera::Camera(int width_, int height_)
{
	width = width_;
	height = height_;
	pos.x = 0.0f;
	pos.y = 0.0f;
	pos.z = 0.0f;
	mass = 0.0f;
}

Camera::~Camera() {}

void Camera::Render(SDL_Surface * surface, MATH::Matrix4 projection)
{
	SDL_Rect camera;

	Vec3 ScreenPos = projection * pos;
	SDL_Rect OrigPlatform;
	OrigPlatform.x = 0;
	OrigPlatform.y = 0;
	OrigPlatform.w = width * 8;
	OrigPlatform.h = height * 8;

	camera.x = static_cast<int>(ScreenPos.x);
	camera.y = static_cast<int>(ScreenPos.y);
	camera.w = width * 8.02;
	camera.h = height * 8.02;
	SDL_BlitSurface(NULL, &OrigPlatform, surface, &camera);
}

void Camera::SetY(int y_)
{
	pos.y += y_;
}

