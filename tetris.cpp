#include <raylib.h>
#include <iostream>
#include "game.cpp"



///set up game loop
//creating the grid
//create the blocks
//move the blocks
//rotate the blocks
//check for collisions
//check for completed rows
//game over
//create user interface
//add score
//add next block
//add sounds
double lastupdatetime = 0;
bool EventTriggered(double interval){
    double currentTime = GetTime();
    if(currentTime - lastupdatetime >= interval){
        lastupdatetime = currentTime;
        return true;
    }
    return false;

}

int main(){
    // Game Strcture 1 - Definitions
    
    InitWindow(500,620,"Tetris"); //initializes window. This window is where everything will happen
    SetTargetFPS(60); //without this computer will run game as fast as it can

    Font font = LoadFontEx("Monogram.ttf",64,0,0);
    

    Game game = Game();
    //Game Structue 2 - Game Loop
    while(WindowShouldClose() == false){  //WindowShouldClose() checks for exit events like esc or X on top right
        game.HandleInput();
        if(EventTriggered(0.2)){
            game.MoveBlockDown();
        }
        
        BeginDrawing(); //draws shape enabling us to define the shape and update it
        ClearBackground(darkBlue); // changes background data
        DrawTextEx(font, "Score", {355,15},38,2,WHITE);
        DrawTextEx(font, "Next", {365,175},38,2,WHITE);
        if(game.GameOver){
            DrawTextEx(font, "GAME OVER", {320,450},38,2,WHITE);
        }
        DrawRectangleRounded({320,55,170,60},0.3,6,lightBlue);

        char ScoreText[10];
        sprintf(ScoreText, "%d", game.Score);
        Vector2 textsize = MeasureTextEx(font, ScoreText,38,2);
        textsize.x;


        DrawTextEx(font, ScoreText, {240+ (170 - textsize.x/2),65},38,2,WHITE);
        DrawRectangleRounded({320,215,170,180},0.3,6,lightBlue);
        game.Draw();        
        EndDrawing();
    }

    CloseWindow(); //closes the window
}
