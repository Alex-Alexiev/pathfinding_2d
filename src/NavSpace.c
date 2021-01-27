#include <stdlib.h>

#include <SFML/Graphics.h>

#include "NavSpace.h"
#include "Grid.h"

navSpace *nvNavSpace_create(grid *g, geVec2d start, geVec2d end){
    navSpace *tempNavSpace = (navSpace *)malloc(sizeof(navSpace));
    tempNavSpace->grid = g;
    tempNavSpace->start = start;
    tempNavSpace->end = end;
    return tempNavSpace;
}

void nvNavSpace_draw(navSpace *n, sfRenderWindow *window){
    nvGrid_draw(n->grid, window);
    nvGrid_drawSpot(n->grid, n->start.x, n->start.y, sfGreen, window);
    nvGrid_drawSpot(n->grid, n->end.x, n->end.y, sfRed, window);
}