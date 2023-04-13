#pragma once
#include "GameObject.h"
class Charmander :
    public GameObject
{
	int yOffset{};
	bool patrollingDown{ true };
	int minOffset{ 0 };
	int maxOffset{ 200 };
public:
	Charmander(Window* window) : GameObject{ "img/charmander.png", window } { }
	Charmander(Window* window, int x, int y) : GameObject{ "img/charmander.png", window } { 
		image->x = x;
		image->y = y;
	}
	Charmander(Window* window, int x, int y, int minOffset, int maxOffset)
		: GameObject{ "img/charmander.png", window },
		minOffset{minOffset},
		maxOffset{ maxOffset } {
		image->x = x;
		image->y = y;
	}
	void update() override;
};

