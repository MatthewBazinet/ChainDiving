
#ifndef PLAYERCONTROLLER_H
#define PLAYERCONTROLLER_H

#include "Body.h"
#include "SDL.h"

class PlayerController
{
public:
	SDL_Event* event;
	Body* body;

	PlayerController();
	~PlayerController();

	void Update();
	void HandleEvents();
};

#endif // PLAYERCONTOLLER_H