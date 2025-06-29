#ifndef DRAWGUI_H
#define DRAWGUI_H

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

#include <errno.h>
#include <stdio.h>

#include "utils.h"

#define MENU_HSIZE_PERCENTAGE 20
#define PLUS_BUTTON_XPOS_PERCENTAGE 5
#define PLUS_BUTTON_YPOS_PERCENTAGE 95

void drawInterface(SDL_Renderer *renderer, SDL_Window *screen);
void startDrawing(SDL_Renderer *renderer, SDL_Window *screen);

#endif