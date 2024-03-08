#include "Header.h"

constexpr auto maxi = 24;
void FixConsoleWindow() {
    HWND consoleWindow = GetConsoleWindow();
    LONG style = GetWindowLong(consoleWindow, GWL_STYLE);
    style = style & ~(WS_MAXIMIZEBOX) & ~(WS_THICKFRAME);
    SetWindowLong(consoleWindow, GWL_STYLE, style);
}
void BackGroundColor(WORD color)
{
    HANDLE hConsoleOutput;
    hConsoleOutput = GetStdHandle(STD_OUTPUT_HANDLE);

    CONSOLE_SCREEN_BUFFER_INFO screen_buffer_info;
    GetConsoleScreenBufferInfo(hConsoleOutput, &screen_buffer_info);

    WORD wAttributes = screen_buffer_info.wAttributes;
    color &= 0x000f;
    color <<= 4;
    wAttributes &= 0xff0f;
    wAttributes |= color;

    SetConsoleTextAttribute(hConsoleOutput, wAttributes);
}
void TextColor(WORD color)
{
    HANDLE hConsoleOutput;
    hConsoleOutput = GetStdHandle(STD_OUTPUT_HANDLE);

    CONSOLE_SCREEN_BUFFER_INFO screen_buffer_info;
    GetConsoleScreenBufferInfo(hConsoleOutput, &screen_buffer_info);

    WORD wAttributes = screen_buffer_info.wAttributes;
    color &= 0x000f;
    wAttributes &= 0xfff0;
    wAttributes |= color;

    SetConsoleTextAttribute(hConsoleOutput, wAttributes);
}
void gotoxy(short x, short y)
{
    HANDLE hConsoleOutput;
    COORD Cursor_an_Pos = { x,y };
    hConsoleOutput = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleCursorPosition(hConsoleOutput, Cursor_an_Pos);
}
string ConDuong(string**& a, int& n)
{
    a = new string * [6];
    string Tong = "";
    for (int i = 0; i < 5; i++)
    {

        a[i] = new string[30];
        for (int j = 0; j < 30; j++)
        {
            if (j != 29)
            {
                system("cls");
                a[i][j] = "_";
                Tong += a[i][j];
                cout << Tong;
            }
            else
            {
                system("cls");
                a[i][j] = "_|\n";
                Tong += a[i][j];
                cout << Tong;
            }
        }
    }
    for (int j = 0; j < 30; j++)
    {
        a[5][j] = ' ';
        Tong += a[5][j];
    }
    return Tong;

}
void GiaiPhong(string**& a)
{
    for (int i = 0; i < 6; i++)
    {
        delete[] a[i];
    }
    delete[] a;
}
void DiChuyen(string**& a, string Tong)
{
    pos Xe;
    char Press;
    char NC = '0';
    bool Play = 1;
    Xe.x = 5; Xe.y = 0;
    a[Xe.x][Xe.y] = NC;
    cout << '0';
    do
    {
        cout << Tong;
        Press = _getch();
        switch (Press)
        {
        case 37:
            if (Xe.y > 0)
                a[Xe.x][Xe.y--] = NC;
            break;
        case 38:
            if (Xe.x > 0)
                a[Xe.x--][Xe.y] = NC;
            break;
        case 39:
            if (Xe.y < 29)
                a[Xe.x][Xe.y++] = NC;
            break;
        case 40:
            if (Xe.x > 6)
                a[Xe.x++][Xe.y] = NC;
            break;
        case 13:
            GiaiPhong(a);
            Play = 0;
        }
    } while (Play);
}
int TaoVatCan()
{
    int ViTri = rand() % (maxi / 3);
    return ViTri;
}