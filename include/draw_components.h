#ifndef DRAW_COMPONENTS_H
#define DRAW_COMPONENTS_H

// Includes

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

#include <errno.h>
#include <stdio.h>

#include "utils.h"

// Consts

#define MENU_HSIZE_PERCENTAGE 20

// Structs

typedef struct GuiButton {
    const int BUTTON_XPOS_PERCENTAGE;
    const int BUTTON_YPOS_PERCENTAGE;

    const char *UNSELECTED_IMAGE_FILE;
    const char *SELECTED_IMAGE_FILE;

    SDL_Texture *buttonimg;
    SDL_Rect buttonrect;
} GuiButton;

typedef struct GuiButtonNode {
    GuiButton *button;
    GuiButton *next;
} GuiButtonNode;

// Global variables

extern SDL_Window *screen;
extern SDL_Renderer *renderer;
extern GuiButton *plusbutton;
extern GuiButton *minusbutton;

// Functions

/*
Runs all the functions needed to draw a frame: gui functions, etc.
*/
void draw_startDrawing();

/*
The drawing loop function. This function runs every function required in
order to draw everything in screen, also listens to the events.
*/
void draw_loop();

/*
This function checks if the plus button is being pressed;

Returns:
SDL_bool It is SDL_TRUE if the button is being pressed, otherwise it's SDL_FALSE.
*/
SDL_bool guiButton_isClicked(GuiButton *button);

/*
Changes the plus button texture from selected to unselected and viceversa.
@param selected Acts as a boolean data type,
if 1 the button will have a selected texture,
if 0 the button will have an unselected texture.
*/
void guiButton_setSelected(GuiButton *button, unsigned char selected);

/* 
Initializes the GUI plus button, which is a GuiButton struct.
*/
void guiButtons_initialize();

/*
Sets everything up in order to start drawing the GUI.

@param renderer Is the renderer
@param screen Is the window
*/
void gui_initialize(SDL_Renderer *renderer, SDL_Window *screen);

/*
Draws the interface elements.
*/
void gui_drawInterface();

/*
Runs all the functions needed to draw the GUI elements in a frame.
*/
void gui_startDrawing();

/*
Frees all the pointers allocated.
*/
void gui_freeComponents();

#endif