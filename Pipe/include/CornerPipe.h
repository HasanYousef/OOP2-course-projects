#pragma once

#include "RotatablePipe.h"

class CornerPipe : public RotatablePipe {
public:
	CornerPipe() : RotatablePipe() {};
	CornerPipe(sf::Vector2f& point, int rotDeg) :
		RotatablePipe(point, rotDeg) {}
	sf::Sprite create() const;
	bool canConnect(char) const;
private:

};