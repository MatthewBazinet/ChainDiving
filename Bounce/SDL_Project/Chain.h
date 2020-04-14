#include "Spring.h"
class Chain {
private: 
	Spring chain[4];

public:
	Chain();
	Chain(Body* Body1, Body* Body2, Body* Body3, Body* Body4, Body* Body5);
	void Update(float deltaTime);
};
