#ifndef BALL_H
#define BALL_H
#include "GameObject.h"
#include "MMath.h"
#include "Body.h"
class Ball : public GameObject, public Body
{
	friend class Collider;
public:
	Ball();
	Ball(Vec3 pos_, Vec3 vel_, Vec3 accel_, float mass_, float radius_, SDL_Surface* image);
	bool OnCreate();
	void OnDestroy();
	void Update(const float deltaTime);
	void Update(float deltaTime, float timepassed);
	void handleEvents(const SDL_Event& sdlevent);
	void Render()const;
	void Render(SDL_Surface* screenSurface_, Matrix4 projection);
	~Ball();
	
private:
	SDL_Surface* ballImage;
	SDL_Surface* screenSurface;
	Vec3 ScreenPos;
};
#endif
