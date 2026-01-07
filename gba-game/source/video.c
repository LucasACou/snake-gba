#include "../includes/video.h"


void videoInit () {

    REG_DISPCNT = MODE_3 | BG2_ENABLE;
    
}

// coordenadas (x,y) em pixel
void drawPixel (int x, int y, u16 color) {

    VID_MEM[y * 240 + x] = color;

}

// coodernadas (x,y) em grid
void drawRect(int x, int y, u16 color) {

    int px = x * TILE_SIZE;
    int py = y * TILE_SIZE;

    for (int y = 0; y < TILE_SIZE; y++)
        for (int x = 0; x < TILE_SIZE; x++)
            drawPixel(px + x, py + y, color);
}

void drawWalls() {

    for (int ty = 0; ty < GRID_H; ty++) {
        for (int tx = 0; tx < GRID_W; tx++) {

            if (tx == 0 || ty == 0 || tx == GRID_W - 1 || ty == GRID_H - 1){
                drawRect(tx,ty,CINZA_CLARO);
            }
        }
    }
}