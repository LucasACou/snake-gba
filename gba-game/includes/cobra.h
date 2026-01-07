#ifndef COBRA_H
#define COBRA_H

#include "config.h"
#include "video.h"
#include <gba_types.h>
#include <gba_input.h>

#define VERDE RGB5(0, 31, 0)

typedef enum direcao{
    DIR_DIREITA  = 0,
    DIR_ESQUERDA = 1,
    DIR_CIMA     = 2,
    DIR_BAIXO    = 3
} Direcao;

typedef struct segmento{
    s16 x;
    s16 y;
} Segmento;

typedef struct cobra{
    Segmento corpo[MAX_SEGMENTOS];
    u16 tamanho;
    Direcao direcao;
} Cobra;

void cobraInit(Cobra *cobra);
void cobraDraw(Cobra *cobra);
void cobraErase(Cobra *cobra);
void cobraMove(Cobra *cobra);
void cobraCtrlDir(Cobra *cobra);
void cobraGrow(Cobra *cobra);
void cobraCheckColision(Cobra *cobra);

#endif // COBRA_H