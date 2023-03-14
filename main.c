#define STB_IMAGE_IMPLEMENTATION
#include "src/Frame.h"
#include "src/Video.h"

#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>

int main(int argc, char** argv) {

    int maxFrames = 6572;
    Video v = createVideo(maxFrames, 30, atoi(argv[1]));
    loadVideo(v, "data/frames2");
    playVideo(v);

    freeVideo(v);
    
    return 0;

}
