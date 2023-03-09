#include "Frame.h"

Frame createFrame(int width, int height, int frame) {

    Frame f;
    f.frame = frame;
    f.width = width;
    f.height = height;
    
    f.data = malloc((sizeof(char*) * height));
    for (int i = 0; i < height; i++) {

        f.data[i] = calloc(sizeof(char), width);

    }

    return f;

}

void freeFrame(Frame f) {

    free(f.data);

}

void showFrame(Frame f) {

    for (int i = 0; i < f.height; i++) {

        for (int j = 0; j < f.width; j++) {

            printf("%c", f.data[i][j]);

        }
        printf("\n");

    }

}
