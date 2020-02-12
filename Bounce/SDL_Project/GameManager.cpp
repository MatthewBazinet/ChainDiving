#include "GameManager.h"
#include "Window.h"
#include "Timer.h"
#include "Scene0.h"
#include <iostream>
#include <SDL.h>
#include <SDL_image.h>

GameManager::GameManager() {
	timer = nullptr;
	isRunning = true;
	currentScene = nullptr;

	mInputMgr = InputManager::Instance();
}


/// In this OnCreate() method, fuction, subroutine, whatever the word, 
bool GameManager::OnCreate() {
	const int SCREEN_WIDTH = 400;
	const int SCREEN_HEIGHT = 800;
	ptr = new Window(SCREEN_WIDTH, SCREEN_HEIGHT);
	if (ptr == nullptr) {
		OnDestroy();
		return false;
	}
	if (ptr->OnCreate() == false) {
		OnDestroy();
		return false;
	}

	timer = new Timer();
	if (timer == nullptr) {
		OnDestroy();
		return false;
	}

	if (!IMG_Init(IMG_INIT_JPG | IMG_INIT_PNG)) {
		OnDestroy();
		return false;
	}

	currentScene = new Scene0(ptr->GetSDL_Window());
	if (currentScene == nullptr) {
		OnDestroy();
		return false;
	}

	if (currentScene->OnCreate() == false) {
		OnDestroy();
		return false;
	}

	return true;
}

/// Here's the whole game
void GameManager::Run() {
	timer->Start();
	while (isRunning) {
		/*mInputMgr->Update();

		if (mInputMgr->KeyDown(SDL_SCANCODE_W)) {
			//ball.ApplyForce(Vec3(0.0f, 100.0f, 0.0f) * timer->GetDeltaTime());
			printf("W Key Pressed \n");
		}

		if (mInputMgr->KeyUp(SDL_SCANCODE_W)) {
			printf("W Key Released \n");
		}*/

		timer->UpdateFrameTicks();
		currentScene->Update(timer->GetDeltaTime());
		currentScene->Render();
		handleEvents();

		/// Keeep the event loop running at a proper rate
		SDL_Delay(timer->GetSleepTime(120)); ///120 frames per sec
	}
}

void GameManager::handleEvents() {
	SDL_Event sdlEvent;
	while (SDL_PollEvent(&sdlEvent)) {
		switch (sdlEvent.type) {
			case SDL_KEYDOWN:
				switch (sdlEvent.key.keysym.sym) {
					case SDLK_w:
						ball[0]->ApplyForce(Vec3(0.0f, 5.0f, 0.0f));
						printf("W Key Pressed \n");
						break;
					case SDLK_d:
						ball[0]->ApplyForce(Vec3(5.0f, 0.0f, 0.0f));
						printf("D Key Pressed \n");
						break;
					case SDLK_RIGHT:
						ball[1]->ApplyForce(Vec3(5.0f, 0.0f, 0.0f));
						printf("Right Aroow Key Pressed \n");
						break;
					default:
						break;
				}
				break;
				
			case SDL_KEYUP:
				switch (sdlEvent.key.keysym.sym)
				{
					case SDLK_w:
						ball[0]->ApplyForce(Vec3(0.0f, 0.0f, 0.0f));
						printf("W Key Released \n");
						break;
					case SDLK_d:
						ball[0]->ApplyForce(Vec3(0.0f, 0.0f, 0.0f));
						printf("D Key Released \n");
						break;
					case SDLK_RIGHT:
						ball[1]->ApplyForce(Vec3(5.0f, 0.0f, 0.0f));
						printf("Right Aroow Key Released \n");
						break;
					default:
						break;
				}
				break;
		}
		//printf("%d\n", sdlEvent.type);
		if (sdlEvent.type == SDL_QUIT) {
			isRunning = false;
		}
		else {
			//currentScene->handleEvents(sdlEvent);
		}
	}
}

GameManager::~GameManager() {
	//InputManager::Release();
	//mInputMgr = NULL;
}

void GameManager::OnDestroy(){
	if (ptr) delete ptr;
	if (timer) delete timer;
	if (currentScene) delete currentScene;
}