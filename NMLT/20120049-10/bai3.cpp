//3. Nhap v�o 1 k� tu. Xu?t ra m�n h�nh k� tu d� v� m� ASCII cua n�.
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
