#include "Header.h"

int main()
{
	string** a; int n;
    char Press; int x = 0, y = 0;
	FixConsoleWindow();
	BackGroundColor(7);
	TextColor(0);
    /*
    gotoxy(x, y);
    do
    {
        Press = _getch();
        switch (Press)
        {
        case 'a':
            if (x > 0)
                gotoxy(x--, y);
            break;
        case 'w':
            if (y > 0)
                gotoxy(x, y--);
            break;
        case 'd':
            //if (x < 29)
                gotoxy(x++, y);
            break;
        case 's':
            //if (y < 6)
                gotoxy(x, y++);
            break;
        }
    } while (1);
    */
}