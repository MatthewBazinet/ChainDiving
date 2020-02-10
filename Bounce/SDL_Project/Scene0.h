#ifndef SCENE0_H
#define SCENE0_H

#include "MMath.h"
#include "Scene.h"
#include "Body.h"
#include "Ball.h"
#include <SDL.h>
#include "GameManager.h"

using namespace MATH;
class Scene0 : public Scene {
private:
	SDL_Window *window;
	SDL_Renderer* renderer;
	Ball* ball[5];
	SDL_Surface* screenSurface;
	SDL_Surface* ballImage;
	Matrix4 projection;
	float timePassed;
	Collider* umer;
	GameManager *gameManager;
	

	
public:
	Scene0(SDL_Window* sdlWindow);
	~Scene0();
	bool OnCreate();
	void OnDestroy();
	void Update(const float time);
	void Render();
	
};

#endif

