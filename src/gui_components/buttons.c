#include "draw_components.h"

SDL_bool plusButton_isClicked() {
    SDL_Rect mousePosition;
    mousePosition.w = 1;
    mousePosition.h = 1;
    SDL_GetMouseState(&mousePosition.x, &mousePosition.y);
    return SDL_HasIntersection(&plusbutton->plusbuttonrect, &mousePosition);
}

void plusButton_setSelected(unsigned char selected) {
    // It's not that difficult to read, if selected equals 1, selected, if 0, unselected.
    if(selected) {
        plusbutton->plusbuttonimg = IMG_LoadTexture(renderer, plusbutton->SELECTED_IMAGE_FILE);
    } else if (selected == 0) {
        plusbutton->plusbuttonimg = IMG_LoadTexture(renderer, plusbutton->UNSELECTED_IMAGE_FILE);
    }
}

void plusButton_initialize() {
    // Allocates memory for the struct instance
    plusbutton = malloc(sizeof(GuiButton));

    //  So, how am I adding a value to a const?
    //  I saw this in a Google Gemini code (I don't have enough money to pay a ChatGPT suscription).
    //  For what I understood, now the const is converted to a int*, and we use pointers
    // to assign a value to the const var. 
    *(int *) &plusbutton->PLUS_BUTTON_XPOS_PERCENTAGE = 5;
    *(int *) &plusbutton->PLUS_BUTTON_YPOS_PERCENTAGE = 95;

    // Same happens here.
    *(char **) &plusbutton->UNSELECTED_IMAGE_FILE = "files/images/plusbutton.png";
    *(char **) &plusbutton->SELECTED_IMAGE_FILE = "files/images/plusbutton_selected.png";

    // Here we seek for the default plus button image.
    plusbutton->plusbuttonimg = IMG_LoadTexture(renderer, plusbutton->UNSELECTED_IMAGE_FILE);

    // Get the window size
    int windowWidth, windowHeight;
    SDL_GetWindowSize(screen, &windowWidth, &windowHeight);

    // We set the button width and height.
    plusbutton->plusbuttonrect.w = 30;
    plusbutton->plusbuttonrect.h = 30;

    // We calculate the position of the button using percentages.
    plusbutton->plusbuttonrect.x = getPercentage(plusbutton->PLUS_BUTTON_XPOS_PERCENTAGE, windowWidth) - plusbutton->plusbuttonrect.w / 2;
    plusbutton->plusbuttonrect.y = getPercentage(plusbutton->PLUS_BUTTON_YPOS_PERCENTAGE, windowHeight) - plusbutton->plusbuttonrect.h / 2;
}