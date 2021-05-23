#include "Pipe.h"

//---------------------------------------------
sf::Sprite Pipe::create() const {
    return sf::Sprite();
}

//---------------------------------------------
void Pipe::draw(sf::RenderWindow& window) {
    window.draw(create());
}

//---------------------------------------------
bool Pipe::handleClick(const sf::Vector2f& location) {
    return create().getGlobalBounds().contains(location);
}

void Pipe::rotatePipe(Rotate rotate) {
    if (rotate == Rotate::ToLeft) {
        m_rotateDeg++;
        if (m_rotateDeg > 4)
            m_rotateDeg = 1;
    }
    else {
        m_rotateDeg--;
        if (m_rotateDeg < 1)
            m_rotateDeg = 4;
    }
}

bool Pipe::canConnect(char way) const {
    if (way == TOP)
        return m_topReceived;
    else if (way == BOTTOM)
        return m_buttomReceived;
    else if (way == RIGHT)
        return m_rightReceived;
    else if (way == LEFT)
        return m_leftReceived;
}

//---------------------------------------------
int Pipe::getRotateDeg() const {
    return m_rotateDeg;
}

//---------------------------------------------
sf::Vector2f Pipe::getPoint() const {
    return m_point;
}

//---------------------------------------------
bool Pipe::ifReceiveWater() const {
    return m_topReceived || m_buttomReceived || m_leftReceived || m_rightReceived;
