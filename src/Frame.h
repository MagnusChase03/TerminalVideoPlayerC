#ifndef FrameH
#define FrameH

#include <stdlib.h>
#include <stdio.h>

typedef struct {

    int frame;
    int width;
    int height;
    char** data;

} Frame;

Frame createFrame(int width, int height, int frame);
void freeFrame(Frame f);

void showFrame(Frame f);

#endif
