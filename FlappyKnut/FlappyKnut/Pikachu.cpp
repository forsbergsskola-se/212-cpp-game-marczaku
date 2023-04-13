#include "Pikachu.h"
#include "Image.h"

void Pikachu::update() {
	if (patrollingRight) {
		xOffset++;
		image->x++;
		if (xOffset == 100) {
			patrollingRight = false;
		}
	}
	else {
		xOffset--;
		image->x--;
		if (xOffset == 0) {
			patrollingRight = true;
		}
	}
}