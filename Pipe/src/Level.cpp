#include "Level.h"

//-----------------------------------------------
Level::Level() {
	m_height = 0;
	m_width = 0;
	m_pumperPoint.x = 0;
	m_pumperPoint.y = 0;
}

//-----------------------------------------------
Level::~Level() {
	deleteLevel();
}

//-----------------------------------------------
void Level::deleteLevel() {
	for (int row = 0; row < m_board.size(); row++) {
		for (int col = 0; col < m_board[row].size(); col++) {
			delete m_board[row][col];
		}
	}
}

//-----------------------------------------------
void Level::load_level(int level) {
	deleteLevel();
	m_board.clear();
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
	m_board.resize(m_height);
	for (int row = 0; row < m_width; row++) {
		//jumping over the new line char
		stream.get();
		for (int col = 0; col < m_width; col++) {
			sf::Vector2f points(col * TEXTURE_SIZE, row * TEXTURE_SIZE);
			switch (char_to_type(stream.get())) {
			case PipeType::Receiver:
				m_board[row].push_back(new ReceiverPipe(points,
					int(stream.get() - '0')));
				break;
			case PipeType::Pumper:
				m_board[row].push_back(new PumperPipe(points,
					int(stream.get() - '0')));
				break;
			default: //case PipeType::TwoSides:	
				m_board[row].push_back(new TwoSidesPipe(points,
					int(stream.get() - '0')));
				break;
			case PipeType::Corner:
				m_board[row].push_back(new CornerPipe(points,
					int(stream.get() - '0')));
				break;
			case PipeType::ThreeSides:
				m_board[row].push_back(new ThreeSidesPipe(points,
					int(stream.get() - '0')));
				break;
			}
		} 
	}
}

//-----------------------------------------------
void Level::draw(sf::RenderWindow& window) {
	for (int row = 0; row < m_height; row++) {
		for (int col = 0; col < m_width; col++) {
			m_board[row][col]->draw(window);
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
Pipe *Level::getPipe(int row, int col) {
	if (row >= m_height || col >= m_width
		|| row < 0 || col < 0) {
		throw std::exception("Wrong index");
	}
	return (m_board[row][col]);
}

//-----------------------------------------------
bool Level::solved() {
	bool** arr = new bool*[m_height];
	for (int row = 0; row < m_height; row++) {
		arr[row] = new bool[m_width];
	}
	fillBoolArr(arr);
	for (int receiver = 0; receiver < m_receiversPoints.size(); receiver++) {
		if (!checkIfConnect(m_receiversPoints[receiver].y,
			m_receiversPoints[receiver].x, arr, 0)){
			deleteArr(arr, m_height);
			return false;
		}
		fillBoolArr(arr);
	}
	deleteArr(arr, m_height);
	return true;
}

//-----------------------------------------------
void Level::fillBoolArr(bool** arr) {
	for (int row = 0; row < m_height; row++) {
		for (int col = 0; col < m_width; col++) {
			arr[row][col] = true;
		}
	}
}

//-----------------------------------------------
bool Level::pointsOfReceiver(int y, int x) {
	for (int rec = 0; rec < m_receiversPoints.size(); rec++){
		if (m_receiversPoints[rec].x == x && m_receiversPoints[rec].y == y)
			return true;
	}
	return false;
}

//-----------------------------------------------
bool Level::checkIfConnect(int y, int x, bool** arr, int count) {
	if (!(arr[y][x])) { return false; }
	arr[y][x] = false;
	if (pointsOfReceiver(x,y)) {
		count++;
		if (count == m_receiversPoints.size()) { return true; }
	}
	else if (x > 0 && m_board[y][x]->canConnect(LEFT)
		&& m_board[y][x - 1]->canConnect(RIGHT)) {
		m_board[y][x - 1]->setWaterRec(true);
		if (checkIfConnect(y, x - 1, arr)) { return true; }
	}
	else if (x < m_width - 1 && m_board[y][x]->canConnect(RIGHT)
		&& m_board[y][x + 1]->canConnect(LEFT)) {
		m_board[y][x + 1]->setWaterRec(true);
		if (checkIfConnect(y, x + 1, arr)) { return true; }
	}
	else if (y > 0 && m_board[y][x]->canConnect(TOP)
		&& m_board[y - 1][x]->canConnect(BOTTOM)) {
		m_board[y - 1][x]->setWaterRec(true);
		if (checkIfConnect(y - 1, x, arr)) { return true; }
	}
	else if (y < m_height - 1 && m_board[y][x]->canConnect(BOTTOM)
		&& m_board[y + 1][x]->canConnect(TOP)) {
		m_board[y + 1][x]->setWaterRec(true);
		if (checkIfConnect(y + 1, x, arr)) { return true; }
	}
	return false;
}

/*   DONT DELETE IT
//-----------------------------------------------
bool Level::checkIfConnect(int y, int x, bool** arr) {
	if (!(arr[y][x])) { return false; }
	arr[y][x] = false;
	if (y == m_pumperPoint.y && x == m_pumperPoint.x) {
		return true;
	}
	else if (x > 0 && m_board[y][x]->canConnect(LEFT)
			&& m_board[y][x - 1]->canConnect(RIGHT)) {
		m_board[y][x - 1]->setWaterRec(true);
		if (checkIfConnect(y, x - 1, arr)) { return true; }
	}
	else if (x < m_width - 1 && m_board[y][x]->canConnect(RIGHT)
		&& m_board[y][x + 1]->canConnect(LEFT)) {
		m_board[y][x + 1]->setWaterRec(true);
		if (checkIfConnect(y, x + 1, arr)) { return true; }
	}
	else if (y > 0 && m_board[y][x]->canConnect(TOP)
		&& m_board[y - 1][x]->canConnect(BOTTOM)) {
		m_board[y - 1][x]->setWaterRec(true);
		if (checkIfConnect(y - 1, x, arr)) { return true; }
	}
	else if (y < m_height - 1 && m_board[y][x]->canConnect(BOTTOM)
		&& m_board[y + 1][x]->canConnect(TOP)) {
		m_board[y + 1][x]->setWaterRec(true);
		if(checkIfConnect(y + 1, x, arr)){return true;}
	}
	return false;
}
*/

//-----------------------------------------------
void Level::deleteArr(bool** arr, int rowsNum) {
	for (int row = 0; row < rowsNum; row++) {
		delete arr[row];
	}
	delete arr;
}