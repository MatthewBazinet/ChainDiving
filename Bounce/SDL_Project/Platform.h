#ifndef PLATFORM_H
#define PLATFORM_H
#include "Body.h"
#include <SDL.h>
#include <SDL_image.h>
#include "Matrix.h"

class Platform : Body
{
	friend class Collider;
protected:
	int width;
	int height;
	SDL_Surface* image;
public:
	Platform();
	~Platform();
	Platform(Vec3 pos_, int width_, int height_);
	Platform::Platform(Vec3 pos_, int wh);
	void Update(const float deltaTime);
	void Render(SDL_Surface* surface, MATH::Matrix4 projection);
};
#endif

