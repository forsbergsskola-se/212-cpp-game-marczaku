#include "Charmander.h"

void Charmander::update() {
	if (patrollingDown) {
		i++;
		if (i == 200) {
			patrollingDown = false;
		}
	}
	else {
		i--;
		if (i == 0) {
			patrollingDown = true;
		}
	}
	image->y = i;
}