#pragma once

#include "PumperPipe.h"

sf::Sprite PumperPipe::create() const {
	return Pipe::create(PipeType::Pumper);
}