#include "RotatablePipe.h"

//---------------------------------------------
bool RotatablePipe::handleClick(const sf::Vector2f& location) {
    return create().getGlobalBounds().contains(location);
}

//---------------------------------------------
void RotatablePipe::rotatePipe(Rotate rotate) {
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

//---------------------------------------------
bool RotatablePipe::canConnect(char) const {
    return false;
}
