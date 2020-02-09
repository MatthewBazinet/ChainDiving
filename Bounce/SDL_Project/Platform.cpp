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
	SDL_Rect OrigPlatform;
	OrigPlatform.x = pos.x;
	OrigPlatform.y = pos.y;
	OrigPlatform.w = width;
	OrigPlatform.h = height;
	Vec3 ScreenPos = projection * pos;
	Platform.x = static_cast<int>(ScreenPos.x);
	Platform.y = static_cast<int>(ScreenPos.y);
	Platform.w = width;
	Platform.h = height;
	//SDL_BlitSurface(SDL_Surface* src, OrigPlatform, surface, Platform); 
	//Put the surface image into src
	
}
