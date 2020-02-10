#include "Platform.h"
#include "Matrix.h"
Platform::Platform()
{
	width = 0;
	height = 0;
	pos.x = 0.0f;
	pos.y = 0.0f;
	pos.z = 0.0f;

}

Platform::~Platform()
{
}
//Simple setting a new platform
Platform::Platform(Vec3 pos_, int width_, int height_)
{
	pos = pos_;
	width = width_;
	height = height_;
	image = IMG_Load("image.png");
	mass = 20;
}
Platform::Platform(Vec3 pos_, int wh) {
	pos = pos_;
	width = wh;
	height = wh;
}
void Platform::Update(const float deltaTime)
{} //Leaving as Stub Temporarily

//Take the renderer and a projection matrix to put Rect on screen
void Platform::Render(SDL_Surface* surface, Matrix4 projection)
{
	SDL_Rect Platform;
	
	Vec3 ScreenPos = projection * pos;
	SDL_Rect OrigPlatform;
	OrigPlatform.x = 0;
	OrigPlatform.y = 0;
	OrigPlatform.w = width * 8;
	OrigPlatform.h = height * 8;
	Platform.x = static_cast<int>(ScreenPos.x);
	Platform.y = static_cast<int>(ScreenPos.y);
	Platform.w = width * 8.02;
	Platform.h = height * 8.02;
	SDL_BlitSurface(image, &OrigPlatform, surface, &Platform); 
	//Put the surface image into src

}