#include "game.h"
#include <random>

bool Game::BlockFits()
{
    std::vector<Position> tiles = currentBlock.GetCellPositions();
    for(Position item: tiles){
        if(grid.IsCellEmpty(item.row, item.column) == false){
            return false;
        }
    }
    return true;
}

void Game::RotateBlock()
{
    currentBlock.rotate();
    if(IsBlockOutside()){
        currentBlock.UndoRotation();
    }
}

void Game::LockBlock()
{
    std::vector <Position> tiles = currentBlock.GetCellPositions();
    for (Position item: tiles){
        grid.grid[item.row][item.column] = currentBlock.id;
    }
    currentBlock = nextBlock;
    if(BlockFits() == false){
        GameOver = true;

    }
    nextBlock = GetRandomBlock();
    int rowsCleared = grid.ClearFullRows();
    UpdateScore(rowsCleared, 0);
}

bool Game::IsBlockOutside()
{
    std::vector <Position> tiles = currentBlock.GetCellPositions();

    for(Position item: tiles){
        if(grid.IsCellOutside(item.row,item.column)){
            return true;
        }
    }
    return false;
}

void Game::UpdateScore(int linesCleared, int MoveDownPoints)
{
    switch(linesCleared){
        case 1:
            Score+=100;
            break;
        case 2:
            Score+=300;
            break;
        case 3:
            Score+=500;
            break;
        default:
            break;
    }
    Score += MoveDownPoints;
}

Game::Game()
{
    grid = Grid();
    blocks = GetAllBlocks();
    currentBlock = GetRandomBlock();
    nextBlock = GetRandomBlock();
    GameOver = 0;
    Score = 0;
}

Block Game::GetRandomBlock() {
    if (blocks.empty()) {
        blocks = GetAllBlocks();
    }

    int randomIndex = rand() % blocks.size();
    Block block = blocks[randomIndex];
    blocks.erase(blocks.begin() + randomIndex);
    return block;
}

std::vector<Block> Game::GetAllBlocks() {
    return { IBlock(),JBlock(),LBlock(),OBlock(),SBlock(),TBlock(),ZBlock() };
}

void Game::Draw() {
    grid.Draw();   
    currentBlock.Draw(11,11);
    switch(nextBlock.id){
        case 3:
            nextBlock.Draw(255,290);
            break;
        case 4:
            nextBlock.Draw(255,280);
            break;
        default:
            nextBlock.Draw(270,270);
    }
    
    
}

void Game::Reset(){
    grid.Initialize();
    blocks = GetAllBlocks();
    currentBlock = GetRandomBlock();
    nextBlock = GetRandomBlock();
    Score = 0;
}
void Game::HandleInput() {
    int KeyPressed = GetKeyPressed();//Raylib function that returns key pressed
    if(GameOver != 0 && KeyPressed !=0){
        GameOver = false;
        Reset();
    }

    switch (KeyPressed) {
    case KEY_LEFT:
        MoveBlockLeft();
        break;

    case KEY_RIGHT:
        MoveBlockRight();
        break;

    case KEY_DOWN:
        MoveBlockDown();
        UpdateScore(0, 1);
        break;

    case KEY_UP:
        RotateBlock();
        break;
    }

    
}

void Game::MoveBlockLeft() {
    if(!GameOver){
    currentBlock.Move(0, -1);
    if(IsBlockOutside() || BlockFits() == false){
        currentBlock.Move(0, 1);
    }
}}

void Game::MoveBlockRight() {
    if(!GameOver)
    {currentBlock.Move(0, 1);
    if(IsBlockOutside() || BlockFits() == false){
        currentBlock.Move(0, -1);
    }
    }
}

void Game::MoveBlockDown() {
    if(!GameOver)
    {currentBlock.Move(1, 0);
    if(IsBlockOutside() || BlockFits() == false){
        currentBlock.Move(-1, 0);
        LockBlock();
    }
}}
