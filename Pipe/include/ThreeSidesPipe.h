#pragma once

#include "Pipes.h"

class ThreeSidesPipe : public Pipes
{
public:
	ThreeSidesPipe() : Pipes() {}
	ThreeSidesPipe(sf::Vector2f&);
	sf::Sprite create() const;

private:

};
