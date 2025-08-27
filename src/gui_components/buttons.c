#include "draw_components.h"

GuiButton *plusbutton = NULL;
GuiButton *minusbutton = NULL;

SDL_bool guiButton_isClicked(GuiButton *button) {
    SDL_Rect mousePosition;
    mousePosition.w = 1;
    mousePosition.h = 1;
    SDL_GetMouseState(&mousePosition.x, &mousePosition.y);
    return SDL_HasIntersection(&button->buttonrect, &mousePosition);
}

void guiButton_setSelected(GuiButton *button, unsigned char selected) {
    // It's not that difficult to read, if selected equals 1, selected, if 0, unselected.
    if(selected) {
        button->buttonimg = IMG_LoadTexture(renderer, button->SELECTED_IMAGE_FILE);
    } else if (selected == 0) {
        button->buttonimg = IMG_LoadTexture(renderer, button->UNSELECTED_IMAGE_FILE);
    }
}

void guiButtons_initialize() {
    // Plus button initialization

    // Allocates memory for the struct instance
    plusbutton = malloc(sizeof(GuiButton));

    //  So, how am I adding a value to a const?
    //  I saw this in a Google Gemini code (I don't have enough money to pay a ChatGPT suscription).
    //  For what I understood, now the const is converted to a int*, and we use pointers
    // to assign a value to the const var. 
    *(int *) &plusbutton->BUTTON_XPOS_PERCENTAGE = 5;
    *(int *) &plusbutton->BUTTON_YPOS_PERCENTAGE = 95;

    // Same happens here.
    *(char **) &plusbutton->UNSELECTED_IMAGE_FILE = "files/images/plusbutton.png";
    *(char **) &plusbutton->SELECTED_IMAGE_FILE = "files/images/plusbutton_selected.png";

    // Here we seek for the default plus button image.
    plusbutton->buttonimg = IMG_LoadTexture(renderer, plusbutton->UNSELECTED_IMAGE_FILE);

    // Get the window size
    int windowWidth, windowHeight;
    SDL_GetWindowSize(screen, &windowWidth, &windowHeight);

    // We set the button width and height.
    plusbutton->buttonrect.w = 30;
    plusbutton->buttonrect.h = 30;
        
    // We calculate the position of the button using percentages.
    plusbutton->buttonrect.x = getPercentageFrom(plusbutton->BUTTON_XPOS_PERCENTAGE, windowWidth) - plusbutton->buttonrect.w / 2;
    plusbutton->buttonrect.y = getPercentageFrom(plusbutton->BUTTON_YPOS_PERCENTAGE, windowHeight) - plusbutton->buttonrect.h / 2;
        
    gui_addButtonToGuiCollisionCell(plusbutton); // Add clicking detection to the button

    // Minus button initialization
    minusbutton = malloc(sizeof(GuiButton));

    *(int *) &minusbutton->BUTTON_XPOS_PERCENTAGE = 10;
    *(int *) &minusbutton->BUTTON_YPOS_PERCENTAGE = 95;

    *(char **) &minusbutton->UNSELECTED_IMAGE_FILE = "files/images/minusbutton.png";
    *(char **) &minusbutton->SELECTED_IMAGE_FILE = "files/images/minusbutton_selected.png";

    minusbutton->buttonimg = IMG_LoadTexture(renderer, minusbutton->UNSELECTED_IMAGE_FILE);

    minusbutton->buttonrect.w = 30;
    minusbutton->buttonrect.h = 30;

    minusbutton->buttonrect.x = getPercentageFrom(minusbutton->BUTTON_XPOS_PERCENTAGE, windowWidth) - minusbutton->buttonrect.w / 2;
    minusbutton->buttonrect.y = getPercentageFrom(minusbutton->BUTTON_YPOS_PERCENTAGE, windowHeight) - minusbutton->buttonrect.h / 2;

    gui_addButtonToGuiCollisionCell(minusbutton); // Add clicking detection to the button
}