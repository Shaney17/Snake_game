#ifndef SETUP_H
#define SETUP_H


class Setup
{
    public:
        Setup();
        int getPoint();
        void setPoint();
        void printPoint();
        void gotoxy (short x, short y);
        void ShowCur(bool CursorVisibility);
        void firstSetup();

    private:
        int _point;
};

#endif // SETUP_H
