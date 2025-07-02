#include "draw_components.h"

void gui_initialize(SDL_Renderer *renderer, SDL_Window *screen) {
    plusButton_initialize();
}

void gui_drawInterface() {
    // Create the menu border line
    SDL_Rect menu;
    int windowWidth, windowHeight;

    SDL_GetWindowSize(screen, &windowWidth, &windowHeight); // Get the window size

    menu.w = 3;
    menu.h = windowHeight;
    menu.x = getPercentage(MENU_HSIZE_PERCENTAGE, windowWidth) - menu.w / 2;
    menu.y = 0;

    SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
    SDL_RenderFillRect(renderer, &menu);
    
    // We calculate the position of the button using percentages.
    plusbutton->plusbuttonrect.x = getPercentage(plusbutton->PLUS_BUTTON_XPOS_PERCENTAGE, windowWidth) - plusbutton->plusbuttonrect.w / 2;
    plusbutton->plusbuttonrect.y = getPercentage(plusbutton->PLUS_BUTTON_YPOS_PERCENTAGE, windowHeight) - plusbutton->plusbuttonrect.h / 2;

    // Draw the plus button image
    SDL_RenderCopy(renderer, plusbutton->plusbuttonimg, NULL, &plusbutton->plusbuttonrect);
}

void gui_startDrawing() {
    gui_drawInterface();
}

void gui_freeComponents() {
    // Free the plus button
    SDL_DestroyTexture(plusbutton->plusbuttonimg);
    free(plusbutton);
}