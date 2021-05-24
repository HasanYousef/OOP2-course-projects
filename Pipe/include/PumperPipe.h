#pragma once
#include "RotatablePipe.h"

class PumperPipe : public Pipe {
public:
	PumperPipe() : Pipe() {}
	PumperPipe(sf::Vector2f vec) : Pipe(vec) {}
	PumperPipe(sf::Vector2f vec, int rotDeg) :
		Pipe(vec, rotDeg) { setWaterRec(true); }
	sf::Sprite create() const;
	bool canConnect(char) const;
private:

};
