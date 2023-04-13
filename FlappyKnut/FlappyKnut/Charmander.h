#pragma once
#include "GameObject.h"
class Charmander :
    public GameObject
{
	int i{};
	bool patrollingDown{ true };
public:
	Charmander(Window* window) : GameObject{ "img/charmander.png", window } { }
	Charmander(Window* window, int x) : GameObject{ "img/charmander.png", window } { 
		image->x = x;
	}
	void update() override;
};

