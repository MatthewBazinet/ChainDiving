#ifndef PLAYERCONTROLLER_H
#define PLAYERCONTROLLER_H

#include "Body.h"
#include "Ball.h"
#include "SDL.h"

class PlayerController
{
public:

	PlayerController();
	~PlayerController();

	void HandleEvents(const SDL_Event& event, Ball* body1, Ball* body2);
};

#endif // PLAYERCONTOLLER_H