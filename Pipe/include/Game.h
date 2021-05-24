#pragma once

#include "Level.h"
#include "ThreeSidesPipe.h"
#include "TwoSidesPipe.h"
#include "CornerPipe.h"
#include "macros.h"

class Game {
public:
	Game();
	void run();

private:
	//---Functions-----
	bool run_level(); //false if didnot solve the level
	void pipeClick(sf::Vector2f, Rotate);
	//---Members-------
	sf::RenderWindow m_window;
	Level m_level;
	int m_clicks;
};
