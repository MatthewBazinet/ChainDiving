#include "Ball.h"
#include <SDL_image.h>
#include "Scene0.h"

Ball::Ball():Body(Vec3(0.0f, 0.0f, 0.0f), Vec3(0.0f, 0.0f, 0.0f), Vec3(0.0f, 0.0f, 0.0f), 0.0f)
{
	ballImage = IMG_Load("ball.png");
}

Ball::Ball(Vec3 pos_, Vec3 vel_, Vec3 accel_, float mass_, float radius_, SDL_Surface* image):Body(pos_,vel_, accel_, mass_)
{
	ballImage = image; 
	radius = radius_;
}

bool Ball::OnCreate()
{
	return true;
}

void Ball::OnDestroy()
{
	SDL_FreeSurface(ballImage);
	SDL_FreeSurface(screenSurface);
}

void Ball::Update(float deltaTime)
{
	Body::Update(deltaTime);
}

void Ball::Update(float deltaTime, float timepassed) 
{
		Body::Update(deltaTime, timepassed);
	
}


void Ball::handleEvents(const SDL_Event& sdlevent)
{
}

void Ball::Render() const
{
	SDL_Rect dstrect;
	dstrect.x = static_cast<int>(ScreenPos.x);
	dstrect.y = static_cast<int>(ScreenPos.y);
	dstrect.w = 0;
	dstrect.h = 0;

	SDL_BlitSurface(ballImage, NULL, screenSurface, &dstrect);
}

void Ball::Render(SDL_Surface* screenSurface_,Matrix4 projection)
{
	screenSurface = screenSurface_;
	ScreenPos = projection * pos - Vec3(38.5f,38.5f,0.0f);
	Render();
}

Ball::~Ball()
{
}
