#ifndef FRUIT_H
#define FRUIT_H

#include "define.h"

class fruit
{
    public:
        fruit();
        ToaDo getFruitToaDo();
        void drawFruit();
        void newToaDo();

    private:
        ToaDo _toaDo;
};

#endif // FRUIT_H
