#include <stdlib.h>

#include <SFML/Graphics.h>

#include "Array2dUtil.h"
#include "Geometry.h"
#include "Grid.h"

grid *nvGrid_create(int height, int width, int density){
    grid *tempGrid = (grid *)malloc(sizeof(grid));
    tempGrid->height = height;
    tempGrid->width = width;
    tempGrid->density = density;
    int ySpots = height*density;
    tempGrid->ySpots = ySpots;
    int xSpots = width*density;
    tempGrid->xSpots = xSpots; 
    tempGrid->numOccupied = 0;
    tempGrid->array = (int *)malloc(sizeof(int)*ySpots*xSpots);
    for (int r = 0; r < ySpots; r++){
        for (int c = 0; c < xSpots; c++){
            *(tempGrid->array + r*xSpots + c) = 0;
        }
    }
    return tempGrid;
}

void nvGrid_occupySpot(grid *g, int x, int y){
    *(g->array + y*g->xSpots + x) = 1;
    g->numOccupied++;
}

void nvGrid_print(grid *g){
    utArray2d_print(g->array, g->xSpots, g->ySpots);
}

int nvGrid_isOccupied(grid *g, int x, int y){
    return *(g->array + y*g->xSpots + x) == 1;
}

geVec2d *nvGrid_getOccupied(grid *g){
    geVec2d *positions = (geVec2d *)malloc(sizeof(geVec2d)*g->numOccupied);
    int counter = 0;
    for (int r = 0; r < g->ySpots; r++){
        for (int c = 0; c < g->xSpots; c++){
            if (nvGrid_isOccupied(g, c, r) == 1){
                positions[counter++] = (geVec2d){c, r};
            }
        }
    }
    return positions;
}

void nvGrid_drawSpot(grid *g, int x, int y, sfColor color, sfRenderWindow *window){
    sfRectangleShape *rect = sfRectangleShape_create();
    sfRectangleShape_setFillColor(rect, color);
    sfVector2u windowSize = sfRenderWindow_getSize(window);
    sfVector2f rectSize = {windowSize.x/g->xSpots, windowSize.y/g->ySpots};
    sfVector2f rectPosition = {x*rectSize.x, y*rectSize.y};
    sfRectangleShape_setSize(rect, rectSize);
    sfRectangleShape_setPosition(rect, rectPosition);
    sfRenderWindow_drawRectangleShape(window, rect, NULL);
    sfRectangleShape_destroy(rect);
}

void nvGrid_draw(grid *g, sfRenderWindow *window){
    geVec2d *rectPositions = nvGrid_getOccupied(g);
    for (int i = 0; i < g->numOccupied; i++){
        nvGrid_drawSpot(g, rectPositions[i].x, rectPositions[i].y, sfWhite, window);
    }
}