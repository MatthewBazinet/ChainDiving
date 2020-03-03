#ifndef SCENE0_H
#define SCENE0_H

#include "MMath.h"
#include "Scene.h"
#include "Body.h"
#include "Ball.h"
#include <SDL.h>
#include "PlayerController.h"
#include "Platform.h"

using namespace MATH;
class Scene0 : public Scene {
private:
	SDL_Window *window;
	SDL_Renderer* renderer;
	Ball* ball[2];
	Platform* platforms[5];
	SDL_Surface* screenSurface;
	SDL_Surface* ballImage;
	Matrix4 projection;
	float timePassed;
	Collider* umer;
	PlayerController* pc;

	
public:
	Scene0(SDL_Window* sdlWindow);
	~Scene0();
	bool OnCreate() override;
	void OnDestroy() override;
	void Update(const float time) override;
	void Render() override;
	void handleEvents(const SDL_Event& event) override;
	
};

#endif

