// Nhap chieu d�i 2 c?nh cua mot h�nh chu nhat. T�nh v� xuat ra chu vi, dien t�ch cua h�nh chu nhat d�

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
