#include "../includes/cobra.h"

// (x,y) inicial central
u8 x = GRID_W / 2;
u8 y = GRID_H / 2;

void cobraInit(Cobra *cobra) {
 
    cobra->tamanho = 3;
    cobra->direcao = DIR_DIREITA;

    cobra->corpo[0] = (Segmento) {x, y};
    cobra->corpo[1] = (Segmento) {x - 1, y};
    cobra->corpo[2] = (Segmento) {x - 2, y};

}

void cobraDraw(Cobra *cobra) {

    for(int i = 0; i < cobra->tamanho; i++) {
		drawRect(cobra->corpo[i].x, cobra->corpo[i].y, VERDE);
	}

}

void cobraErase(Cobra *cobra) {

    for(int i = 0; i < cobra->tamanho; i++) {
		drawRect(cobra->corpo[i].x, cobra->corpo[i].y, RGB5(0,0,0));
	}

}

void cobraMove(Cobra *cobra) {

    for(int i = cobra->tamanho - 1; i > 0; i--) {
        cobra->corpo[i] = cobra->corpo[i - 1];
    }

    switch (cobra->direcao) {
        case DIR_DIREITA : cobra->corpo[0].x++; break;
        case DIR_ESQUERDA : cobra->corpo[0].x--; break;
        case DIR_CIMA : cobra->corpo[0].y--; break;
        case DIR_BAIXO : cobra->corpo[0].y++; break;
    }

    // resolução de wrap teleporte
    cobra->corpo[0].x = (cobra->corpo[0].x + GRID_W) % GRID_W;
    cobra->corpo[0].y = (cobra->corpo[0].y + GRID_H) % GRID_H;

}

void cobraCtrlDir(Cobra *cobra) {

    scanKeys();
	u16 keys = keysDown();

    if (keys & KEY_UP && cobra->direcao != DIR_BAIXO) {
		cobra->direcao = DIR_CIMA;
	}
	if (keys & KEY_DOWN && cobra->direcao != DIR_CIMA) {
		cobra->direcao = DIR_BAIXO;
	}
	if (keys & KEY_RIGHT && cobra->direcao != DIR_ESQUERDA) {
		cobra->direcao = DIR_DIREITA;
	}
	if (keys & KEY_LEFT && cobra->direcao != DIR_DIREITA) {
		cobra->direcao = DIR_ESQUERDA;
	}

        // teste : faz cobra crescer
    if (keys & KEY_A) {
        cobra->corpo[cobra->tamanho] = cobra->corpo[cobra->tamanho - 1];
        cobra->tamanho++;
    }

}

void cobraGrow(Cobra *cobra) {
    
}

void cobraCheckColision(Cobra *cobra) {

    if (cobra->corpo[0].y == 0 && cobra->direcao == DIR_CIMA) {
        cobra->direcao = DIR_BAIXO;
    }
    if (cobra->corpo[0].y == 39 && cobra->direcao == DIR_BAIXO) {
        cobra->direcao = DIR_CIMA;
    }
    if (cobra->corpo[0].x == 59 && cobra->direcao == DIR_DIREITA) {
        cobra->direcao = DIR_ESQUERDA;
    }
    if (cobra->corpo[0].x == 0 && cobra->direcao == DIR_ESQUERDA) {
        cobra->direcao = DIR_DIREITA;
    }
}