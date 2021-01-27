#include <stdio.h>
#include <stdlib.h>

#include <SFML/Graphics.h>

#include "Array2dUtil.h"
#include "Grid.h"
#include "NavSpace.h"

int main(){

    grid *testGrid = nvGrid_create(10, 10, 2);
    
    for (int i = 0; i < 10; i++){
        nvGrid_occupySpot(testGrid, 10, i+5);
    }

    geVec2d start = {0, 0};
    geVec2d end = {19, 19};

    navSpace *testNavSpace = nvNavSpace_create(testGrid, start, end);


    //printf("%d\n", testGrid->numOccupied);
    //nvGrid_print(testGrid);
    
    sfVideoMode mode = {200, 200, 32};
    sfRenderWindow *mainWindow = sfRenderWindow_create(mode, "RRT", sfDefaultStyle, NULL);
    // sfCircleShape *circle = sfCircleShape_create();
    // sfCircleShape_setFillColor(circle, sfGreen);
    // sfCircleShape_setRadius(circle, 100);

    sfRectangleShape *testRect = sfRectangleShape_create();
    sfRectangleShape_setFillColor(testRect, sfGreen);
    sfRectangleShape_setPosition(testRect, (sfVector2f){100, 50});
    sfRectangleShape_setSize(testRect, (sfVector2f){10, 10});

    sfEvent event;
    sfFloatRect view_rectangle = {0, 0, 0, 0};
    sfView *new_view = sfView_createFromRect(view_rectangle);

    while(sfRenderWindow_isOpen(mainWindow)){
        
        while(sfRenderWindow_pollEvent(mainWindow, &event)){
            if (event.type == sfEvtClosed){
                sfRenderWindow_close(mainWindow);
            } else if (event.type == sfEvtResized){
                view_rectangle.width = event.size.width;
                view_rectangle.height = event.size.height;
                sfView_reset(new_view, view_rectangle);
                sfRenderWindow_setView(mainWindow, new_view);
            }
        }

        sfRenderWindow_clear(mainWindow, sfBlack);
        nvNavSpace_draw(testNavSpace, mainWindow);
        //sfRenderWindow_drawCircleShape(mainWindow, circle, NULL);
        //sfRenderWindow_drawRectangleShape(mainWindow, testRect, NULL);
        sfRenderWindow_display(mainWindow);

    }

    //sfCircleShape_destroy(circle);
    sfRenderWindow_destroy(mainWindow);
    
}

