#pragma once

#include "Pipes.h"

class BowPipe : public Pipes
{
public:
	BowPipe() : Pipes() {}
	BowPipe(sf::Vector2f&);
	sf::Sprite create() const;

private:

};