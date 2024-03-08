// bai02.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
using namespace std;
void NhapMang(int arr[], int n)
{
	for (int i = 0; i < n; i++)
	{
		cin >> arr[i];
	}
}
void XuatMang(int arr[], int n)
{
	cout << "Mang vua nhap la: ";
	for (int i = 0; i < n; i++)
	{
		cout << arr[i] << ' ' << endl;
	}
}
void ViTri(int arr[], int n)
{
	cout << "Cac vi tri thoa man la: ";
	for (int i = 0; i < n; i++)
	{
		if (i == 0)
		{
			if (arr[i] < arr[i + 1])
			{
				cout << i << ' ';
			}
		}
		else
		{
			if (i == n - 1)
			{
				if (arr[i - 1] > arr[i])
				{
					cout << i << ' ';
				}
			}
			else
			{
				if (arr[i - 1] > arr[i] && arr[i + 1] > arr[i])
				{
					cout << i << ' ';
				}
			}
		}
	}
}
int main()
{
	int n, arr[100];
	cin >> n;
	NhapMang(arr, n);
	XuatMang(arr, n);
	ViTri(arr, n);
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
