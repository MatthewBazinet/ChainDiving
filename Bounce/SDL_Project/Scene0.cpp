#include "Scene0.h"
#include <SDL.h>
#include <SDL_image.h>
#include "Collider.h"
Scene0::Scene0(SDL_Window* sdlWindow_){
	window = sdlWindow_;
}

Scene0::~Scene0(){
}

bool Scene0::OnCreate() {
	//umer = new Collider();
	int w, h;
	SDL_GetWindowSize(window,&w,&h);

	pc = new PlayerController();
	Matrix4 ndc = MMath::viewportNDC(w,h);
	Matrix4 ortho = MMath::orthographic(0.0f, 50.0f, 0.0f, 100.0f, 0.0f, 1.0f);
	projection = ndc * ortho;
	
	timePassed = 0;

	ballImage = IMG_Load("ball.png");

    ball[0] = new Ball(Vec3(10.0f, 100.0f, 0.0f), Vec3(0.0f, 0.0f, 0.0f), Vec3(0.0f, -9.8f, 0.0f), 20.0f, 4.8f, ballImage);
	ball[1] = new Ball(Vec3(20.0f, 50.0f, 0.0f), Vec3(5.0f, 0.0f, 0.0f), Vec3(0.0f, -9.8f, 0.0f), 20.0f, 4.8f, ballImage);

	platforms[0] = new Platform(Vec3(10, 30, 0), 10, 10);
    renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);

	return true;
}

void Scene0::OnDestroy() 
{
	SDL_DestroyRenderer(renderer);
	SDL_FreeSurface(ballImage);
	for (int i = 0; i < 2; i++) {
		ball[i]->OnDestroy();
		delete ball[i];
		ball[i] = nullptr;
	}
}

void Scene0::Update(const float time) {


	if (Collider::SphereSphereCollision(ball[1], ball[0])) {
		Collider::SphereSphereCollisionResponse(ball[1], ball[0]);
	}		
	
	for(int i = 0; i < 2; i++) {
		if (Collider::SphereBoxCollision(platforms[0], ball[i])) {
			Collider::SphereBoxCollisionResponse(platforms[0], ball[i]);
		}
	ball[i]->Update(time, timePassed);
	}
	timePassed += time;
}

void Scene0::Render()
{
	screenSurface = SDL_GetWindowSurface(window);
	SDL_FillRect(screenSurface, nullptr, 0xffffffff);
	for (int i = 0; i < 2; i++) {
		ball[i]->Render(screenSurface, projection);
	}
	platforms[0]->Render(screenSurface, projection);
	SDL_UpdateWindowSurface(window);
}

void Scene0::handleEvents(const SDL_Event& event)
{
	pc->HandleEvents(event, ball[0], ball[1]);
}
