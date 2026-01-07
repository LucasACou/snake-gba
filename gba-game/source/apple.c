#include "../includes/apple.h"

void appleSpawn(Apple *apple) {

    srand(REG_VCOUNT);

    apple->x = rand() % 58 + 1;
    apple->y = rand() % 38 + 1;

    drawRect(apple->x, apple->y, VERMELHO);
    

}