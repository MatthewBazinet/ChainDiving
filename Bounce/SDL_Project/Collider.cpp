#include "Collider.h"
#include "VMath.h"
Collider::Collider()
{
}
Collider::~Collider()
{
}

bool Collider::SphereSphereCollision(const Body* body1, const Body *body2)
{
	float distance = sqrt(pow(body2->pos.x - body1->pos.x, 2) + pow(body2->pos.y - body1->pos.y, 2) + pow(body2->pos.z - body1->pos.z, 2));
	if (distance < body1->radius + body2->radius) {
		return true;
	}
	else {
		return false;
	}
}

void Collider::SphereSphereCollisionResponse(Body* body1, Body* body2)
{
	float e = 1.0f;//0.99f;
	Vec3 lineOfAction = body1->pos - body2->pos;
	Vec3 normalizedLineOfAction = lineOfAction / (sqrt(lineOfAction.x * lineOfAction.x + lineOfAction.y * lineOfAction.y + lineOfAction.z * lineOfAction.z));
	float v1p = VMath::dot(normalizedLineOfAction, body1->vel);
	float v2p = VMath::dot(normalizedLineOfAction, body2->vel);

	if (v1p - v2p > 0.0f) return;

	float v1pnew = (((body1->mass - e * body2->mass) * v1p) + ((1.0f + e) * body2->mass * v2p) / (body1->mass + body2->mass));
	float v2pnew = (((body2->mass - e * body1->mass) * v2p) + ((1.0f + e) * body1->mass * v1p) / (body1->mass + body2->mass));

	body1->vel += (v1pnew - v1p) * normalizedLineOfAction;
	body2->vel += (v2pnew - v2p) * normalizedLineOfAction;
}

bool Collider::SphereBoxCollision(const Platform* rect, const Body* body)
{
	Vec3 distance;
	distance.x = abs(body->GetPos().x - (rect->GetPos().x + rect->width / 2));  // circle is x away from rect center on horizontal axis
	distance.y = abs(body->GetPos().y - (rect->GetPos().y - rect->height / 2));  // circle is y away from rect center on verticle axis
	if (distance.x > (rect->width / 2 + body->radius)) { return false; } // too far on x axis
	if (distance.y > (rect->height / 2 + body->radius)) { return false; } // too far on y axis

	if (distance.x <= (rect->width / 2)) { return true; }
	if (distance.y <= (rect->height / 2)) { return true; }

	float cDist_sq = pow(distance.x - rect->width / 2, 2) + pow(distance.y - rect->height / 2, 2);

	if (cDist_sq <= (body->radius*body->radius)) {
		//collision detected
		return true;
	}
}

void Collider::SphereBoxCollisionResponse(Platform* rect, Body* body)
{
	Vec3 up = Vec3(0.0f, 1.0f, 0.0f);
	float updot = VMath::dot(up, VMath::normalize(body->vel));
	if (updot < cos(90)) {
		body->vel.y = 0.0f;
	}
	else if (updot > cos(180)) {
		body->vel.x *= -1;
	}
	else {
		body->vel.y *= -1;
	}



}