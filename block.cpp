#include "block.h"

Block::Block() {
    cellsize = 30;
    rotationState = 0;
    colors = GetCellColors();
    rowOffset = 0;
    columnOffset = 0;
}

void Block::rotate()
{
    rotationState++;
    if(rotationState == cells.size()){
        rotationState = 0;
    }
}

void Block::UndoRotation()
{
    rotationState --;
    if(rotationState == -1){
        rotationState = cells.size() - 1;
    }
}

void Block::Draw(int offsetX, int offsetY){
    std::vector<Position> tiles = GetCellPositions();
    for (Position item : tiles) {
        DrawRectangle(item.column * cellsize + offsetX, item.row * cellsize + offsetY, cellsize - 1, cellsize - 1, colors[id]);
    }
}

void Block::Move(int rows, int columns) {

    rowOffset += rows;
    columnOffset += columns;

}

std::vector<Position> Block::GetCellPositions() {
    std::vector<Position> tiles = cells[rotationState];
    std::vector<Position> movedTiles;
    for (Position item : tiles) {
        Position newPos = Position(item.row + rowOffset, item.column + columnOffset);
        movedTiles.push_back(newPos);
    }
    return movedTiles;
}