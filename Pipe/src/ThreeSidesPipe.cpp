#include "ThreeSidesPipe.h"

ThreeSidesPipe::ThreeSidesPipe(sf::Vector2f& points) {
	m_points = points;
	m_receiveWater = false;
	m_rotateDeg = 1;
	m_down = true;
	m_left = true;
	m_right = true;
	m_up = false;
}

sf::Sprite ThreeSidesPipe::create() const {
	sf::Sprite result = sf::Sprite(*Textures::instance().
		get_texture(PipeType::ThreeSidesP, ifReceiveWater()));
	result.setPosition(getPoints());
	int rot = 1;
	while (rot < getRotateDeg()) {
		result.rotate(90.0f);
		rot++;
	}
	return result;
}
