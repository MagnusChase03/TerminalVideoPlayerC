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

Frame readFrame(char* filepath, int frame, int scale) {

    int width, height, bpp;
    uint8_t* rgb_image = stbi_load(filepath, &width, &height, &bpp, 3);

    Frame f = createFrame(width / scale, height / scale, frame);
    for (int i = 0; i < height; i+= scale) {

        for (int j = 0; j < width; j += scale) {

            int y = i * width * 3;
            int x = 3 * j;

            if (rgb_image[y + x] > 60) {

                f.data[i / scale][j / scale] = ' ';

            } else {

                f.data[i / scale][j / scale] = '#';

            }

        }

    }

    stbi_image_free(rgb_image);

    return f;

}

void showFrame(Frame f) {

    for (int i = 0; i < f.height; i++) {

        for (int j = 0; j < f.width; j++) {

            printf("%c", f.data[i][j]);

        }
        printf("\n");

    }

}
