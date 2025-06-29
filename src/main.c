#include <stdio.h>
#include <SDL2/SDL.h>
#include "drawgui.h"

SDL_Window *screen = NULL;
SDL_Renderer *renderer;
SDL_Event event;

void loop(){
    unsigned char running = 1;
    
    while(running) {
        startDrawing(renderer, screen);

        SDL_RenderPresent(renderer);

        while(SDL_PollEvent(&event)){
            switch(event.type) {
                case SDL_QUIT:
                     running = 0;
                     break;
            }
        }
    }
}

int main(){
    SDL_Init(SDL_INIT_EVERYTHING);
    SDL_CreateWindowAndRenderer(1024,600, SDL_WINDOW_SHOWN, &screen, &renderer);
    if(!screen) {
        printf("Error ocurred while creating the window.");
        exit(1);
    }
    SDL_SetWindowTitle(screen, "VNFV");
    SDL_SetWindowResizable(screen, SDL_TRUE);

    loop();

    SDL_DestroyRenderer(renderer);
	SDL_DestroyWindow(screen);
	SDL_Quit();
	exit(0);
}