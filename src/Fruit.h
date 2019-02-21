#pragma once

class Matrix;

class Fruit
{
  public:
    Fruit(unsigned posX, unsigned posY);
    ~Fruit();

    void draw(Matrix& matrix) const noexcept;

  private:
  unsigned m_posX, m_posY;
};