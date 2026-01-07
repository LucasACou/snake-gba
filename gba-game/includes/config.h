#ifndef CONFIG_H
#define CONFIG_H

#include <gba_video.h>

// TELA
#define TILE_SIZE 4
#define GRID_W (SCREEN_WIDTH / TILE_SIZE)
#define GRID_H (SCREEN_HEIGHT / TILE_SIZE)

// COBRA
#define COBRA_SPEED 6
#define MAX_SEGMENTOS (GRID_W * GRID_H)

#endif // CONFIG_H