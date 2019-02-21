#pragma once

#include "Player.h"
#include "Matrix.h"
#include "Fruit.h"

#include <vector>

class Game
{
  public:
    Game();
    ~Game();

    void run();

  private:
    void spawnFruits(unsigned count) noexcept;


  private:
    Player m_player;
    Matrix m_matrix;
    std::vector<Fruit> m_fruits;
};