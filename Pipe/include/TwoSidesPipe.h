#pragma once

#include "Pipes.h"

class TwoSidesPipe : public Pipes {
public:
	TwoSidesPipe() : Pipes() {}
	TwoSidesPipe(sf::Vector2f&);
	sf::Sprite create() const;

private:

};
