#pragma once

class Matrix;

class BodyPart
{
  public:
    BodyPart(unsigned posX, unsigned posY);
    ~BodyPart();

    void draw(Matrix& matrix) const noexcept;
    void move(int ofX, int ofY);
    void teleport(unsigned toX, unsigned toY);
    inline  BodyPart* getNext() const noexcept { return m_next; }

    inline unsigned getX() const noexcept { return m_posX; }
    inline unsigned getY() const noexcept { return m_posY; }
    inline void setNext(BodyPart* next) noexcept { m_next = next; }

  private:
    unsigned m_posX, m_posY;
    BodyPart* m_next = nullptr;
};
