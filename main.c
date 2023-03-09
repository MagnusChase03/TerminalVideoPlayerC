#define STB_IMAGE_IMPLEMENTATION

#include "src/Frame.h"
#include "lib/stb_image.h"

#include <stdlib.h>
#include <stdio.h>
#include <stdint.h>

Frame readFrame(char* framePath) {

    int width, height, bpp;
    uint8_t* rgb_image = stbi_load(framePath, &width, &height, &bpp, 3);

    Frame f = createFrame(width / 10, height / 10, 1);

    for (int i = 0; i < height; i += 10) {

        for (int j = 0; j < width; j += 10) {

            int y = (i * width * 3);
            int x = (3 * j);

            if (rgb_image[y + x] == 255) {
    
                f.data[i / 10][j / 10] = ' ';

            } else {

                f.data[i / 10][j / 10] = '#';

            }

        }

    }

    stbi_image_free(rgb_image);

    return f;

}

int main() {

    Frame f = readFrame("data/frames/output500.png");
    showFrame(f);
    freeFrame(f);
    return 0;

}
