#include "ReceiverPipe.h"

sf::Sprite ReceiverPipe::create() const {
	return Pipe::create(PipeType::Receiver);
}