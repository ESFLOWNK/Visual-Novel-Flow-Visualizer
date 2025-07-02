#include "draw_components.h"

SDL_Window *screen = NULL;
SDL_Renderer *renderer = NULL;
SDL_Event event;
GuiButton *plusbutton = NULL;

void draw_loop(){
    unsigned char running = 1;
    
    while(running) {
        SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
        SDL_RenderClear(renderer);
        
        gui_startDrawing(renderer, screen);

        SDL_RenderPresent(renderer);

        while(SDL_PollEvent(&event)){
            switch(event.type) {
                case SDL_QUIT:
                    running = 0;
                    break;

                case SDL_MOUSEBUTTONDOWN:
                    if(plusButton_isClicked() == SDL_TRUE)
                        plusButton_setSelected(1);
                    break;
                
                case SDL_MOUSEBUTTONUP:
                    plusButton_setSelected(0);
                    break;
            }
        }
    }
}