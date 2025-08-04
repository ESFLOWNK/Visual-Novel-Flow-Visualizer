#include "utils.h"

int getPercentage(int percentage, int of) {
    return ((float) of / 100) * percentage;
}

unsigned char isInside(int ax, int ay, int bx, int by, int bw, int bh) {
    // It checks if a is inside b
    if(ax > bx && ax < bx + bw && ay > by && by < by + bh) {
        return 1;
    }

    return 0;
}