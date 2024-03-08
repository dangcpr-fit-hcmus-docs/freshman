// Bai01.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
using namespace std;
bool SoNguyenTo(int n)
{
    bool NgTo = 1;
    if (n == 0 || n == 1) { return 0; }
    for (int i = 2; i <= n - 1; i++)
    {
        if (n % i == 0)
        {
            NgTo = 0;
            break;
        }
    }
    return NgTo;
}
void CapSoNguyenTo(int N)
{
    int TimThay = 0;
    bool NgTo = 1;
    for (int i = 2; i < N; i++)
    {
        if (SoNguyenTo(i) == 1)
        {
            int j = N - i;
            if (SoNguyenTo(j) == 1)
            {
                cout << "(" << i << "," << j << ");";
                TimThay++;
                break;
            }
        }
    }
    if (TimThay == 0) { cout << "Khong tim thay"; }
}
int main()
{
    int n;
    cin >> n;
    CapSoNguyenTo(n);
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
