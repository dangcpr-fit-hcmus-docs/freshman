// Bai02.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
using namespace std;
void NhapMang(int arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << "arr[" << i << "] = ";
        cin >> arr[i];
    }
}
void XuatMang(int arr[], int n)
{
    cout << "Mang ban nhap la: ";
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
}
void reduceArray(int arr[], int& n)
{
    int b[1000];
    int k = 0;
    for (int i = 0; i < n; i++)
    {
        int GTPT = arr[i];
        for (int j = i + 1; j < n; j++)
        {
            if (arr[i] % 2 == 0 && arr[j] % 2 == 0)
            {
                GTPT += arr[j];
                i = j;
            }
            else
            {
                break;
            }
        }
        b[k] = GTPT;
        k++;
    }
    cout << "Mang rut gon la: ";
    for (int i = 0; i < k; i++)
    {
        cout << b[i] << " ";
    }
}
int main()
{
    int n, arr[1000];
    cin >> n;
    NhapMang(arr, n);
    XuatMang(arr, n);
    reduceArray(arr, n);
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
