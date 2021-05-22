#include "BowPipe.h"

BowPipe::BowPipe(sf::Vector2f& points) {
	m_points = points;
	m_receiveWater = false;
	m_rotateDeg = 1;
	m_down = true;
	m_left = true;
	m_right = false;
	m_up = false;
}

sf::Sprite BowPipe::create() const {
	sf::Sprite result = sf::Sprite(*Textures::instance().
		get_texture(PipeType::BowP, ifReceiveWater()));
	result.setPosition(getPoints());
	int rot = 1;
	while (rot < getRotateDeg())
		result.rotate(90.0f);
		rot++;
	return result;
}
