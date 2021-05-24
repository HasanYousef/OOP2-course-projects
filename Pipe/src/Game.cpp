#include "Game.h"

//---------------------------------------------
game::game() {
	m_window.create(sf::VideoMode(300, 300), "Pipe");
	m_clicks = 0;
}

//-----------------start_game------------------
void game::run() {
	int level = 1;
	while (level <= NUMOFLEVELS) {
		m_level.load_level(level);
		run_level();
		level++;
	}
}

//---------------------------------------------
bool game::run_level() {
	sf::Event event;
	sf::Vector2f mousepos;
	while (m_window.isOpen()) {
		m_window.clear();
		m_level.draw(m_window);
		m_window.display();

		if (event = sf::Event{}; m_window.waitEvent(event)) {
			try {
				switch (event.type) {
				case sf::Event::Closed:
					m_window.close();
					break;
				case sf::Event::KeyPressed:
					throw std::exception("click just on mouse");
				default:
					throw std::exception("you can use just mouse");
				}
				//check if button mouse pressed
				if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
					mousepos = m_window.mapPixelToCoords(
						{ event.mouseButton.x, event.mouseButton.y });
					pipeClick(mousepos, Rotate::ToLeft);
					while (!(sf::Event::MouseButtonReleased)) {}
					m_clicks++;
				}
				else if (sf::Mouse::isButtonPressed(sf::Mouse::Right)) {
					mousepos = m_window.mapPixelToCoords(
						{ event.mouseButton.x, event.mouseButton.y });
					pipeClick(mousepos, Rotate::ToRight);
					while (!(sf::Event::MouseButtonReleased)) {}
					m_clicks++;
				}
			}
			catch (const std::exception& err) {
				err.what();
			}
		}
		if (m_level.solved()) {
			return true;
		}
	}
	return true;
}

//---------------------------------------------
void game::pipeClick(sf::Vector2f points, Rotate way) {
	for (int row = 0; row < m_level.getHeight(); row++) {
		for (int col = 0; col < m_level.getWidth(); col++) {
			RotatablePipe* pipe = dynamic_cast<RotatablePipe*>(m_level.getPipe(row, col));
			if (pipe == NULL) {
				throw std::exception("error in line 73 in game class");
			}
			if (pipe->handleClick(points)) {
				pipe->rotatePipe(way); //rotate left or right
				return;
			}
		}
	}
}