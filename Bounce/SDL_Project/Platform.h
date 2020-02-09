#include "Body.h"
#include <SDL.h>
#include "Matrix.h"
class Platform : Body
{
private:
	int width;
	int height;
public:
	Platform();
	~Platform();
	Platform(Vec3 pos_, int width_, int height_);
	Platform::Platform(Vec3 pos_, int wh);
	void Update(const float deltaTime);
	void Render(SDL_Surface* surface, MATH::Matrix4 projection);
};

