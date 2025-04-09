#include <iostream>
#include <string>
#include "emp/web/Animate.hpp"
#include "emp/web/web.hpp"

emp::web::Document doc{"target"};
emp::web::Canvas canvas{100, 100, "canvas"};

class NFAnimator : public emp::web::Animate {
   
    public:
    NFAnimator() {
        doc << canvas; //define a constructor and place canvas into doc
        for(int i = 0; i < 101; i += 10) {
            for(int j = 0; j < 101; j += 10) {
                canvas.Rect(i,j,10,10, "white","black");
            }
        }
    }

    // void FindNeighbors(int x, int y) {
           
    //         int a = x - 10;
    //         int b = x + 10;
    //         int c = y - 10;
    //         int d = y + 10;

    //         for(int i = a; i <= b; i += 10) {
    //             for(int j = c; j <= d; j += 10) {
    //                 if(i == -10 and j == -10) {
    //                     canvas.Rect(90, 90, 10, 10, "red", "black");
    //                 }
    //                 else if (i == 100 and j == 100) {
    //                     canvas.Rect(0, 0, 10, 10, "red", "black");
    //                 }
    //                 else if(i == -10) {
    //                     canvas.Rect(90, j, 10, 10, "red", "black");
    //                 }
    //                 else if(j == -10) {
    //                     canvas.Rect(i, 90, 10, 10, "red", "black");
    //                 }
    //                 else if(i == 100) {
    //                     canvas.Rect(0, j, 10, 10, "red", "black");
    //                 }
    //                 else if(j == 100) {
    //                     canvas.Rect(i, 0, 10, 10, "red", "black");
    //                 }
    //                 else {
    //                 canvas.Rect(i, j, 10, 10, "red", "black");
    //                 }
    //             }
    //         }
    //         canvas.Rect(x, y, 10, 10, "black", "black");

    // }
    void FindNeighbors(int x, int y) {
    // Grid dimensions (assuming a 100x100 grid)
    const int gridSize = 100;
    const int cellSize = 10;

    // Helper function to wrap coordinates around the grid
    auto wrap = [gridSize](int coord) { //
        if (coord < 0) return gridSize - cellSize; // Wrap negative to max
        if (coord >= gridSize) return 0;          // Wrap overflow to 0
        return coord;
    };

    // Calculate neighbors
    for (int i = x - cellSize; i <= x + cellSize; i += cellSize) {
        for (int j = y - cellSize; j <= y + cellSize; j += cellSize) {
            // Skip the center cell (x, y) itself
            if (i == x && j == y) continue;

            // Wrap coordinates around the grid
            int wrappedX = wrap(i);
            int wrappedY = wrap(j);

            // Draw the neighbor cell
            canvas.Rect(wrappedX, wrappedY, cellSize, cellSize, "red", "black");
        }
    }
    canvas.Rect(x, y, 10, 10, "black", "black");
}
};

NFAnimator animator;

int main() {
    animator.FindNeighbors(90, 90);
    animator.Step();
}