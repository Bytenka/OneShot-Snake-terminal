#include "Matrix.h"

#include <stdexcept>

Matrix::Matrix()
{
    clear();
}

Matrix::~Matrix()
{
}

// public:

std::string Matrix::getDisplay() const noexcept
{
    std::string tr;
    for (int row = 0; row < MAT_SIZE; row++) {
        for (int col = 0; col < MAT_SIZE; col++) {
            std::string toAppend;
            switch (m_mat[col][row]) {
            case MatrixObjects::VOID:
                toAppend = ".";
                break;
            case MatrixObjects::BODY_PART:
                toAppend = "o";
                break;
            case MatrixObjects::FRUIT:
                toAppend = "x";
                break;
            default:
                toAppend = "?";
                break;
            }
            tr.append(toAppend + " ");
        }
        tr += "\n";
    }

    return tr;
}

void Matrix::clear() noexcept
{
    for (int row = 0; row < MAT_SIZE; row++)
        for (int col = 0; col < MAT_SIZE; col++)
            m_mat[row][col] = 0;
}

// private:

void Matrix::setPixel(unsigned row, unsigned col, char value)
{
    if (row >= MAT_SIZE)
        throw std::runtime_error("Invalid value \"" + std::to_string(row) + "\" for parameter \"row\"");

    if (col >= MAT_SIZE)
        throw std::runtime_error("Invalid value \"" + std::to_string(col) + "\" for parameter \"col\"");

    m_mat[row][col] = value;
}

MatrixObjects Matrix::getPixel(unsigned row, unsigned col) const
{
    if (row >= MAT_SIZE)
        throw std::runtime_error("Invalid value \"" + std::to_string(row) + "\" for parameter \"row\"");

    if (col >= MAT_SIZE)
        throw std::runtime_error("Invalid value \"" + std::to_string(col) + "\" for parameter \"col\"");

    return (MatrixObjects)m_mat[row][col];
}