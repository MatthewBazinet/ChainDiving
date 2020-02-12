#ifndef INPUTMANAGER_H
#define INPUTMANAGER_H

#include "Body.h"
#include "SDL.h"

class InputManager
{
private:
	static InputManager* sInstance;
	const Uint8* mKeyboardStates;

public:

	static InputManager* Instance();
	//static void Release();
	bool KeyDown(SDL_Scancode scanCode);
	bool KeyUp(SDL_Scancode scanCode);
	void Update();

	InputManager();
	~InputManager();
private:
};

#endif // INPUTMANAGER_H