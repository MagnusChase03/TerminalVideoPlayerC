#include "Video.h"

Video createVideo(int totalFrames, int fps, int scale) {

    Video v;
    v.totalFrames = totalFrames;
    v.fps = fps;
    v.scale = scale;

    v.frames = calloc(sizeof(Frame), totalFrames);

    return v;

}

void freeVideo(Video v) {

    for (int i = 0; i < v.totalFrames; i++) {

        freeFrame(v.frames[i]);

    }

    free(v.frames);

}

typedef struct {

    Video *v;
    char* filepath;
    int frame;
    int workload;

} ThreadArgs;

void* loadFrameThread(void* args) {

    ThreadArgs data = *((ThreadArgs*) args);

    for (int i = 0; i < data.workload && data.frame + i < data.v->totalFrames; i++) {
    
        char filepath2[200] = "";
        sprintf(filepath2, "%s/output%d.png", data.filepath, data.frame + i);

        Frame f = readFrame(filepath2, data.frame + i, data.v->scale);
        data.v->frames[data.frame + i - 1] = f;

    }

    free(args);

}

void loadVideo(Video v, char* filepath) {

    int workload = v.totalFrames / 8;

    pthread_t threads[8];
    int threadNum = 0;
    for (int i = 1; i < v.totalFrames; i += workload) {

        ThreadArgs* data = calloc(sizeof(ThreadArgs), 1);
        data->v = &v;
        data->filepath = filepath;
        data->frame = i; 
        data->workload = workload;

        pthread_t tid;
        pthread_create(&tid, NULL, loadFrameThread, (void*) data);

        threads[threadNum] = tid;
        threadNum += 1;

    }

    for (int i = 0; i < 8; i++) {

        pthread_join(threads[i], NULL);

    }

}

void playVideo(Video v) {

    for (int i = 0; i < v.totalFrames; i++) {

        double sleepTime = (double) 1.0 / v.fps * 1000000.0;
        usleep(sleepTime);
        printf("\e[1;1H\e[2J");
        showFrame(v.frames[i]);

    } 

}
