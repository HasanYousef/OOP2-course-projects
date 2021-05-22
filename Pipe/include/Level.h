#pragma once

#include <fstream>
#include <filesystem>
namespace fs = std::filesystem;
#include "BowPipe.h"
#include "Pumper.h"
#include "Receiver.h"
#include "ThreeSidesPipe.h"
#include "TwoSidesPipe.h"

class Level {
public:
	Level();
	~Level();
    //--------------------
	void deleteLevel();
	void load_level(int);
	void readFromStream(std::ifstream&);
	void draw(sf::RenderWindow&);
	int getWidth() const;
	int getHeight() const;
	Pipes *getPipe(int, int);
	bool solved();
	
private:
	bool checkIfConnect(int, int);
	//----------
	std::vector<std::vector<Pipes*>> m_level;
	int m_width, m_height,
		m_pumperXindex, m_pumperYindex,
		m_receiverXindex, m_receiverYindex;
};