#include <iostream>
#include <math.h>
using namespace std;
/* point type */
struct Diem {
	int x, y;
};
/* tam giac type */
struct tamgiac {
	Diem A, B, C;
};
/* Mang tam giac */
struct MangTG {
	int sz;
	tamgiac* T;
};
void NhapDiem(Diem& ToaDo)
{
	cout << "(x, y) = ";
	cin >> ToaDo.x >> ToaDo.y;
}
void XuatDiem(Diem ToaDo)
{
	cout << "Diem ban nhap la (" << ToaDo.x << "," << ToaDo.y << ").";
}
float KhoangCach(int x1, int y1, int x2, int y2)
{
	return sqrt((x1 * x1 - x2 * x2) * (x1 * x1 - x2 * x2) - (y1 * y1 - y2 * y2) * (y1 * y1 - y2 * y2));
}
bool KTTamGiac(tamgiac TG)
{
	float a = KhoangCach(TG.A.x, TG.A.y, TG.B.x, TG.B.y);
	float b = KhoangCach(TG.B.x, TG.B.y, TG.C.x, TG.C.y);
	float c = KhoangCach(TG.C.x, TG.C.y, TG.A.x, TG.A.y);
	if (a + b > c && a + c > b && b + c > a)
	{
		return 1;
	}
	else
	{
		return 0;
	}
}
void NhapTamGiac(tamgiac& TG)
{
	cout << "Nhap diem A";
	NhapDiem(TG.A);
	XuatDiem(TG.A); cout << endl;
	cout << "Nhap diem B";
	NhapDiem(TG.B);
	XuatDiem(TG.B); cout << endl;
	cout << "Nhap diem C";
	NhapDiem(TG.C);
	XuatDiem(TG.C); cout << endl;
}
float C(tamgiac TG) //Chu vi tam giac
{
	float a = KhoangCach(TG.A.x, TG.A.y, TG.B.x, TG.B.y);
	float b = KhoangCach(TG.B.x, TG.B.y, TG.C.x, TG.C.y);
	float c = KhoangCach(TG.C.x, TG.C.y, TG.A.x, TG.A.y);
	return a + b + c;
}
float S(tamgiac TG) //Dien tich tam giac
{
	float a = KhoangCach(TG.A.x, TG.A.y, TG.B.x, TG.B.y);
	float b = KhoangCach(TG.B.x, TG.B.y, TG.C.x, TG.C.y);
	float c = KhoangCach(TG.C.x, TG.C.y, TG.A.x, TG.A.y);
	return sqrt(C(TG) / 2 * (C(TG) / 2 - a) * (C(TG) / 2 - b) * (C(TG) / 2 - c));
}
void NhapMangTamGiac(MangTG& MTG)
{
	cout << "Nhap so tam giac: ";
	cin >> MTG.sz;
	MTG.T = (tamgiac*)malloc(MTG.sz * sizeof(tamgiac));
	for (int i = 0; i < MTG.sz; i++)
	{
		cout << "Nhap tam giac T[" << i << "]:\n";
		NhapTamGiac(*(MTG.T + i));
	}
}
int TamGiacSMax(MangTG MTG) //Tam giac co dien tich lon nhat
{
	int n = 0;
	for (int i = 0; i < MTG.sz; i++)
	{
		if (KTTamGiac(*(MTG.T + i)) == 1)
		{
			n == i;
			break;
		}
	}
	for (int i = 0; i < MTG.sz; i++)
	{
		if (KTTamGiac(*(MTG.T + i)) > KTTamGiac(*(MTG.T + n)))
		{
			n == i;
		}
	}
	return n;
}
void ThemTamGiac(MangTG& MTG, int& n)
{
	cout << "Vi tri them: "; cin >> n;
	MTG.sz++;
	MTG.T = (tamgiac*)realloc(MTG.T, MTG.sz * sizeof(tamgiac));
	cout << "Them tam giac: ";
	for (int i = MTG.sz - 1; i >= n + 1; i--)
	{
		MTG.T[i] = MTG.T[i - 1];
	}
	NhapTamGiac(*(MTG.T + n));
}
int main()
{
	MangTG MTG; int n;
	NhapMangTamGiac(MTG);
	cout << "Tam giac co dien tich lon nhat la tam giac T[" << TamGiacSMax(MTG) << "]\n";
	ThemTamGiac(MTG, n);
	XuatDiem((MTG.T)->A);
	XuatDiem((MTG.T + 1)->A);
	XuatDiem((MTG.T + 2)->A);
	free(MTG.T);
	return 1;
}