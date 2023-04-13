#pragma once

#include "GameObject.h"

class Pikachu : public GameObject
{
	int i{};
	bool patrollingRight{ true };
public:
	Pikachu(Window* window) : GameObject{"img/pikachu.png", window}{ }
	void update() override;
};

