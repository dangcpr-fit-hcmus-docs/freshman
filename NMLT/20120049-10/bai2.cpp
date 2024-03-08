//2. Nhap 2 so nguyên. Xuat ra màn hình tong, hieu, tích, thuong cua hai so dó.
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
