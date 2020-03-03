#ifndef BODY_H
#define BODY_H
#include "Vector.h"
using namespace MATH;
class Body
{
	friend class Collider;
protected:
	Vec3 pos, vel, accel;
	float mass;
	float radius;
	bool bouncedX;
	bool bouncedY;
	float hitTimeY;
	float hitTimeX;
public:
	Body();
	Body(Vec3 pos_, Vec3 vel_, Vec3 accel_, float mass);
	void Update(const float deltaTime);
	void Update(const float deltaTime, float timePassed);
	void ApplyForce(Vec3 force);
	Vec3 GetPos() const;
	Vec3 GetVel() const;
	void SetVel(Vec3 vel_);
	~Body();
};
#endif