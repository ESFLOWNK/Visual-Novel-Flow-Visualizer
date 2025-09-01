#include "draw_components.h"

SDL_Window *screen = NULL;
SDL_Renderer *renderer = NULL;
SDL_Event event;

void draw_startDrawing() {
    SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
    SDL_RenderClear(renderer);
    
    gui_startDrawing();

    SDL_RenderPresent(renderer);
}

void draw_loop(){
    /*
    Status:
        0 -> Not running
        1 -> Just running
        2 -> Resized
    */
    unsigned char status = 1;
    
    draw_startDrawing();

    while(status > 0) {
        while(SDL_PollEvent(&event)){
            switch(event.type) {
                case SDL_MOUSEBUTTONDOWN:
                    gui_handleClickDown();
                    draw_startDrawing();
                    break;
                
                case SDL_MOUSEBUTTONUP:
                    gui_handleClickUp();
                    draw_startDrawing();
                    break;

                case SDL_WINDOWEVENT:
                    if(event.window.event == SDL_WINDOWEVENT_RESIZED)
                        status = 2;
                    break;

                case SDL_QUIT:
                    status = 0;
                    break;
            }
        }

        if(status == 2) {
            draw_startDrawing();
            status = 1;
        }
    }
}