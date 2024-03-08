#include "Bai2.h"

void input(float& x, unsigned int& n)
{
    cout << "Nhap x: "; cin >> x;
    cout << "Nhap n: "; cin >> n;
}
float F(float x, unsigned int n)
{
	if (n == 0) return 1;
    if (n == 1) return 1 + x / n;
    return F(x, n - 1) + (F(x, n - 1) - F(x, n - 2)) * x / n;
}
float LT(float x, unsigned int n)
{
	float kq = 1;
	for (int i = 1; i <= n; i++)
	{
		kq = kq * x;
	}
	return kq;
}
unsigned long long GT(unsigned int n)
{
	unsigned long long kq = 1;
	for (int i = 1; i <= n; i++)
	{
		kq = kq * i;
	}
	return kq;
}
float Fk(float x, unsigned int n)
{
    float kq = 1;
    for (int i = 1; i <= n; i++)
    {
        kq = kq + LT(x, i) / GT(i);
    }
    return kq;
}
void CauA(float x, unsigned int n) {
    cout << "\nF(" << x << "," << n << ") = " << F(x, n) << " (de quy).";
}
void CauB(float x, unsigned int n) {
    cout << "\n" << x << "^" << n << " = " << LT(x, n);
}
void CauC(float x, unsigned int n) {
    cout << "\n" << n << "! = " << GT(n);
}
void CauD(float x, unsigned int n) {
    cout << "\nF(" << x << "," << n << ") = " << Fk(x, n) << " (vong lap).";
}
void loadMenu()
{
    int choice;
    unsigned int n;
    float x;
    cout << "-----MENU-----\n\n";
    cout << "1. Cau a: Tinh F(x,n) bang de quy.\n";
    cout << "2. Cau b: Tinh x^n.\n";
    cout << "3. Cau c: Tinh n!.\n";
    cout << "4. Cau d: Tinh F(x,n) khong dung de quy.\n";
    cout << "5. Exit.\n\n";
    cout << "Nhap lua chon: "; cin >> choice;
    while (choice < 1 || choice > 5)
    {
        cout << "Nhap lai: "; cin >> choice;
    }
    cout << endl;
    input(x, n);
    switch (choice)
    {
    case 1: {CauA(x, n);  break; }
    case 2: {CauB(x, n); break; }
    case 3: {CauC(x, n); break; }
    case 4: {CauD(x, n);  break; }
    case 5: {exit(0); }
    }
    while (1)
    {
        cout << "\n\nNhap lua chon: "; cin >> choice;
        while (choice < 1 || choice > 5)
        {
            cout << "Nhap lai: "; cin >> choice;
        }
        switch (choice)
        {
        case 1: {CauA(x, n);  break; }
        case 2: {CauB(x, n); break; }
        case 3: {CauC(x, n); break; }
        case 4: {CauD(x, n);  break; }
        case 5: {exit(0); }
        }
    }
}