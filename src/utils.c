#include "utils.h"

int getPercentageFrom(int percentage, int of) {
    return ((float) of / 100) * percentage;
}

int getPercentageOf(int percentage, int of){
    return ((float) 100 / of) * percentage;
}

unsigned char isInside(int ax, int ay, int bx, int by, int bw, int bh) {
    // It checks if a is inside b
    if(ax > bx && ax < bx + bw && ay > by && by < by + bh) {
        return 1;
    }

    return 0;
}