// Nhap vào so thuc x. Xuat ra giá tri bieu thuc A = 3x3 – 2x2. Ket qua lay 2 chu so sau dau phay thap phân

#include <iostream>
using namespace std;

int main()
{
	float x;
	std::cout << "Nhap so thuc x = ";
	std::cin >> x;
	std::cout << "Gia tri bieu thuc 3x^3 - 2x^2=" << 3 * x * x * x - 2 * x * x;
}
