#include "draw_components.h"

SDL_Window *screen = NULL;
SDL_Renderer *renderer = NULL;
SDL_Event event;
Plus_button *plusbutton = NULL;

void drawLoop(){
    unsigned char running = 1;
    
    while(running) {
        SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
        SDL_RenderClear(renderer);
        
        startDrawingGui(renderer, screen);

        SDL_RenderPresent(renderer);

        while(SDL_PollEvent(&event)){
            switch(event.type) {
                case SDL_QUIT:
                    running = 0;
                    break;

                case SDL_MOUSEBUTTONDOWN:
                    plusButtonSetSelected(1);
                    break;
                
                case SDL_MOUSEBUTTONUP:
                    plusButtonSetSelected(0);
                    break;
            }
        }
    }
}