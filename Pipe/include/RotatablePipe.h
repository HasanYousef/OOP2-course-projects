#pragma once

#include "Pipe.h"

class RotatablePipe : public Pipe
{
public:
	bool handleClick(const sf::Vector2f&);
	void rotatePipe(Rotate);
private:

};