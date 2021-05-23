#include "TwoSidesPipe.h"

sf::Sprite TwoSidesPipe::create() const {
	return Pipe::create(PipeType::TwoSides);
}

