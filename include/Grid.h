#ifndef GRID_H_
#define GRID_H_

#include <SFML/Graphics.h>

typedef struct Grid Grid;

Grid *nvGrid_new(int height, int width, int density);

void nvGrid_occupySpot(Grid *g, int y, int x);

void nvGrid_print(Grid *g);

int nvGrid_isOccupied(Grid *g, int r, int c);

sfVector2f *nvGrid_getOccupied(Grid *g);

void nvGrid_draw(Grid *g, sfRenderWindow *window);

#endif