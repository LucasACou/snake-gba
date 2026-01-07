#ifndef VIDEO_H
#define VIDEO_H

#include "config.h"
#include <gba_video.h>
#include <gba_types.h>

#define VID_MEM ((u16*)VRAM)
#define CINZA_ESCURO RGB5(12, 12, 12)
#define CINZA_CLARO RGB5(20, 20, 20)

void videoInit();
void drawPixel(int x, int y, u16 color);
void drawRect(int x, int y, u16 color);
void drawWalls();


#endif // VIDEO_H