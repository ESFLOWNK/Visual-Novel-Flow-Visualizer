#include "drawgui.h"

void drawInterface(SDL_Renderer *renderer, SDL_Window *screen) {
    SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
    SDL_RenderClear(renderer);

    SDL_Rect menu;
    int windowWidth, windowHeight;

    SDL_GetWindowSize(screen, &windowWidth, &windowHeight);

    menu.w = 3;
    menu.h = windowHeight;
    menu.x = getPercentage(MENU_HSIZE_PERCENTAGE, windowWidth) - menu.w / 2;

    SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
    SDL_RenderFillRect(renderer, &menu);

/*     SDL_Texture *plusbuttonimg;
    SDL_Rect plusbuttonrect;
    plusbuttonimg = IMG_LoadTexture(renderer, "files/images/plusbutton.png");
    plusbuttonrect.w = 30;
    plusbuttonrect.h = 30;
    plusbuttonrect.x = getPercentage(PLUS_BUTTON_XPOS_PERCENTAGE, windowWidth) - plusbuttonrect.w / 2;
    plusbuttonrect.y = getPercentage(PLUS_BUTTON_YPOS_PERCENTAGE, windowHeight) - plusbuttonrect.h / 2;

    SDL_RenderCopy(renderer, plusbuttonimg, NULL, &plusbuttonrect); */
}

void startDrawing(SDL_Renderer *renderer, SDL_Window *screen) {
    drawInterface(renderer, screen);
}