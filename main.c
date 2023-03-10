#define STB_IMAGE_IMPLEMENTATION
#include "src/Frame.h"

#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>

int main() {

    int maxFrames = 3258;
    Frame* frames = calloc(sizeof(Frame), maxFrames);

    for (int i = 1; i < maxFrames; i++) {

        printf("Loading frame %d\n", i);
        char filepath[200];
        sprintf(filepath, "data/frames/output%d.png", i);

        Frame f = readFrame(filepath, i, 8);
        frames[i - 1] = f;
    
    }
    
    for (int i = 0; i < maxFrames; i++) {

        usleep(60000);
        printf("\e[1;1H\e[2J");
        showFrame(frames[i]);
        freeFrame(frames[i]);

    }

    free(frames);
    
    return 0;

}
