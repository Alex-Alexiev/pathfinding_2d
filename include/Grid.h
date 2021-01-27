#ifndef GRID_H_
#define GRID_H_

#include <SFML/Graphics.h>

#include "Geometry.h"

typedef struct grid{
    int height;
    int width;
    int density;
    int ySpots;
    int xSpots;
    int numOccupied;
    int *array; 
} grid;

grid *nvGrid_create(int height, int width, int density);

void nvGrid_occupySpot(grid *g, int x, int y);

void nvGrid_print(grid *g);

int nvGrid_isOccupied(grid *g, int r, int c);

geVec2d *nvGrid_getOccupied(grid *g);

void nvGrid_draw(grid *g, sfRenderWindow *window);

void nvGrid_drawSpot(grid *g, int x, int y, sfColor color, sfRenderWindow *window);

#endif