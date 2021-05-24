#pragma once

#include "Pipe.h"

class RotatablePipe : public Pipe {
public:
	RotatablePipe() : Pipe() {}
	RotatablePipe(sf::Vector2f& point, int rotDeg) : Pipe(point, rotDeg) {}
	bool handleClick(const sf::Vector2f&);
	void rotatePipe(Rotate);
	virtual bool canConnect(char) const;
private:

};