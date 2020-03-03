#include "Body.h"
#include <iostream>

Body::Body()
{
	Body(Vec3(0.0f, 0.0f, 0.0f), Vec3(0.0f, 0.0f, 0.0f), Vec3(0.0f, 0.0f, 0.0f), 0.0f);
}

Body::Body(Vec3 pos_, Vec3 vel_, Vec3 accel_, float mass_)
{
	pos.x = pos_.x;
	pos.y = pos_.y;
	pos.z = pos_.z;

	vel.x = vel_.x;
	vel.y = vel_.y;
	vel.z = vel_.z;

	accel.x = accel_.x;
	accel.y = accel_.y;
	accel.z = accel_.z;
	mass = mass_;
}

Body::~Body()
{
}

void Body::Update(const float deltaTime)
{
	printf("%f %f %f\n", pos.x, vel.x, accel.x);
	pos.x += vel.x * deltaTime + 0.5f * accel.x * deltaTime * deltaTime;
	vel.x += accel.x * deltaTime;
	pos.y += vel.y * deltaTime + 0.5f * accel.y * deltaTime * deltaTime;
	vel.y += accel.y * deltaTime;
	pos.z += vel.z * deltaTime + 0.5f * accel.z * deltaTime * deltaTime;
	vel.z += accel.z * deltaTime;

}

void Body::Update(const float deltaTime, float timePassed)
{
	printf("%f %f %f\n", pos.x, vel.x, accel.x);
	pos.x += vel.x * deltaTime + 0.5f * accel.x * deltaTime * deltaTime;
	vel.x += accel.x * deltaTime;
	pos.y += vel.y * deltaTime + 0.5f * accel.y * deltaTime * deltaTime;
	vel.y += accel.y * deltaTime;
	pos.z += vel.z * deltaTime + 0.5f * accel.z * deltaTime * deltaTime;
	vel.z += accel.z * deltaTime;

	if (pos.y < 4 && !bouncedY) {
		vel = Vec3(vel.x, vel.y * -0.99, 0.0f);
		bouncedY = true;
		hitTimeY = timePassed;
	}
	if (hitTimeY + 0.01f < (timePassed)) {
		bouncedY = false;
	}

	if ((pos.x < 4.2 || pos.x > 45.8) && !bouncedX) {
		vel = Vec3(vel.x * -0.99, vel.y, 0.0f);
		bouncedX = true;
		hitTimeX = timePassed;
	}
	if (hitTimeX + 0.01f < (timePassed)) {
		bouncedX = false;
	}

}

void Body::ApplyForce(Vec3 force)
{
	accel.x += force.x / mass;
	accel.y += force.y / mass;
	accel.z += force.z / mass;
}

Vec3 Body::GetPos() const {
	return pos;
}

Vec3 Body::GetVel() const {
	return vel;
}

void Body::SetVel(Vec3 vel_) {
	vel = vel_;
}