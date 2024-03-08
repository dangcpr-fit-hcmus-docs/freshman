//3. Nhap vào 1 ký tu. Xu?t ra màn hình ký tu dó và mã ASCII cua nó.
#include <iostream>
using namespace std;

int main()
{
	char kitu;
	std::cout << "Nhap ki tu: ";
	std::cin >> kitu;
	std::cout << "Ma ASCII cua ki tu do la: " << int(kitu) << "\n";
	return 0;
}
