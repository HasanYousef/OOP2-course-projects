#include "Pipes.h"

//---------------------------------------------
Pipes::Pipes() {
    m_receiveWater = false;
    m_rotateDeg = 1;
    m_down = false;
    m_left = false;
    m_right = false;
    m_up = false;
}

Pipes::Pipes(sf::Vector2f& vec) {
    m_points = vec;
    m_receiveWater = false;
    m_rotateDeg = 1;
}

//---------------------------------------------
Pipes::Pipes(sf::Vector2f& vec, bool up,
      bool down, bool left, bool right) {
    m_points = vec;
    m_receiveWater = false;
    m_rotateDeg = 1;
    m_up = up;
    m_down = down;
    m_left = left;
    m_right = right;
}

//---------------------------------------------
Pipes::Pipes(bool up, bool down, bool left, bool right) {
    m_receiveWater = false;
    m_rotateDeg = 1;
    m_up = up;
    m_down = down;
    m_left = left;
    m_right = right;
}

//---------------------------------------------
sf::Sprite Pipes::create() const {
    return sf::Sprite();
}

//---------------------------------------------
void Pipes::draw(sf::RenderWindow& window) {
    window.draw(create());
}

//---------------------------------------------
bool Pipes::handleClick(const sf::Vector2f& location) {
    return create().getGlobalBounds().contains(location);
}

void Pipes::rotatePipe(Rotate rotate) {
    if (rotate == Rotate::Left) {
        m_rotateDeg++;
        if (m_rotateDeg > 4)
            m_rotateDeg = 1;
        return;
    }
    m_rotateDeg--;
    if (m_rotateDeg < 1 )
        m_rotateDeg = 4;
}

//---------------------------------------------
void Pipes::setWaterRec(bool ifReceive) {
    m_receiveWater = ifReceive;
}

bool Pipes::ifcanConnect(char way) const {
    switch (way) {
    case U:
        return m_up;
    case D:
        return m_down;
    case R:
        return m_right;
    case L:
        return m_left;
    }
    return false;
}

//---------------------------------------------
int Pipes::getRotateDeg() const {
    return m_rotateDeg;
}

//---------------------------------------------
sf::Vector2f Pipes::getPoints() const {
    return m_points;
}

//---------------------------------------------
bool Pipes::ifReceiveWater() const {
    return m_receiveWater;
}
