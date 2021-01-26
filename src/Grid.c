#include <SFML/Graphics.h>
#include "Array2dUtil.h"

typedef struct Grid{
    int height;
    int width;
    int density;
    int ySpots;
    int xSpots;
    int numOccupied;
    int *array; 
} Grid;

Grid *nvGrid_new(int height, int width, int density){
    Grid *tempGrid = (Grid *)malloc(sizeof(Grid));
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

void nvGrid_occupySpot(Grid *g, int y, int x){
    *(g->array + y*g->xSpots + x) = 1;
    g->numOccupied++;
}

void nvGrid_print(Grid *g){
    utArray2d_print(g->array, g->xSpots, g->ySpots);
}

int nvGrid_isOccupied(Grid *g, int r, int c){
    return *(g->array + r*g->xSpots + c) == 1;
}

sfVector2f *nvGrid_getOccupied(Grid *g){
    sfVector2f *positions = (sfVector2f *)malloc(sizeof(sfVector2f)*g->numOccupied);
    int counter = 0;
    for (int r = 0; r < g->ySpots; r++){
        for (int c = 0; c < g->xSpots; c++){
            if (nvGrid_isOccupied(g, r, c) == 1){
                positions[counter++] = (sfVector2f){r, c};
            }
        }
    }
    return positions;
}

void nvGrid_draw(Grid *g, sfRenderWindow *window){
    sfVector2f *rectPositions = nvGrid_getOccupied(g);
    for (int i = 0; i < g->numOccupied; i++){
        sfRectangleShape *rect = sfRectangleShape_create();
        sfRectangleShape_setFillColor(rect, sfGreen);
        sfVector2u windowSize = sfRenderWindow_getSize(window);
        sfVector2f rectSize = {windowSize.x/g->xSpots, windowSize.y/g->ySpots};
        sfRectangleShape_setSize(rect, rectSize);
        sfRectangleShape_setPosition(rect, (sfVector2f){rectPositions[i].y*rectSize.y, rectPositions[i].x*rectSize.x});
        sfRenderWindow_drawRectangleShape(window, rect, NULL);
        sfRectangleShape_destroy(rect);
    }
}
