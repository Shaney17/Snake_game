#ifndef SNAKE_H
#define SNAKE_H

#include "Setup.h"
#include "define.h"

#define MAX_DOT 100


enum TrangThai
{
    UP, DOWN, LEFT, RIGHT
};



class Snake
{
    public:
        Snake();
        int getSoDot();
        ToaDo getSnakeToaDo(int i);
        void drawSnake();
        void moveSnake();
        void inputControl();
        bool eat(ToaDo f_fruit);
        void checkWall();
        bool checkHit();
    private:
        ToaDo dot[MAX_DOT];
        int _soDot;
        TrangThai _status;
};

#endif // SNAKE_H
