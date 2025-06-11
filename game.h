#pragma once
#include "grid.cpp"
#include "blocks.cpp"

class Game{
    private:
        std::vector <Block> blocks;
        Block currentBlock;
        Block nextBlock;
        bool BlockFits();
        void RotateBlock();
        void LockBlock();
        void Reset();
        bool IsBlockOutside();
        void UpdateScore(int linesCleared, int MoveDownPoints);
    public:
        Game();
        Block GetRandomBlock();
        int Score;
        bool GameOver;
        std::vector<Block> GetAllBlocks();
        void Draw();
        Grid grid;
        void HandleInput();
        void MoveBlockLeft();
        void MoveBlockRight();
        void MoveBlockDown();

    
        
};