#include "PlayerController.h"

PlayerController::PlayerController()
{
}


PlayerController::~PlayerController()
{
}

void PlayerController::HandleEvents(const SDL_Event &event, Ball* body1, Ball* body2)
{
		if (event.type == SDL_KEYDOWN) {

			switch (event.key.keysym.sym) {
			case SDLK_d: //going right
				//body1->ApplyForce(Vec3(100.0f, 0.0f, 0.0f));
				body1->vel.x = 10;
				break;
			case SDLK_a: //going left
				//body1->ApplyForce(Vec3(-100.0f, 0.0f, 0.0f));
				body1->vel.x = -10;
				break;
			case  SDLK_w: //jumping
				body1->ApplyForce(Vec3(0.0f, 100.0f, 0.0f));
				//jumping method
				break;

				/*for the second character*/
			case SDLK_RIGHT:
				//body2->ApplyForce(Vec3(100.0f, 0.0f, 0.0f));
				body2->vel.x = 10;
				break;
			case SDLK_LEFT:

//body2->ApplyForce(Vec3(-100.0f, 0.0f, 0.0f));
				body2->vel.x = -10;
				break;

			case SDLK_UP:

				body2->ApplyForce(Vec3(0.0f, 100.0f, 0.0f));
				break;

			case SDLK_f: //intracting with objects
				break;
			default:
				break;
			}
			//This is for when the button released
			if (event.type == SDL_KEYUP) {
				switch (event.key.keysym.sym) {
				case SDLK_d:
					body1->ApplyForce(Vec3(0.0f, 0.0f, 0.0f));
					break;
				case SDLK_a: //going left
					body1->ApplyForce(Vec3(0.0f, 0.0f, 0.0f));
					break;
				case  SDLK_w: //jumping
					body1->ApplyForce(Vec3(0.0f, 0.0f, 0.0f));
					//jumping method
					break;

					/*for the second character*/
				case SDLK_RIGHT:
				
					body2->ApplyForce(Vec3(0.0f, 0.0f, 0.0f));
					break;

				case SDLK_LEFT:
					body2->ApplyForce(Vec3(0.0f, 0.0f, 0.0f));
					break;
				case SDLK_UP:
					body2->ApplyForce(Vec3(0.0f, 0.0f, 0.0f));
					break;
				case SDLK_f: //intracting with objects
					break;
				default:
					break;
				}
			}
		}
	}
