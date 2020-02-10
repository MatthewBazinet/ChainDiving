#include "Scene0.h"
#include <SDL.h>
#include <SDL_image.h>
#include "Collider.h"
#include "GameManager.h"
Scene0::Scene0(SDL_Window* sdlWindow_){
	window = sdlWindow_;
}

Scene0::~Scene0(){
}

bool Scene0::OnCreate() {
	//umer = new Collider();
	int w, h;
	SDL_GetWindowSize(window,&w,&h);

	Matrix4 ndc = MMath::viewportNDC(w,h);
	Matrix4 ortho = MMath::orthographic(0.0f, 50.0f, 0.0f, 100.0f, 0.0f, 1.0f);
	projection = ndc * ortho;
	
	timePassed = 0;

	ballImage = IMG_Load("ball.png");

    ball[0] = new Ball(Vec3(10.0f, 100.0f, 0.0f), Vec3(10.0f, 0.0f, 0.0f), Vec3(0.0f, -9.8f, 0.0f), 10.0f, 4.8f, ballImage);
	//ball[1] = new Ball(Vec3(20.0f, 50.0f, 0.0f), Vec3(5.0f, 0.0f, 0.0f), Vec3(0.0f, -9.8f, 0.0f), 10.0f, 4.8f, ballImage);
	//ball[2] = new Ball(Vec3(30.0f, 25.0f, 0.0f), Vec3(-1.0f, 0.0f, 0.0f), Vec3(0.0f, -9.8f, 0.0f), 10.0f, 4.8f, ballImage);
	//ball[3] = new Ball(Vec3(30.0f, 100.0f, 0.0f), Vec3(2.0f, 0.0f, 0.0f), Vec3(0.0f, -9.8f, 0.0f), 10.0f, 4.8f, ballImage);
	//ball[4] = new Ball(Vec3(10.0f, 10.0f, 0.0f), Vec3(-3.0f, 0.0f, 0.0f), Vec3(0.0f, -9.8f, 0.0f), 10.0f, 4.8f, ballImage);

    renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);

	return true;
}

void Scene0::OnDestroy() 
{
	SDL_DestroyRenderer(renderer);
	SDL_FreeSurface(ballImage);
	for (int i = 0; i < 1; i++) {
		ball[i]->OnDestroy();
		delete ball[i];
		ball[i] = nullptr;
	}
}

void Scene0::Update(const float time) {

	for (int i = 0; i < 1; i++) {
		for (int j = 0; j < 1; j++) {
			if (i != j) {
				if (Collider::SphereSphereCollision(ball[i], ball[j])) {
					Collider::SphereSphereCollisionResponse(ball[i], ball[j]);
				}
			}
		}
	}
	for (int i = 0; i < 1; i++) {
	ball[i]->Update(time, timePassed);
	}
	timePassed += time;
}

void Scene0::Render()
{
	screenSurface = SDL_GetWindowSurface(window);
	SDL_FillRect(screenSurface, nullptr, 0xffffffff);
	for (int i = 0; i < 1; i++) {
		ball[i]->Render(screenSurface, projection);
	}

	SDL_UpdateWindowSurface(window);
}