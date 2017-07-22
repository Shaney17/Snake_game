#include <iostream>
#include <time.h>
#include <stdlib.h>
#include <stdio.h>
#include <conio.h>

#include "define.h"
#include "Snake.h"
#include "Setup.h"

#define snakeX 25
#define snakeY 10
#define soDotBanDau 3

Setup setupSnake;

Snake::Snake()
{
    dot[0].x = snakeX;
    dot[0].y = snakeY;
    dot[0].ox = 0;
    dot[0].oy = 0;

    _soDot = soDotBanDau;

    for(int i = 1; i < _soDot; i++)
    {
        dot[i].x = dot[i - 1].x - 1;
        dot[i].y = dot[i - 1].y;
        dot[i].ox = 0;
        dot[i].oy = 0;
    }

    _status = RIGHT;
}

int Snake::getSoDot()
{
    return this->_soDot;
}

ToaDo Snake::getSnakeToaDo(int i)
{
    return this->dot[i];
}

void Snake::drawSnake()
{
    for(int i = 0; i < _soDot; i++)
    {
        setupSnake.gotoxy(this->dot[i].x, this->dot[i].y);
        putchar('*');
        setupSnake.gotoxy(this->dot[i].ox, this->dot[i].oy);
        putchar(' ');
    }
}

void Snake::moveSnake()
{
    for(int i = this->_soDot - 1; i > 0; i--)
    {
        this->dot[i].ox = this->dot[i].x;
        this->dot[i].oy = this->dot[i].y;
        this->dot[i].x = this->dot[i - 1].x;
        this->dot[i].y = this->dot[i - 1].y;
    }

    switch(this->_status)
    {
    case UP:
        this->dot[0].oy = this->dot[0].y;
        this->dot[0].y--;
        break;
    case DOWN:
        this->dot[0].oy = this->dot[0].y;
        this->dot[0].y++;
        break;
    case LEFT:
        this->dot[0].ox = this->dot[0].x;
        this->dot[0].x--;
        break;
    case RIGHT:
        this->dot[0].ox = this->dot[0].x;
        this->dot[0].x++;
        break;
    }
}

void Snake::inputControl()
{
    if(_kbhit())
    {
        switch(getch())
        {
        case 'a':
            if(this->_status == RIGHT) break;
            this->_status = LEFT;
            break;
        case 'd':
            if(this->_status == LEFT) break;
            this->_status = RIGHT;
            break;
        case 'w':
            if(this->_status == DOWN) break;
            this->_status = UP;
            break;
        case 's':
            if(this->_status == UP) break;
            this->_status = DOWN;
            break;
        }
    }
}

bool Snake::eat(ToaDo f_ToaDo)
{
    if(f_ToaDo.x == this->dot[0].x && f_ToaDo.y == this->dot[0].y)
    {
        this->_soDot++;
        return true;
    }
    return false;
}

void Snake::checkWall()
{
    if(this->dot[0].x == (boardX + boardW - 1) && this->_status == RIGHT) this->dot[0].x = boardX + 1;
    if(this->dot[0].x == boardX && this->_status == LEFT) this->dot[0].x = boardX + boardW - 2;
    if(this->dot[0].y == (boardY + boardH - 1) && this->_status == DOWN) this->dot[0].y = boardY + 1;
    if(this->dot[0].y == boardY && this->_status == UP) this->dot[0].y = boardY + boardH - 2;
}

bool Snake::checkHit()
{
    for(int i = 1; i < this->_soDot; i++)
    {
        if(this->dot[0].x == this->dot[i].x && this->dot[0].y == this->dot[i].y)
            return true;
    }
    return false;
}
