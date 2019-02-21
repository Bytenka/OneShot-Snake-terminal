#include "Game.h"
#include "Main.h"

#include <random>
#include <chrono>
#include <thread>
#include <iostream>

Game::Game()
    : m_player(1, 1, Facing::SOUTH)
{
    spawnFruits(2);
}

Game::~Game()
{
}

// public:

void Game::run()
{
    while (m_player.isAlive()) {
        std::this_thread::sleep_for(std::chrono::milliseconds(500));
        
        m_matrix.clear();
        for (auto& f : m_fruits) {
            f.draw(m_matrix);
        }
        m_player.draw(m_matrix);

        m_player.move(m_matrix, Direction::FORWARD);

        m_matrix.clear();
        for (auto& f : m_fruits) {
            f.draw(m_matrix);
        }
        m_player.draw(m_matrix);

        std::cout << m_matrix.getDisplay() << std::endl;
    }
}

// private:

void Game::spawnFruits(unsigned count) noexcept
{
    for (unsigned i = 0; i < count; i++) {
        unsigned x, y;
        while (m_matrix.getItemAt(x = rand() % MAT_SIZE, y = rand() % MAT_SIZE) != MatrixObjects::VOID)
            ;

        m_fruits.push_back(Fruit(x, y));
    }
}