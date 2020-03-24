#include "Scene0.h"
#include <SDL.h>
#include <SDL_image.h>
#include "Collider.h"
#include "Camera.h"

Scene0::Scene0(SDL_Window* sdlWindow_) {
	window = sdlWindow_;
}

Scene0::~Scene0() {
}

bool Scene0::OnCreate() {
	camera = new Camera();

	//umer = new Collider();
	int w, h;
	SDL_GetWindowSize(window, &w, &h);

	pc = PlayerController();
	Matrix4 ndc = MMath::viewportNDC(w, h);
	Matrix4 ortho = MMath::orthographic(0.0f, 50.0f, 0.0f, 100.0f, 0.0f, 1.0f);
	projection = ndc * ortho;

	timePassed = 0;

	ballImage = IMG_Load("ball.png");

	ball[0] = new Ball(Vec3(10.0f, 90.0f, 0.0f), Vec3(0.0f, 0.0f, 0.0f), Vec3(0.0f, -9.8f, 0.0f), 20.0f, 4.8f, ballImage);
	ball[1] = new Ball(Vec3(20.0f, 50.0f, 0.0f), Vec3(5.0f, 0.0f, 0.0f), Vec3(0.0f, -9.8f, 0.0f), 20.0f, 4.8f, ballImage);
	ball[2] = new Ball(Vec3(30.0f, 25.0f, 0.0f), Vec3(-1.0f, 0.0f, 0.0f), Vec3(0.0f, -9.8f, 0.0f), 20.0f, 4.8f, ballImage);
	ball[3] = new Ball(Vec3(30.0f, 90.0f, 0.0f), Vec3(2.0f, 0.0f, 0.0f), Vec3(0.0f, -9.8f, 0.0f), 20.0f, 4.8f, ballImage);
	ball[4] = new Ball(Vec3(10.0f, 10.0f, 0.0f), Vec3(-3.0f, 0.0f, 0.0f), Vec3(0.0f, -9.8f, 0.0f), 20.0f, 4.8f, ballImage);

	platforms[0] = new Platform(Vec3(10, 30, 0), 10, 10);

	killBorder[0] = new Platform(Vec3(0, 3, 0), 50, 2, "kill"); //Bottom
	killBorder[1] = new Platform(Vec3(0, 97, 0), 50, 2, "kill"); //Top
	killBorder[2] = new Platform(Vec3(0, 95, 0), 2, 105, "kill"); //Left
	killBorder[3] = new Platform(Vec3(48, 95, 0), 2, 105, "kill"); //Right

	renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);

	return true;
}

void Scene0::OnDestroy()
{
	SDL_DestroyRenderer(renderer);
	SDL_FreeSurface(ballImage);
	for (int i = 0; i < 5; i++) {
		ball[i]->OnDestroy();
		delete ball[i];
		ball[i] = nullptr;
	}
}

void Scene0::Update(const float time) {

	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < 4; j++) {
			if (i != j) {
				if (Collider::SphereSphereCollision(ball[i], ball[j])) {
					Collider::SphereSphereCollisionResponse(ball[i], ball[j]);
				}
			}
		}
	}
	for (int i = 0; i < 5; i++) {
		if (Collider::SphereBoxCollision(platforms[0], ball[i])) {
			Collider::SphereBoxCollisionResponse(platforms[0], ball[i]);
		}
		ball[i]->Update(time, timePassed);
	}
	//Kill Border 1
	for (int i = 0; i < 5; i++) {
		if (Collider::SphereBoxCollision(killBorder[0], ball[i])) {
			Collider::SphereBoxCollisionResponse(killBorder[0], ball[i]);
			OnCreate();
		}
		//ball[i]->Update(time, timePassed);
	}
	//Kill Border 2
	for (int i = 0; i < 5; i++) {
		if (Collider::SphereBoxCollision(killBorder[1], ball[i])) {
			Collider::SphereBoxCollisionResponse(killBorder[1], ball[i]);
			OnCreate();
		}
		//ball[i]->Update(time, timePassed);
	}
	//Kill Border 3
	for (int i = 0; i < 5; i++) {
		if (Collider::SphereBoxCollision(killBorder[2], ball[i])) {
			Collider::SphereBoxCollisionResponse(killBorder[2], ball[i]);
			OnCreate();
		}
		//ball[i]->Update(time, timePassed);
	}
	//Kill Border 4
	for (int i = 0; i < 5; i++) {
		if (Collider::SphereBoxCollision(killBorder[3], ball[i])) {
			Collider::SphereBoxCollisionResponse(killBorder[3], ball[i]);
			OnCreate();
		}
		//ball[i]->Update(time, timePassed);
	}
	SDL_Event sdlEvent;
	while (SDL_PollEvent(&sdlEvent)) {
		switch (sdlEvent.type) {
		case SDL_KEYDOWN:
			case SDLK_h:
				printf("Reset Button pressed\n");
				OnCreate();
			default:
				break;
			}
		break;
	}
	camera->SetY(100);
	timePassed += time;
}

void Scene0::Render()
{
	screenSurface = SDL_GetWindowSurface(window);
	SDL_FillRect(screenSurface, nullptr, 0xffffffff);
	for (int i = 0; i < 5; i++) {
		ball[i]->Render(screenSurface, projection);
	}
	platforms[0]->Render(screenSurface, projection);
	killBorder[0]->Render(screenSurface, projection);
	killBorder[1]->Render(screenSurface, projection);
	killBorder[2]->Render(screenSurface, projection);
	killBorder[3]->Render(screenSurface, projection);
	camera->Render(screenSurface, projection);
	SDL_UpdateWindowSurface(window);
}

void Scene0::handleEvents(SDL_Event* sdlEvent)
{
	pc.event = sdlEvent;
}