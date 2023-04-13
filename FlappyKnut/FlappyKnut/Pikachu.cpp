#include "Pikachu.h"
#include "Image.h"

void Pikachu::update() {
	if (patrollingRight) {
		i++;
		if (i == 100) {
			patrollingRight = false;
		}
	}
	else {
		i--;
		if (i == 0) {
			patrollingRight = true;
		}
	}
	image->x = i;
}