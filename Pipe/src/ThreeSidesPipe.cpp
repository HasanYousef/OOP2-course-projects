#include "ThreeSidesPipe.h"

sf::Sprite ThreeSidesPipe::create() const {
	return Pipe::create(PipeType::ThreeSides);
}
