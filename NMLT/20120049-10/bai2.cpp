//2. Nhap 2 so nguy�n. Xuat ra m�n h�nh tong, hieu, t�ch, thuong cua hai so d�.
#include <iostream>
using namespace std;
int main()
{
	int a, b;
	std::cout << "Nhap hai so a va b: ";
	std::cin >> a;
	std::cin >> b;
	std::cout << "Tong = " << a + b << "\n" << endl;
	std::cout << "Hieu = " << a - b << "\n" << endl;
	std::cout << "Tich = " << a * b << "\n" << endl;
	std::cout << "Thuong = " << (a*1.0) / (b*1.0) << "\n" << endl;
	return 0;
}
