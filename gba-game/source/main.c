
#include <gba_console.h>
#include <gba_interrupt.h>
#include <gba_systemcalls.h>
#include <gba_input.h>
#include <stdio.h>
#include <stdlib.h>

#include "../includes/video.h"
#include "../includes/cobra.h"
#include "../includes/apple.h"

int main(void) {

	irqInit();
	irqEnable(IRQ_VBLANK);

	videoInit();

	Cobra cobra;
	Apple apple;

	cobraInit(&cobra);

	int frame = 0;

	drawWalls();
	
	appleSpawn(&apple);

	while (1) {

		cobraCtrlDir(&cobra);
		cobraCheckColision(&cobra);

		frame++;

		if(frame >= 60 / COBRA_SPEED) {
			frame = 0;
			cobraErase(&cobra);
			cobraMove(&cobra);
		}

		cobraDraw(&cobra);
		

		VBlankIntrWait();
	}
}


