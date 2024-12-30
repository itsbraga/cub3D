#include <stdio.h>
#include <stdlib.h>

#define GRID_SIZE 20

// Fonction pour initialiser la grille avec des points
void initGrid(char grid[GRID_SIZE][GRID_SIZE]) {
    for (int i = 0; i < GRID_SIZE; i++) {
        for (int j = 0; j < GRID_SIZE; j++) {
            grid[i][j] = '.';
        }
    }
}

// Fonction pour afficher la grille
void displayGrid(char grid[GRID_SIZE][GRID_SIZE]) {
    for (int i = 0; i < GRID_SIZE; i++) {
        for (int j = 0; j < GRID_SIZE; j++) {
            printf("%c ", grid[i][j]);
        }
        printf("\n");
    }
}

// Algorithme de Bresenham pour tracer une ligne
void bresenhamLine(char grid[GRID_SIZE][GRID_SIZE], int x1, int y1, int x2, int y2) {
    int dx = abs(x2 - x1);
    int dy = abs(y2 - y1);
    printf("dx = %d\ndy = %d\n", dx, dy);
    int sx = (x1 < x2) ? 1 : -1;
    int sy = (y1 < y2) ? 1 : -1;
    int err = (dx > dy ? dx : -dy) / 2;
    int e2;

    while (1) {
        if (x1 >= 0 && x1 < GRID_SIZE && y1 >= 0 && y1 < GRID_SIZE) {
            grid[y1][x1] = '*';
        }
        
        if (x1 == x2 && y1 == y2) {
            break;
        }

        e2 = err;
        if (e2 > -dx) {
            err -= dy;
            x1 += sx;
        }
        if (e2 < dy) {
            err += dx;
            y1 += sy;
        }
    }
}

int main() {
    char grid[GRID_SIZE][GRID_SIZE];
    
    // Initialisation de la grille
    initGrid(grid);
    
    // Tracer une ligne diagonale de (2,2) à (17,17)
    bresenhamLine(grid, 15, 2, 7, 16);
    
    // Affichage de la grille
    displayGrid(grid);
    
    return 0;
}
