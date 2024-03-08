#include "Header.h"

int main()
{
	string** a; int n;
    char Press; int x = 0, y = 0;
	FixConsoleWindow();
	BackGroundColor(7);
	TextColor(0);
    gotoxy(x, y);
    do
    {
        Press = _getch();
        switch (Press)
        {
        case 97:
            if (x > 0)
                gotoxy(x--, y);
            break;
        case 119:
            //if (y > 0)
                gotoxy(x, y--);
            break;
        case 100:
            //if (x < 29)
                gotoxy(x++, y);
            break;
        case 115:
            //if (y > 6)
                gotoxy(x, y++);
            break;
        }
    } while (1);
}