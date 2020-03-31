#ifndef COLLIDER_H
#define COLLIDER_H

#include "Ball.h"
#include "Platform.h"
class Collider
{
public:
	Collider();
	~Collider();
	static bool SphereSphereCollision(const Body* body1, const Body* body2);
	static void SphereSphereCollisionResponse(Body* body1, Body* body2);
	static bool SphereBoxCollision(const Platform* rect, const Body* body);
	static void SphereBoxCollisionResponse(Platform* rect, Body* body);
};

#endif