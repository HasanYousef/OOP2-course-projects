#pragma once

#include "Pipe.h"

class ReceiverPipe : public Pipe {
public:
	ReceiverPipe() : Pipe() {}
	ReceiverPipe(sf::Vector2f& point, int rotDeg) : Pipe(point, rotDeg) {}
	sf::Sprite create() const;
	bool canConnect(char) const;
private:

};
