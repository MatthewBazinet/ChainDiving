#include "Chain.h"

Chain::Chain() {
	Body* temp = new Body(Vec3(0.0f, 0.0f, 0.0f), Vec3(0.0f, 0.0f, 0.0f), Vec3(0.0f, 0.0f, 0.0f), 1.0f);
	chain[0] = Spring(temp, temp); //Zero Argument Constructors
	chain[1] = Spring(temp, temp);
	chain[2] = Spring(temp, temp);
	chain[3] = Spring(temp, temp);
}
Chain::Chain(Body* Body1, Body* Body2, Body* Body3, Body* Body4, Body* Body5) {
	chain[0] = Spring(Body1, Body2); //Make 4 springs between the 5 bodies 
	chain[1] = Spring(Body2, Body3);
	chain[2] = Spring(Body3, Body4);
	chain[3] = Spring(Body4, Body5);
}

void Chain::Update(float deltaTime)
{
	for (int i = 0; i < 4; i++) {
		chain[i].Solve(); //Call Spring's Solve to change the force they apply 
	}
		chain[0].body1->Update(deltaTime); //Calls each of the Bodies' updates
		chain[1].body1->Update(deltaTime);
		chain[2].body1->Update(deltaTime);
		chain[3].body1->Update(deltaTime);
		chain[3].body2->Update(deltaTime);
}
