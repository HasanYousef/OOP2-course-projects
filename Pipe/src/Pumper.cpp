#pragma once

#include "Pumper.h"

Pumper::Pumper(sf::Vector2f& points) {
	m_points = points;
	m_receiveWater = true;
	m_rotateDeg = 1;
	m_down = true;
	m_left = false;
	m_right = false;
	m_up = false;
}