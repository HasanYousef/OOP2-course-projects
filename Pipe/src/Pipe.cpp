#include "Pipe.h"

//---------------------------------------------
sf::Sprite Pipe::create() const {
    return sf::Sprite();
}

//---------------------------------------------
void Pipe::draw(sf::RenderWindow& window) {
    window.draw(create());
}

sf::Sprite Pipe::create(PipeType pipeType) const {
    sf::Sprite result = sf::Sprite(*Textures::instance().
        get_texture(pipeType, ifReceiveWater()));
    result.setPosition(getPoint());
    int rot = 1;
    while (rot < getRotateDeg()) {
        result.rotate(90.0f);
        rot++;
    }
    return result;
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
