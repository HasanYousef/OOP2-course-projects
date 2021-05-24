#include "TwoSidesPipe.h"

sf::Sprite TwoSidesPipe::create() const {
	return Pipe::create(PipeType::TwoSides);
}

bool TwoSidesPipe::canConnect(char way) const {
	int deg = getRotateDeg();
	if ((deg == 1 || deg == 3) &&
		(way == TOP || way == BOTTOM)) {
		return true;
	}
	if ((deg == 2 || deg == 4) &&
		(way == LEFT || way == RIGHT)) {
		return true;
	}
	return false;
}

