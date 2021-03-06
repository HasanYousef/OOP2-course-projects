#pragma once

#include <fstream>
#include <filesystem>
#include <SFML/Graphics.hpp>
#include "ReceiverPipe.h"
#include "CornerPipe.h"
#include "PumperPipe.h"
#include "RotatablePipe.h"
#include "ThreeSidesPipe.h"
#include "TwoSidesPipe.h"
namespace fs = std::filesystem;

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
	Pipe *getPipe(int, int);
	bool solved();
	
private:
	bool checkIfConnect(int, int, bool** arr, int = 0);
	void deleteArr(bool** arr, int rowsNum);
	void fillBoolArr(bool**);
	bool pointsOfReceiver(int, int);
	//---------------------------------------
	std::vector<std::vector<Pipe*>> m_board;
	int m_width, m_height;
	sf::Vector2i m_pumperPoint;
	std::vector<sf::Vector2i> m_receiversPoints;
};