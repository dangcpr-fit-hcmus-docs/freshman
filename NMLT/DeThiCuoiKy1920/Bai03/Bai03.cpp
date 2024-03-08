// Bai03.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <iomanip>
#include <string>
using namespace std;
void NhapMang(string arr[][100], int m, int n)
{
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout << "arr[" << i << "][" << j << "] = ";
            cin >> arr[i][j];
        }
    }
}
void XuatMang(string arr[][100], int m, int n)
{
    cout << "Mang ban vua nhap la: " << endl;
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout << setw(8) << arr[i][j];
        }
    }
}
string s(string arr[][100], int m, int n)
{
    string Xau;
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            Xau += arr[i][j];
            Xau += ' ';
        }
    }
   return Xau;
}
int main()
{
    int n, m; 
    string arr[100][100];
    cin >> m >> n;
    NhapMang(arr, m, n);
    XuatMang(arr, m, n);
    cout << endl << s(arr, m, n);
    return 0;
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
