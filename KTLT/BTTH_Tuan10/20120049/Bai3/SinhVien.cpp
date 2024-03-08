#include "SinhVien.h"

void Ini(SinhVien& sv)
{
	memset(sv.maso, 0, sizeof(sv.maso));
	memset(sv.hoten, 0, sizeof(sv.hoten));
	memset(sv.ngaysinh, 0, sizeof(sv.ngaysinh));
	sv.Diem = 0;
}
void Input(SinhVien& sv)
{
	cout << "Ma so: ";
	cin.get(sv.maso, 9);
	cin.ignore();
	cout << "Ho ten: ";
	cin.get(sv.hoten, 30);
	cin.ignore(); 
	cout << "Ngay sinh: ";
	cin.get(sv.ngaysinh, 11);
	cout << "Diem: ";  cin >> sv.Diem;
	cin.ignore();
}

void Output(SinhVien sv)
{
	cout << "Ma so: " << sv.maso << " - ";
	cout << "Ho ten: " << sv.hoten << " - ";
	cout << "Ngay sinh: " << sv.ngaysinh << " - ";
	cout << "Diem: " << sv.Diem << endl;
}


