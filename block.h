#pragma once
#include <vector>
#include <map>
#include "position.cpp"
#include "colors.h"
class Block {
private:
    int cellsize;
    int rotationState;
    int rowOffset;
    int columnOffset;
    std::vector<Color> colors;
    

public:
    Block();
    int id;
    void rotate();
    void UndoRotation();
    std::map<int, std::vector<Position>> cells;
    void Draw(int offsetX, int offsetY);

    void Move(int rows, int columns);
    std::vector<Position> GetCellPositions();
};

