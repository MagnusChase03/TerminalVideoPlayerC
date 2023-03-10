#ifndef FrameH
#define FrameH

#include "../lib/stb_image.h"

#include <stdlib.h>
#include <stdio.h>
#include <stdint.h>

typedef struct {

    int frame;
    int width;
    int height;
    char** data;

} Frame;

Frame createFrame(int width, int height, int frame);
void freeFrame(Frame f);

Frame readFrame(char* filepath, int frame, int scale);

void showFrame(Frame f);

#endif
