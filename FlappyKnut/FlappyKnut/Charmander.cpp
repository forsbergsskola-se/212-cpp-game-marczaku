#include "Charmander.h"

void Charmander::update() {
	if (patrollingDown) {
		yOffset++;
		image->y++;
		if (yOffset == maxOffset) {
			patrollingDown = false;
		}
	}
	else {
		yOffset--;
		image->y--;
		if (yOffset == minOffset) {
			patrollingDown = true;
		}
	}
}