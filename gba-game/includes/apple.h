#ifndef APPLE_H
#define APPLE_H

#include <gba_types.h>
#include <stdlib.h>
#include <time.h>
#include "../includes/video.h"

#define VERMELHO RGB5(31, 0, 0)

typedef struct apple {
    s16 x;
    s16 y;
} Apple;

void appleSpawn(Apple *apple);


#endif // APPLE_H