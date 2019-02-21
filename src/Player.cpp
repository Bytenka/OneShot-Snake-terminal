#include "Player.h"

#include "Matrix.h"
#include "BodyPart.h"

Player::Player(unsigned posX, unsigned posY, Facing facing)
:m_facing(facing)
{
    m_head = new BodyPart(posX, posY);
}

Player::~Player()
{
    const BodyPart* currentPart = m_head;
    while (currentPart != nullptr) {
        const BodyPart* toDel = currentPart;
        currentPart = currentPart->getNext();
        delete toDel;
    }
}

// public:

void Player::draw(Matrix& matrix) const noexcept
{
    const BodyPart* currentPart = m_head;
    while (currentPart != nullptr) {
        currentPart->draw(matrix);
        currentPart = currentPart->getNext();
    }
}

void Player::grow() noexcept
{
    BodyPart* newOne = new BodyPart(m_head->getX(), m_head->getY());
    newOne->setNext(m_head);
    m_head = newOne;
    m_hasGrown = true;
}

void Player::move(Matrix& matrix, Direction dir) noexcept
{
    Movement movement = getMovement(dir);

    int futurX = m_head->getX() + movement.onX;
    int futurY = m_head->getY() + movement.onY;
    if (futurX < 0 || futurX >= MAT_SIZE || futurY < 0 || futurY >= MAT_SIZE) {
        m_isAlive = false;
        return;
    }

    MatrixObjects obj = matrix.getItemAt(futurX, futurY);
    switch (obj) {
    case MatrixObjects::BODY_PART:
        m_isAlive = false;
        return;
    case MatrixObjects::FRUIT:
        grow();
        // delete fruit
        break;
    default:
        break;
    }

    if (!m_hasGrown) {
        BodyPart* currentPart = m_head;
        unsigned lastX = currentPart->getX(), lastY = currentPart->getY();

        while (currentPart != nullptr) {
            BodyPart* next = currentPart->getNext();

            if (next != nullptr) {
                unsigned toTeleX = lastX, toTeleY = lastY;
                lastX = next->getX();
                lastY = next->getY();
                next->teleport(toTeleX, toTeleY);
            }

            currentPart = next;
        }
    }

    m_head->move(movement.onX, movement.onY);
    m_hasGrown = false;
}

// private:

Movement Player::getMovement(Direction dir) noexcept
{
    switch (dir) {
    case LEFT:
        switch (m_facing) {
        case NORTH:
            m_facing = WEST;
            break;
        case SOUTH:
            m_facing = EAST;
            break;
        case EAST:
            m_facing = NORTH;
            break;
        case WEST:
            m_facing = SOUTH;
            break;
        }
        break;
    case RIGHT:
        switch (m_facing) {
        case NORTH:
            m_facing = EAST;
            break;
        case SOUTH:
            m_facing = WEST;
            break;
        case EAST:
            m_facing = SOUTH;
            break;
        case WEST:
            m_facing = NORTH;
            break;
        }
        break;
    }

    switch (m_facing) {
    case NORTH:
        return {0, -1};
    case SOUTH:
        return {0, 1};
    case EAST:
        return {1, 0};
    case WEST:
        return {-1, 0};
    }
    return {0, 0};
}