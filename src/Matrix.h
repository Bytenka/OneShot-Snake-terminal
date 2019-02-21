#pragma once
#include "Main.h"

#include <string>

class Matrix
{
  public:
    Matrix();
    ~Matrix();

    std::string getDisplay() const noexcept;
    void clear() noexcept;
    inline MatrixObjects getItemAt(unsigned row, unsigned col) const { return getPixel(row, col); }
    inline void lightUp(unsigned row, unsigned col, char value) { setPixel(row, col, value); }
    inline void erase(unsigned row, unsigned col) { setPixel(row, col, MatrixObjects::VOID); }

  private:
    void setPixel(unsigned row, unsigned col, char value);
    MatrixObjects getPixel(unsigned row, unsigned col) const;

  private:
    char m_mat[MAT_SIZE][MAT_SIZE];
};