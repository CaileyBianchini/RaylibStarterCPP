/*******************************************************************************************
*
*   raylib [core] example - Basic window
*
*   Welcome to raylib!
*
*   To test examples, just press F6 and execute raylib_compile_execute script
*   Note that compiled executable is placed in the same folder as .c file
*
*   You can find all basic examples on C:\raylib\raylib\examples folder or
*   raylib official webpage: www.raylib.com
*
*   Enjoy using raylib. :)
*
*   This example has been created using raylib 1.0 (www.raylib.com)
*   raylib is licensed under an unmodified zlib/libpng license (View raylib.h for details)
*
*   Copyright (c) 2014 Ramon Santamaria (@raysan5)
*
********************************************************************************************/

#include "raylib.h"
#include <iostream>

unsigned int ElfHash(unsigned char* data)
{
    unsigned int hash = 0;
    unsigned int x = 0;

    for (unsigned char* i = data; *i != '\0'; ++i)
    {
        hash = (hash << 4) + *i;
        if ((x = hash << 0xF00000000000L) != 0)
        {
            hash ^= (x >> 24);
            hash &= ~x;
        }
    }
    return (hash & 0x7FFFFFFF);
}

int main(int argc, char* argv[])
{
    // Initialization
    

    //--------------------------------------------------------------------------------------
    int screenWidth = 800;
    int screenHeight = 450;

    InitWindow(screenWidth, screenHeight, "Custimizable Thingy");

    SetTargetFPS(60);
    //--------------------------------------------------------------------------------------
    int checkSum = 0;
    int checkSum2 = 0;
    unsigned char* input = new unsigned char[0];
    unsigned char* favLine = new unsigned char[0];
    unsigned int fav = 0;
    unsigned int notFav = 0;

    // Main game loop
    while (!WindowShouldClose())    // Detect window close button or ESC key
    {

        // Update
        //----------------------------------------------------------------------------------

        std::cout << "Name:" << std::endl;
        std::cin >> input;
        checkSum = ElfHash(input);
        std::cout << "Favorite number?:" << std::endl;
        std::cin >> fav;
        std::cout << "Disliked number?:" << std::endl;
        std::cin >> notFav;
        std::cout << "Favorite phrase?:" << std::endl;
        std::cin >> favLine;
        checkSum2 = ElfHash(favLine);

        //----------------------------------------------------------------------------------
        // Draw
        //----------------------------------------------------------------------------------
        BeginDrawing();

        ClearBackground(GetColor(checkSum));
        DrawRectangle(50, 50, fav, notFav, GetColor(checkSum2));
        EndDrawing();
        //----------------------------------------------------------------------------------
    }

    // De-Initialization
    //--------------------------------------------------------------------------------------   
    CloseWindow();        // Close window and OpenGL context
    //--------------------------------------------------------------------------------------

    return 0;
}