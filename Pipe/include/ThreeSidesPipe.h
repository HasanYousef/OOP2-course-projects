#pragma once

#include "Pipe.h"

class ThreeSidesPipe : public Pipe
{
public:
	ThreeSidesPipe() : Pipe() {}
	ThreeSidesPipe(sf::Vector2f&);
	sf::Sprite create() const;

private:

};
