#pragma once

#include "RotatablePipe.h"

class ThreeSidesPipe : public RotatablePipe {
public:
	ThreeSidesPipe() : RotatablePipe() {};
	ThreeSidesPipe(sf::Vector2f& point, int rotDeg) :
		RotatablePipe(point, rotDeg) {}
	sf::Sprite create() const;
	bool canConnect(char) const;
private:

};
