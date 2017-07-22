#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <fstream>

using namespace std;

#include "Setup.h"
#include "Menu.h"
#include "Snake.h"
#include "fruit.h"

#define titleX 10
#define titleY 10
#define titleW 100
#define titleH 4


void greet()
{
    fstream file;
    file.open("./views/greet.txt", ios::in);

    string menu[6];

    for(int i = 0; i < 6; i++)
    {
        getline(file, menu[i], ',');
    }
    file.close();

    for(int i = 0; i < titleX; i++)
        cout << " ";

    for(int i = 0; i < titleW; i++)
        cout << "=";

    cout << endl;

    for(int j = 1; j < titleH; j++)
    {
        if(j == titleH/2) printf("%65s", menu[0].c_str()) ;
        cout << endl;
    }

    for(int i = 0; i < titleX; i++)
        cout << " ";

    for(int i = 0; i < titleW; i++)
        cout << "=";

    cout << endl;
    cout << endl;

    printf("%55s \n \n", menu[1].c_str());
    printf("%51s \n \n", menu[2].c_str());
    printf("%57s \n \n", menu[3].c_str());
    printf("%57s \n \n", menu[4].c_str());

    printf("%50s", menu[5].c_str());

}


void menu()
{
    bool endGame = false;

    while(!endGame)
    {
        system("cls");
        greet();
        int luaChon = 0;
        cin >> luaChon;

        switch(luaChon)
        {
        case 1:
            if(!play()) break;
        case 2:
            printHighScore();
            break;
        case 3:
            huongDanChoi();
            break;
        case 4:
            system("cls");
            endGame = true;
            cout << "Ban da thoat tro choi\n\n\n";
            break;
        }
    }


}

bool play()
{
    int tocDo = changeDifficult();
    system("cls");

    Setup setup;
    setup.firstSetup();

    Snake snake;
    fruit fruit;

    while(!snake.checkHit())
    {
        setup.printPoint();
        snake.drawSnake();
        fruit.drawFruit();

        if(snake.eat(fruit.getFruitToaDo()))
        {
            for(int i = 0; i < snake.getSoDot(); i++)
            {
                fruit.newToaDo();
                if(fruit.getFruitToaDo().x != snake.getSnakeToaDo(i).x && fruit.getFruitToaDo().y != snake.getSnakeToaDo(i).y)
                    break;
            }
            setup.setPoint();
        }

        snake.inputControl();
        snake.moveSnake();
        snake.checkWall();
        Sleep(tocDo);
    }

    checkHighScore(setup.getPoint());

    setup.gotoxy(50, 0);
    cout << "****  GAME OVER  ****" << endl;
    system("PAUSE");

    return snake.checkHit();
}

void checkHighScore(int newScore)
{
    fstream file;
    file.open("score.txt", ios::in);

    string tmpScore[10];
    int intScore[10];
    for(int i = 0; i < 10; i++)
    {
        getline(file, tmpScore[i], ',');
        intScore[i] = atoi(tmpScore[i].c_str());
    }
    file.close();

    for(int i = 0; i < 10; i++)
    {
        if(newScore > intScore[i])
        {
            intScore[i] = newScore;
            break;
        }
    }

    file.open("score.txt", ios::out);
    for(int i = 0; i < 10; i++)
        file << intScore[i] << ",";
    file.close();
}

int changeDifficult()
{
    fstream file;
    file.open("./views/difficult.txt", ios::in);

    string difficult[5];

    for(int i = 0; i < 5; i++)
    {
        getline(file, difficult[i], ',');
    }
    file.close();

    int doKho = 0;
    int tocDo = 0;

    system("cls");
    printf("\n\n");
    printf("%50s\n\n", difficult[0].c_str());
    printf("%47s\n\n", difficult[1].c_str());
    printf("%55s\n\n", difficult[2].c_str());
    printf("%48s\n\n", difficult[3].c_str());

    printf("%45s", difficult[4].c_str());
    cin >> doKho;

    switch(doKho)
    {
    case 1:
        tocDo = 200;
        break;
    case 2:
        tocDo = 100;
        break;
    case 3:
        tocDo = 30;
        break;
    }

    return tocDo;
}

void printHighScore()
{
    fstream file;
    file.open("score.txt", ios::in);

    string tmpScore[10];
    int intScore[10];
    for(int i = 0; i < 10; i++)
    {
        getline(file, tmpScore[i], ',');
        intScore[i] = atoi(tmpScore[i].c_str());
    }
    file.close();

    system("cls");
    printf("\n\n");
    printf("%40s", "DIEM CAO:\n\n");
    for(int i = 0; i < 10; i++)
    {
        printf("%45d %d \n", i + 1, intScore[i]);
    }

    system("PAUSE");
}

void huongDanChoi()
{
    fstream file;
    file.open("./views/howtoplay.txt", ios::in);

    string howtoplay[4];

    for(int i = 0; i < 4; i++)
    {
        getline(file, howtoplay[i], ',');
    }
    file.close();

    system("cls");
    printf("\n\n\n\n\n");
    printf("%50s\n\n", howtoplay[0].c_str());
    printf("%116s\n\n", howtoplay[1].c_str());
    printf("%69s\n\n", howtoplay[2].c_str());
    printf("%70s\n\n\n\n\n", howtoplay[3].c_str());
    system("PAUSE");
}
