#include <stdio.h>
#include <time.h>
#include <stdlib.h>

#define boardX 20
#define boardY 5
#define boardW 80
#define boardH 20

#include "define.h"
#include "fruit.h"
#include "Setup.h"

Setup setup;

fruit::fruit()
{
    _toaDo.x = 30;
    _toaDo.y = 15;
}

ToaDo fruit::getFruitToaDo()
{
    return _toaDo;
}

void fruit::drawFruit()
{
    setup.gotoxy(_toaDo.x, _toaDo.y);
    putchar('O');
}

void fruit::newToaDo()
{
    srand(time(NULL));
    //toa do x trong khoang tu (boardX + 1) den (boardX + boardW - 2)
    _toaDo.x = rand()%(boardW - 2) + boardX + 1;
    _toaDo.y = rand()%(boardH - 2) + boardY + 1;
}
