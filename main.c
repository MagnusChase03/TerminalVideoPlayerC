#define STB_IMAGE_IMPLEMENTATION

#include "src/Frame.h"
#include "lib/stb_image.h"

#include <stdlib.h>
#include <stdio.h>
#include <stdint.h>

int main() {

    int width, height, bpp;

    uint8_t* rgb_image = stbi_load("data/frames/output1.png", &width, &height, &bpp, 3);
    printf("Read %dx%d\n", width, height);

    stbi_image_free(rgb_image);

    return 0;

}
