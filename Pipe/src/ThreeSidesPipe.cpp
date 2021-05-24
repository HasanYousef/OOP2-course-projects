#include "ThreeSidesPipe.h"

//------------------------------------------
sf::Sprite ThreeSidesPipe::create() const {
	return Pipe::create(PipeType::ThreeSides);
}

//------------------------------------------
bool ThreeSidesPipe::canConnect(char way) const {
	switch (getRotateDeg()) { //READ THE COMMENT BELLOW
	case 1: //TOP
		if (way == BOTTOM) {
			return false;
		}
		break;
	case 2: //RIGHT
		if (way == LEFT) {
			return false;
		}
		break;
	case 3: //BOTTOM
		if (way == TOP) {
			return false;
		}
		break;
	case 4: //LEFT
		if (way == RIGHT) {
			return false;
		}
		break;
	}
	return true;
}
