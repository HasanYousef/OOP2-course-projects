#pragma once

#include <SFML/Graphics.hpp>
#include "macros.h"
#include "Textures.h"

class Pipe {
public:
	Pipe() {};
	Pipe(sf::Vector2f& point) : m_point(point) {};
	Pipe(sf::Vector2f& point, int rotDeg) :
		m_point(point), m_rotateDeg(rotDeg) {};
	// get functions
	sf::Sprite create(PipeType) const;
	virtual sf::Sprite create() const;
	int getRotateDeg() const;
	sf::Vector2f getPoint() const;
	bool ifReceiveWater() const;
	//--------------------
	virtual void draw(sf::RenderWindow&);
	virtual bool canConnect(char) const;
	void setWaterRec(bool);

protected:
	sf::Vector2f m_point;
	bool m_receiveWater = false;
	int m_rotateDeg = 1; 
};

// Read 
/* rotateDeg is:
		 1 top
		______
left 4 |      | 2 right
	   |      |
	   --------
		 3 bottom   */