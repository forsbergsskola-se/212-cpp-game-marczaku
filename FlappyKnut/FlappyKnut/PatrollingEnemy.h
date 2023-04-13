#pragma once
#include "GameObject.h"
class PatrollingEnemy :
	public GameObject
{
	int yOffset{};
	int patrollingX{ 1 };
	int patrollingY{ 1 };
	int minOffset{ 0 };
	int maxOffset{ 200 };
public:
	PatrollingEnemy(Window* window) : GameObject{ "img/charmander.png", window } { }
	PatrollingEnemy(Window* window, int x, int y) : GameObject{ "img/charmander.png", window } {
		image->x = x;
		image->y = y;
	}
	PatrollingEnemy(Window* window, int x, int y, int minOffset, int maxOffset)
		: GameObject{ "img/charmander.png", window },
		minOffset{ minOffset },
		maxOffset{ maxOffset } {
		image->x = x;
		image->y = y;
	}
	void update() override;
};

