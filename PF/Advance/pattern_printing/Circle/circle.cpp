/**
  Copyright (c) 2024          
                              
  Name: MUHAMMAD AHMAD.       
                              
  Project Name: PF.          
                              
  Date: 2024-06-29.  
           
  TIME: 11:36 PM.
*/
#include <iostream>
#include <windows.h> // For Windows-specific functions

void gotoRowCol(int row, int col) {
    COORD coord;
    coord.X = col;
    coord.Y = row;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

void plotCirclePoints(int xc, int yc, int x, int y) {
    gotoRowCol(yc + y, xc + x);
    std::cout << '*';
    gotoRowCol(yc + y, xc - x);
    std::cout << '*';
    gotoRowCol(yc - y, xc + x);
    std::cout << '*';
    gotoRowCol(yc - y, xc - x);
    std::cout << '*';
    gotoRowCol(yc + x, xc + y);
    std::cout << '*';
    gotoRowCol(yc + x, xc - y);
    std::cout << '*';
    gotoRowCol(yc - x, xc + y);
    std::cout << '*';
    gotoRowCol(yc - x, xc - y);
    std::cout << '*';
}

void drawCircle(int xc, int yc, int r) {
    int x = 0;
    int y = r;
    int d = 3 - 2 * r;
    plotCirclePoints(xc, yc, x, y);
    while (y >= x) {
        x++;
        if (d > 0) {
            y--;
            d = d + 4 * (x - y) + 10;
        } else {
            d = d + 4 * x + 6;
        }
        plotCirclePoints(xc, yc, x, y);
    }
}

int main() {
    int xc = 40; // X-coordinate of the center
    int yc = 12; // Y-coordinate of the center
    int radius = 10; // Radius of the circle

    // Clear the console screen
    system("CLS");

    drawCircle(xc, yc, radius);

    // Move cursor to the bottom to avoid overwriting the circle
    gotoRowCol(yc + radius + 2, 0);

    return 0;
}
