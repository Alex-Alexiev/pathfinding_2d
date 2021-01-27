#ifndef NAVSPACE_H_
#define NAVSPACE_H_

#include "Grid.h"
#include "Geometry.h"

typedef struct navSpace {
    grid *grid;
    geVec2d start;
    geVec2d end;
} navSpace;

navSpace *nvNavSpace_create(grid *g, geVec2d start, geVec2d end);

void nvNavSpace_draw(navSpace *n, sfRenderWindow *window);

#endif