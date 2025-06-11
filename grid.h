#pragma once
#include <vector>
#include <raylib.h>

class Grid {
public:
    Grid();
    void Initialize();
    void Print();
    void Draw();
    int ClearFullRows();
    bool IsCellOutside(int row, int column);
    bool IsCellEmpty(int row, int column);
    int grid[20][10];

private:

    int numRows, numCols, cellSize;
    std::vector<Color> colors;
    void MoveRowDown(int row, int NumRows);
    bool IsRowFull(int row);
    void ClearRow(int row);


};
