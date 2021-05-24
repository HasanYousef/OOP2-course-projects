#pragma once

#include "PumperPipe.h"

sf::Sprite PumperPipe::create() const {
	return Pipe::create(PipeType::Pumper);
}

bool PumperPipe::canConnect(char way) const {
	switch (getRotateDeg()) {
	case 1:
		if (way == TOP) {
			return true;
		}
		break;
	case 2:
		if (way == RIGHT) {
			return true;
		}
		break;
	case 3:
		if (way == BOTTOM) {
			return true;
		}
		break;
	case 4:
		if (way == LEFT) {
			return true;
		}
		break;
	}
	return false;
}
