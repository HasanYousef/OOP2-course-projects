#include "Level.h"

//-----------------------------------------------
Level::Level() {
	m_height = 0;
	m_width = 0;
	m_pumperXindex = 0;
	m_pumperYindex = 0;
	m_receiverYindex = 0;
	m_receiverXindex = 0;
}

//-----------------------------------------------
Level::~Level() {
	deleteLevel();
}

//-----------------------------------------------
void Level::deleteLevel() {
	for (int row = 0; row < m_level.size(); row++) {
		for (int col = 0; col < m_level[row].size(); col++) {
			delete m_level[row][col];
		}
	}
}

//-----------------------------------------------
void Level::load_level(int level) {
	deleteLevel();
	m_level.clear();
	std::string str = "C:Level";
	str += std::to_string(level);
	str += ".txt";
	fs::path p = str;
	std::ifstream ifile(fs::absolute(p));
	readFromStream(ifile);
	ifile.close();
}

//-----------------------------------------------
//here the constructor that we use it if we have 
//a level file we open the file and do stream 
//and we read tha inputs from the file and print 
//them on the window the map to
void Level::readFromStream(std::ifstream& stream) {
	stream >> m_height;
	stream >> m_width;
	//reading the map's chars line by line
	m_level.resize(m_height);
	for (int row = 0; row < m_height; row++) {
		//jumping over the new line char
		stream.get();
		for (int col = 0; col < m_width; col++) {
			sf::Vector2f points(col * TEXTURE_SIZE, row * TEXTURE_SIZE);
			switch (char_to_type(stream.get())) {
			case PipeType::BowP:
				m_level[row].push_back(new BowPipe());
				break;
			case PipeType::PumperP:

			}
		} 
	}
}

//-----------------------------------------------
void Level::draw(sf::RenderWindow& window) {
	for (int row = 0; row < m_height; row++) {
		for (int col = 0; col < m_width; col++) {
			m_level[row][col]->draw(window);
		}
	}
}

//-----------------------------------------------
int Level::getWidth() const {
	return m_width;
}

//-----------------------------------------------
int Level::getHeight() const {
	return m_height;
}

//-----------------------------------------------
Pipes *Level::getPipe(int row, int col) {
	if (row >= m_height || col >= m_width
		|| row < 0 || col < 0) {
		throw std::exception("Wrong index");
	}
	return (m_level[row][col]);
}

//-----------------------------------------------
bool Level::solved() {
	return checkIfConnect(m_pumperYindex, m_pumperXindex);
}

//-----------------------------------------------
bool Level::checkIfConnect(int y, int x) {
	if (y == m_receiverYindex && x == m_receiverXindex) {
		return true;
	}
	else if (x > 0 && m_level[y][x]->ifcanConnect(L)
			&& m_level[y][x - 1]->ifcanConnect(R)) {
		m_level[y][x - 1]->setWaterRec(true);
		checkIfConnect(y, x - 1);
	}
	else if (x < m_width - 1 && m_level[y][x]->ifcanConnect(R)
		&& m_level[y][x + 1]->ifcanConnect(L)) {
		m_level[y][x + 1]->setWaterRec(true);
		checkIfConnect(y, x + 1);
	}
	else if (y > 0 && m_level[y][x]->ifcanConnect(U)
		&& m_level[y - 1][x]->ifcanConnect(D)) {
		m_level[y - 1][x]->setWaterRec(true);
		checkIfConnect(y - 1, x);
	}
	else if (y < m_height - 1 && m_level[y][x]->ifcanConnect(D)
		&& m_level[y + 1][x]->ifcanConnect(U)) {
		m_level[y + 1][x]->setWaterRec(true);
		checkIfConnect(y + 1, x);
	}
	return false;
}