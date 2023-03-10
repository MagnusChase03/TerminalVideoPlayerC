#define STB_IMAGE_IMPLEMENTATION
#include "src/Frame.h"
#include "src/Video.h"

#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>

int main(int argc, char** argv) {

    int maxFrames = 3258;
    Video v = createVideo(maxFrames, 15, 10);
    loadVideo(v, "data/frames");
    playVideo(v);

    freeVideo(v);
    
    return 0;

}
