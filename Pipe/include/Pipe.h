#pragma once

#include <SFML/Graphics.hpp>
#include "macros.h"
#include "Textures.h"

class Pipe {
public:
	Pipe() {};
	Pipe(sf::Vector2f& point) : m_point(point) {};
	Pipe(bool top, bool bottom, bool left, bool right) :
		m_topReceived(top), m_buttomReceived(bottom),
		m_leftReceived(left), m_rightReceived(right) {};;
	Pipe(sf::Vector2f& point, bool top, bool bottom, bool left, bool right) : 
			m_point(point), m_topReceived(top), m_buttomReceived(bottom),
			m_leftReceived(left), m_rightReceived(right) {};
	// get functions
	virtual sf::Sprite create() const;
	int getRotateDeg() const;
	sf::Vector2f getPoint() const;
	bool ifReceiveWater() const;
	//--------------------
	virtual void draw(sf::RenderWindow&);
	bool handleClick(const sf::Vector2f&);
	void rotatePipe(Rotate);
	bool canConnect(char) const;

protected:
	sf::Vector2f m_point;
	bool m_topReceived = false,
		 m_buttomReceived = false,
		 m_leftReceived = false,
		 m_rightReceived = false;
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