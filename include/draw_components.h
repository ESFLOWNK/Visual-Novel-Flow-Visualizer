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

typedef struct Plus_button {
    const int PLUS_BUTTON_XPOS_PERCENTAGE;
    const int PLUS_BUTTON_YPOS_PERCENTAGE;

    const char *UNSELECTED_IMAGE_FILE;
    const char *SELECTED_IMAGE_FILE;

    SDL_Texture *plusbuttonimg;
    SDL_Rect plusbuttonrect;
} Plus_button;

// Global variables

extern SDL_Window *screen;
extern SDL_Renderer *renderer;
extern Plus_button *plusbutton;

// Functions

/*
The drawing loop function. This function runs every function required in
order to draw everything in screen, also listens to the events.
*/
void drawLoop();

/*
Changes the plus button texture from selected to unselected and viceversa.
@param selected Acts as a boolean data type,
if 1 the button will have a selected texture,
if 0 the button will have an unselected texture.
*/
void plusButtonSetSelected(unsigned char selected);

/* 
Initializes a Plus_button struct.
@param button The given button
@param windowWidth The current window width.
@param windowHeight The current window height.
*/
void plusButtonInitialize();

/*
Sets everything up in order to start drawing.

@param . The parameters explain themselves.
*/
void drawInitialize(SDL_Renderer *renderer, SDL_Window *screen);

/*
Draws the interface elements.

@param . The parameters explain themselves.
*/
void drawInterface();

/*
Runs all the functions needed to draw a frame.

@param . The parameters explain themselves.
*/
void startDrawing();

/*
Frees all the pointers allocated.
*/
void freeGuiComponents();

#endif