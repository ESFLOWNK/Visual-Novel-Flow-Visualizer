#include <stdio.h>
#include <SDL2/SDL.h>
#include "draw_components.h"

int main(){
    SDL_Init(SDL_INIT_EVERYTHING);
    SDL_CreateWindowAndRenderer(1024,600, SDL_WINDOW_SHOWN, &screen, &renderer);
    if(!screen) {
        printf("Error ocurred while creating the window.");
        exit(1);
    }
    SDL_SetWindowTitle(screen, "VNFV");
    SDL_SetWindowResizable(screen, SDL_TRUE);
    SDL_SetWindowMinimumSize(screen, 600, 380);

    gui_initialize(renderer, screen);
    draw_loop();

    gui_freeComponents();
    SDL_DestroyRenderer(renderer);
	SDL_DestroyWindow(screen);
	SDL_Quit();
	exit(0);
}