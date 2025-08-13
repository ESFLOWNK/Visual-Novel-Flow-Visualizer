#include "draw_components.h"

typedef struct GuiCollisionCell {
    unsigned char guiElementType;
    GuiButtonNode *button; // guiElementType 0
//  others                 // guiElementType ...
} GuiCollisionCell;

void setButtonPositionByPercentage(GuiButton *button, int windowWidth, int windowHeight){
    /* 
    Local function that sets a GuiButton x and y position by
    its own position percentages.

    This function uses pointers to modify the values.
    */

    button->buttonrect.x = getPercentage(button->BUTTON_XPOS_PERCENTAGE, windowWidth) - button->buttonrect.w / 2;
    button->buttonrect.y = getPercentage(button->BUTTON_YPOS_PERCENTAGE, windowHeight) - button->buttonrect.h / 2;
}

void gui_initialize(SDL_Renderer *renderer, SDL_Window *screen) {
    guiButtons_initialize();
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
    
    // We calculate the position of the buttons using percentages.
    setButtonPositionByPercentage(plusbutton, windowWidth, windowHeight);
    setButtonPositionByPercentage(minusbutton, windowWidth, windowHeight);

    // Draw the buttons images
    SDL_RenderCopy(renderer, plusbutton->buttonimg, NULL, &plusbutton->buttonrect);
    SDL_RenderCopy(renderer, minusbutton->buttonimg, NULL, &minusbutton->buttonrect);
}

void gui_startDrawing() {
    gui_drawInterface();
}

void gui_freeComponents() {
    SDL_DestroyTexture(plusbutton->buttonimg);  // Free the plus button
    free(plusbutton);
    SDL_DestroyTexture(minusbutton->buttonimg); // Free the minus button
    free(minusbutton);
}