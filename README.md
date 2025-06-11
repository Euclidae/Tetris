Tetris Game
This is a Tetris game implementation written in C++ using the Raylib library. The project was developed in 2023, inspired by tutorials from ProgrammingwithNick on YouTube. The code has been structured into multiple files for better organization, and a CMake build system is included to compile the project.
Project Structure

block.cpp, block.h: Defines the Block class and its derived classes (e.g., LBlock, JBlock, etc.) for different Tetris block types.
blocks.cpp: Implements specific block types inheriting from the Block class.
colors.cpp, colors.h: Contains color definitions and a function to get cell colors.
game.cpp, game.h: Implements the game logic, including block movement, rotation, scoring, and game over conditions.
grid.cpp, grid.h: Handles the game grid, including initialization, drawing, and row clearing.
position.cpp, position.h: Defines the Position class for tracking block positions.
tetris.cpp: The main file containing the game loop and window setup using Raylib.
CMakeLists.txt: CMake configuration file for building the project.
Monogram.ttf, Evogria Italic.otf: Font files used for text rendering.
.gitignore: Specifies files to ignore in version control.
README.md: This file.
LICENSE: MIT License for the project.

How to Build

Ensure you have CMake and a C++ compiler installed.
Install Raylib (follow the official Raylib installation guide).
Clone the repository and navigate to the project directory.
Create a build directory and run CMake:mkdir build
cd build
cmake ..
make


Run the executable generated in the build directory.

Features

Grid-based gameplay with 20 rows and 10 columns.
Seven standard Tetris block types (I, J, L, O, S, T, Z).
Block movement (left, right, down) and rotation.
Collision detection and row clearing.
Score tracking and display.
Simple user interface with score and next block preview.
Game over detection.

License
This project is licensed under the MIT License - see the LICENSE file for details.
Acknowledgments

Inspired by ProgrammingwithNick's Tetris tutorial series on YouTube.
Built using Raylib for graphics and input handling.
Font files sourced externally (Monogram and Evogria Italic).

Author

Euclidae (GitHub: @Euclidae)

