#include "draw_components.h"

typedef struct GuiCollisionCell {
    unsigned char guiElementType; // 0 if nothing
    GuiButton *button;            // guiElementType 1
//  others                        // guiElementType ...

    struct GuiCollisionCell *next;
} GuiCollisionCell;

GuiCollisionCell* guiGrid[12][12];

void setButtonPositionByPercentage(GuiButton *button, int windowWidth, int windowHeight){
    /* 
    Local function that sets a GuiButton x and y position by
    its own position percentages.

    This function uses pointers to modify the values.
    */

    button->buttonrect.x = getPercentageFrom(button->BUTTON_XPOS_PERCENTAGE, windowWidth) - button->buttonrect.w / 2;
    button->buttonrect.y = getPercentageFrom(button->BUTTON_YPOS_PERCENTAGE, windowHeight) - button->buttonrect.h / 2;
}

void gui_addButtonToGuiCollisionCell(GuiButton *button) {
    GuiCollisionCell *guiCellP;
    guiCellP = guiGrid
                [(int) button->BUTTON_XPOS_PERCENTAGE / 9]
                [(int) button->BUTTON_YPOS_PERCENTAGE / 9];

    GuiCollisionCell *buttonCell;
    buttonCell = malloc(sizeof(GuiCollisionCell));
    buttonCell->guiElementType = 1;
    buttonCell->button = button;
    buttonCell->next = guiCellP;
    guiGrid
        [(int) button->BUTTON_XPOS_PERCENTAGE / 9]
        [(int) button->BUTTON_YPOS_PERCENTAGE / 9]
        = buttonCell;
}

void gui_handleClick() {
    SDL_Rect mousePosition;
    mousePosition.w = 1;
    mousePosition.h = 1;
    SDL_GetMouseState(&mousePosition.x, &mousePosition.y);
    int windowWidth, windowHeight;
    SDL_GetWindowSize(screen, &windowWidth, &windowHeight);

    int cellxPos = getPercentageOf(mousePosition.x, windowWidth) / 9;
    int cellyPos = getPercentageOf(mousePosition.y, windowHeight) / 9;
    
    printf("%d %d\n", cellxPos, cellyPos);

    GuiCollisionCell *guiCellP;
    guiCellP = guiGrid[cellxPos][cellyPos];

    while(guiCellP->guiElementType != 0) {
        if(guiCellP->guiElementType == 1) {
            if(guiButton_isClicked(guiCellP->button) == SDL_TRUE) guiButton_setSelected(guiCellP->button,1);
        }

        guiCellP = guiCellP->next;
    }
}

void gui_initialize(SDL_Renderer *renderer, SDL_Window *screen) {
    for(int i = 0; i < 12; i++) {
        for(int j = 0; j < 12; j++) {
            guiGrid[i][j] = malloc(sizeof(GuiCollisionCell));
            if(guiGrid[i][j] == NULL) fprintf(stderr, "Gui collision grid couldn't be allocated");
            guiGrid[i][j]->guiElementType = 0;
            guiGrid[i][j]->next = NULL;
        }
    }

    guiButtons_initialize();
}

void gui_drawInterface() {
    // Create the menu border line
    SDL_Rect menu;
    int windowWidth, windowHeight;

    SDL_GetWindowSize(screen, &windowWidth, &windowHeight); // Get the window size

    menu.w = 3;
    menu.h = windowHeight;
    menu.x = getPercentageFrom(MENU_HSIZE_PERCENTAGE, windowWidth) - menu.w / 2;
    menu.y = 0;

    SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
    SDL_RenderFillRect(renderer, &menu);
    
    // We establish the position of the buttons using percentages.
    setButtonPositionByPercentage(plusbutton, windowWidth, windowHeight);
    setButtonPositionByPercentage(minusbutton, windowWidth, windowHeight);

    // Draw the buttons images
    SDL_RenderCopy(renderer, plusbutton->buttonimg, NULL, &plusbutton->buttonrect);
    SDL_RenderCopy(renderer, minusbutton->buttonimg, NULL, &minusbutton->buttonrect);
}

void gui_startDrawing() {
    gui_drawInterface();
}

void freeCollisionGrid_recursive(GuiCollisionCell *grid) {
    if (grid->guiElementType != 0) {
        freeCollisionGrid_recursive(grid->next);
    }
    else if (grid->guiElementType == 1){
        free(grid->button);
        grid->button = NULL;
    }
    free(grid);
    grid = NULL;
}

void gui_freeComponents() {
    for(int i = 0; i < 12; i++){
        for(int j = 0; j < 12; j++) {
            freeCollisionGrid_recursive(guiGrid[i][j]);
        }
    }
}