#pragma once

#include "Main.h"

class Matrix;
class BodyPart;

class Player
{
  public:
    Player(unsigned posX, unsigned posY, Facing facing = Facing::SOUTH);
    ~Player();

    void draw(Matrix& matrix) const noexcept;
    void grow() noexcept;
    void move(Matrix& matrix, Direction dir) noexcept;
    inline bool isAlive() const noexcept { return m_isAlive; }

  private:
    Movement getMovement(Direction dir) noexcept;

  private:
    BodyPart* m_head;
    Facing m_facing;;
    bool m_hasGrown = false;
    bool m_isAlive = true;
};