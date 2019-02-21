#include "Fruit.h"

#include "Matrix.h"

#include <stdexcept>
#include <iostream>

Fruit::Fruit(unsigned posX, unsigned posY)
    : m_posX(posX), m_posY(posY)
{
}

Fruit::~Fruit()
{
}

// public:

void Fruit::draw(Matrix& matrix) const noexcept
{
    try {
        matrix.lightUp(m_posX, m_posY, MatrixObjects::FRUIT);
    } catch (std::runtime_error& e) {
        std::cout << "Could not draw Fruit: " << e.what() << std::endl;
    }
}

// private: