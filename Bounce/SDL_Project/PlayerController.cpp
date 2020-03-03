#include "PlayerController.h"

PlayerController::PlayerController()
{
}


PlayerController::~PlayerController()
{
}

void PlayerController::Update()
{
	if (event != nullptr) {
		if (event->type == SDL_KEYDOWN) {

			switch (event->key.keysym.sym) {
			case SDLK_d: //going right
				body->ApplyForce(Vec3(100.0f, 0.0f, 0.0f));
				break;
			case SDLK_a: //going left
				body->ApplyForce(Vec3(-100.0f, 0.0f, 0.0f));
				break;
			case  SDLK_w: //jumping
				body->ApplyForce(Vec3(0.0f, 100.0f, 0.0f));
				//jumping method
				break;
			case SDLK_RIGHT:
				/*for the second character
				body2.ApplyForce(Vec3(100.0f, 0.0f, 0.0f));
				break;
				*/
			case SDLK_LEFT:
				/*for the second character
				body2.ApplyForce(Vec3(-100.0f, 0.0f, 0.0f));
				break;
				*/
			case SDLK_UP:
				/*for the second character
				body2.ApplyForce(Vec3(0.0f, 100.0f, 0.0f));
				break;
				*/
			case SDLK_f: //intracting with objects
				break;
			default:
				break;
			}
			//This is for when the button released
			if (event->type == SDL_KEYUP) {
				switch (event->key.keysym.sym) {
				case SDLK_d:
					body->ApplyForce(Vec3(0.0f, 0.0f, 0.0f));
					break;
				case SDLK_a: //going left
					body->ApplyForce(Vec3(0.0f, 0.0f, 0.0f));
					break;
				case  SDLK_w: //jumping
					body->ApplyForce(Vec3(0.0f, 0.0f, 0.0f));
					//jumping method
					break;
				case SDLK_RIGHT:
					/*for the second character
					body2.ApplyForce(Vec3(0.0f, 0.0f, 0.0f));
					break;
					*/
				case SDLK_LEFT:
					/*for the second character
					body2.ApplyForce(Vec3(0.0f, 0.0f, 0.0f));
					break;
					*/
				case SDLK_UP:
					/*for the second character
					body2.ApplyForce(Vec3(0.0f, 0.0f, 0.0f));
					break;
					*/
				case SDLK_f: //intracting with objects
					break;
				default:
					break;
				}
			}
		}
	}
}