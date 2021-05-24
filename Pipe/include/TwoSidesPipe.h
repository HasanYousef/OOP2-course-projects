#pragma once

#include "RotatablePipe.h"

class TwoSidesPipe : public RotatablePipe {
public:
	TwoSidesPipe() : RotatablePipe() {}
	TwoSidesPipe(sf::Vector2f& point, int rotDeg) :
		RotatablePipe(point, rotDeg) {}
	sf::Sprite create() const;
	bool canConnect(char) const;
private:

};
