#include <iostream>
#include <windows.h>
#include <conio.h>

#include "Setup.h"

#define boardX 20
#define boardY 5
#define boardW 80
#define boardH 20

Setup::Setup()
{
    _point = 0;
}

//Dich chuyen con tro
void Setup::gotoxy (short x, short y)
{
    HANDLE hConsoleOutput;
    COORD Cursor_an_Pos = {x, y};
    hConsoleOutput = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleCursorPosition(hConsoleOutput , Cursor_an_Pos);
}

//Tuy chon co hien thi con tro hay khong
void Setup::ShowCur(bool CursorVisibility)
{
    HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_CURSOR_INFO cursor = {1, CursorVisibility};
    SetConsoleCursorInfo(handle, &cursor);
}

void Setup::firstSetup()
{
    Setup setup;
    setup.ShowCur(false); //khong hien thi con tro ao

    //ve khung play
    gotoxy(boardX, boardY);
    for(int i = 0; i < boardW; i++)
    {
        std::cout << "-";
    }

    int saveJ = 0;
    for(int j = 1; j < boardH; j++)
    {
        gotoxy(boardX, boardY + j);
        for(int i = 0; i < boardW; i++)
        {
            if(i == 0 || i == boardW - 1) std::cout << "|";
            else std::cout << " ";
        }
        std::cout << std::endl;
        saveJ = j;
    }

    gotoxy(boardX, boardY + saveJ);
    for(int i = 0; i < boardW; i++)
    {
        std::cout << "-";
    }

    system("color 2");
}

void Setup::setPoint()
{
    this->_point++;
}

int Setup::getPoint()
{
    return this->_point;
}

void Setup::printPoint()
{
    gotoxy(3, 5);
    std::cout << "Diem so: " << this->_point;
}

