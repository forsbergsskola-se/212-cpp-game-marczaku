#pragma once

#include "GameObject.h"

class Pikachu : public GameObject
{
	int xOffset{};
	bool patrollingRight{ true };
public:
	Pikachu(Window* window) : GameObject{"img/pikachu.png", window}{ }
	Pikachu(Window* window, int x, int y) : GameObject{ "img/pikachu.png", window } {
		image->x = x;
		image->y = y;
	}
	void update() override;
};

