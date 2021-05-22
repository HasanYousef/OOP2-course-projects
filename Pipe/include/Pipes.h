#pragma once

#include <SFML/Graphics.hpp>
#include "macros.h"
#include "Textures.h"

class Pipes {
public:
	Pipes();
	Pipes(sf::Vector2f&);
	Pipes(bool, bool, bool, bool);
	Pipes(sf::Vector2f&, bool, bool, bool, bool);
	// get functions
	virtual sf::Sprite create() const;
	int getRotateDeg() const;
	sf::Vector2f getPoints() const;
	bool ifReceiveWater() const;
	//--------------------
	virtual void draw(sf::RenderWindow&);
	bool handleClick(const sf::Vector2f&);
	void rotatePipe(Rotate);
	bool ifcanConnect(char) const;
	// set functions
	void setWaterRec(bool);

protected:
	sf::Vector2f m_points;
	bool m_receiveWater = false,
		m_up, m_down, m_left, m_right;
	int m_rotateDeg; 
};

// Read 
/* rotateDeg is:
		 1 up
		______
left 4 |      | 2 right
	   |      |
	   --------
		 3 down   */