// Nhap chieu dài 2 c?nh cua mot hình chu nhat. Tính và xuat ra chu vi, dien tích cua hình chu nhat dó

#include <iostream>
using namespace std;

int main()
{
	int x, y;
	cout << "Nhap chieu dai va chieu rong: ";
	cin >> x;
	cin >> y;
	cout << "Chu vi: " << (x + y) * 2 << "\n";
	cout << "Dien tich: " << x*y << "\n";
	return 0;
}
