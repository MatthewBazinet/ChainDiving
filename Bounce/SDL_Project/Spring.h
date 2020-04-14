#include "Body.h"
class Spring {
public:
	Body* body1;
	Body* body2;
	float springConstant;
	float springLength;
	float frictionConstant;
	Spring() {
		this->springConstant = 1.0f;
		this->springLength = 1.0f;               
		this->frictionConstant = 1.0f;           
		this->body1 = new Body(Vec3(0.0f, 0.0f, 0.0f), Vec3(0.0f, 0.0f, 0.0f), Vec3(0.0f, 0.0f, 0.0f), 1.0f);
		this->body2 = new Body(Vec3(0.0f,0.0f,0.0f), Vec3(0.0f, 0.0f, 0.0f), Vec3(0.0f, 0.0f, 0.0f), 1.0f);
	}
	Spring(Body* body1, Body* body2, float springConstant, float springLength, float frictionConstant)
	{
		this->springConstant = springConstant;               // Set The springConstant
		this->springLength = springLength;               // Set The springLength
		this->frictionConstant = frictionConstant;           // Set The frictionConstant
		this->body1 = body1;                     // Set body1
		this->body2 = body2;                     // Set body2
	}
	Spring(Body* body1, Body* body2) {
		this->body1 = body1;
		this->body2 = body2;
		//These variables will need to be tweaked
		this->springConstant = 0.07f;             
		this->springLength = 5.0f;           
		this->frictionConstant = 0.05f;
	}
	void Solve() {
		Vec3 SpringVector = body1->GetPos() - body2->GetPos(); //Vector between the two
		float distance = sqrt(pow(body2->GetPos().x - body1->GetPos().x, 2) + pow(body2->GetPos().y - body1->GetPos().y, 2) + pow(body2->GetPos().z - body1->GetPos.z, 2));
		Vec3 Force;
		if (distance != 0) { //This is to avoid division by 0 
			Force += -(SpringVector / distance) * (distance - springLength) * springConstant; //the main force
			Force += -(body1->GetVel() - body2->GetVel()) * frictionConstant; //The friction force added on
			body1->ApplyForce(Force);
			body2->ApplyForce(-Force);
		};
	};
};

