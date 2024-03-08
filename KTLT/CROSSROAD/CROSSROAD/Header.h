#include <iostream>
#include <Windows.h>
#include <cstdlib>
#include <ctime>
#include <string>
#include <conio.h>
struct pos
{
    int x;
    int y;
};
using namespace std;

void FixConsoleWindow();
void BackGroundColor(WORD color);
void TextColor(WORD color);
void gotoxy(short x, short y);
string ConDuong(string**& a, int& n);
void GiaiPhong(string**& a);
void DiChuyen(string**& a, string Tong);
int TaoVatCan();

