#pragma once
#define MAT_SIZE 8

enum Direction {
    FORWARD = 0,
    LEFT,
    RIGHT
};

enum Facing {
    NORTH = 0,
    SOUTH,
    EAST,
    WEST
};

struct Movement {
    int onX = 0, onY = 0;
};

enum MatrixObjects {
    VOID = 0,
    BODY_PART,
    FRUIT
};