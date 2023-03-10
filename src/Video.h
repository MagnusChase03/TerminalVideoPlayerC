#ifndef VideoH
#define VideoH

#include "Frame.h"

#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <pthread.h>

typedef struct {

    int totalFrames;
    int fps;
    int scale;
    Frame* frames;

} Video;

Video createVideo(int totalFrames, int fps, int scale);
void freeVideo(Video v);

void loadVideo(Video v, char* filepath);
void playVideo(Video v);

#endif
