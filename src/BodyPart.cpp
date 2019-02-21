#include "BodyPart.h"

#include "Main.h"
#include "Matrix.h"

#include <stdexcept>
#include <string>
#include <iostream>

BodyPart::BodyPart(unsigned posX, unsigned posY)
    : m_posX(posX), m_posY(posY)
{
}

BodyPart::~BodyPart()
{
}

// public

void BodyPart::draw(Matrix& matrix) const noexcept
{
    try {
        matrix.lightUp(m_posX, m_posY, MatrixObjects::BODY_PART);
    } catch (std::runtime_error& e) {
        std::cout << "Could not draw Fruit: " << e.what() << std::endl;
    }
}

void BodyPart::move(int ofX, int ofY)
{
    int futurX = m_posX + ofX;
    int futurY = m_posY + ofY;

    if (futurX >= MAT_SIZE || futurX < 0)
        throw std::runtime_error("Can't move BodyPart from " + std::to_string(ofX) + " units on the X axis");

    if (futurY >= MAT_SIZE || futurY < 0)
        throw std::runtime_error("Can't move BodyPart from " + std::to_string(ofY) + " units on the Y axis");

    m_posX = futurX;
    m_posY = futurY;
}

void BodyPart::teleport(unsigned toX, unsigned toY)
{
    if (toX >= MAT_SIZE)
        throw std::runtime_error("Invalid new X position: " + std::to_string(toX));

    if (toY >= MAT_SIZE)
        throw std::runtime_error("Invalid new X position: " + std::to_string(toY));

    m_posX = toX;
    m_posY = toY;
}

// private