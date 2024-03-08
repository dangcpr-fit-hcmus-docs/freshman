#include <iostream>
#include <iomanip>
#include <fstream>

using namespace std;
int DocDuLieu(int arr[]);
double TrungBinhCong(int arr[], int n);
void GhiFile(int arr[]);
int main()
{
	int arr[100];
	GhiFile(arr);
	return 0;
}
int DocDuLieu(int arr[])
{
	int n;
	fstream f;
	f.open("INPUT.txt", ios::in);
	f >> n;
	for (int i = 0; i < n; i++)
	{
		f >> arr[i];
	}
	return n;
	f.close();
}
double TrungBinhCong(int arr[], int n)
{
	int Tong = 0, NgDuong = 0;
	double TB;
	for (int i = 0; i < n; i++)
	{
		if (arr[i] > 0)
		{
			NgDuong++;
			Tong += arr[i];
		}
	}
	if (NgDuong == 0) { TB = 0; }
	else { TB = (1. * Tong) / NgDuong; }
	return TB;
}
void GhiFile(int arr[])
{
	int n = DocDuLieu(arr);
	double TB = TrungBinhCong(arr, n);
	fstream f;
	f.open("OUTPUT.txt", ios::out);
	f << "{" << endl << "\t\"DanhSach\": [";
	for (int i = 0; i < n; i++)
	{
		f << arr[i];
		if (i != n - 1) { f << ","; }
	}
	f << "],";
	if (TB != 0) { f << endl << "\t\"TrungBinhCong\":" << setprecision(2) << fixed << TB; }
	else { f << endl << "\t\"TrungBinhCong\":" << TB; }
	f << endl << "}";
	f.close();
}