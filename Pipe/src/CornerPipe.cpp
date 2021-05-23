#include "CornerPipe.h"

sf::Sprite CornerPipe::create() const {
	return Pipe::create(PipeType::Corner);
}
