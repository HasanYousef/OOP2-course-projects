#include "..\include\Receiver.h"

Receiver::Receiver(sf::Vector2f& points) {
	m_points = points;
	m_receiveWater = false;
	m_rotateDeg = 1;
	m_down = true;
	m_left = true;
	m_right = false;
	m_up = false;
}
