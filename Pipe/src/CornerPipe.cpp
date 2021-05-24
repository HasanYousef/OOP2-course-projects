#include "CornerPipe.h"

//------------------------------------------
sf::Sprite CornerPipe::create() const {
	return Pipe::create(PipeType::Corner);
}

//------------------------------------------
bool CornerPipe::canConnect(char way) const {
	switch (getRotateDeg()) { //READ THE COMMENT BELLOW
	case 1: //TOP
		if (way == TOP || way == RIGHT) {
			return true;
		}
		break;
	case 2: //RIGHT
		if (way == RIGHT || way == BOTTOM) {
			return true;
		}
		break;
	case 3: //BOTTOM
		if (way == BOTTOM || way == LEFT) {
			return true;
		}
		break;
	case 4: //LEFT
		if (way == LEFT || way == TOP) {
			return true;
		}
		break;
	}
	return false;
}
/*
       |
TOP	   |
	   -----

	   _____
RIGHT  |
	   |

	   _____
	       |
DOWN	   |

            |
LEFT		|
       ------
*/