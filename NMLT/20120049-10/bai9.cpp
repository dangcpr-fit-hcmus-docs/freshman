// Tính dien tích hình sau (phan duoc tô xám). Biet rang các tam giác thành phan là tam giác deu và duoc ve doi xung. Du lieu deu vào là chieu dài canh tam giác deu và bán kính hình tròn.
#define _USE_MATH_DEFINES
#include <iostream>
#include <math.h>
using namespace std;
int main()
{
	float a, R;
	cout << "Nhap chieu dai canh tam giac deu a = ";
	cin >> a;
	cout << "Nhap ban kinh hinh tron R = ";
	cin >> R;
	cout << "Dien tich phan duoc to xam la " << ((a * a * sqrt(3)) / 4) * 3 + 0.5 * M_PI * R * R << "\n";
	return 0;
}
