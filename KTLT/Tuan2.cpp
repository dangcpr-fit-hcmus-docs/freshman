#include <iostream>
using namespace std;

int n;
void InputArray1D(int*& a, int& n)
{
    a = new int[n];
    for (int i = 0; i < n; i++)
    {
        cout << "Xin hay nhap phan tu thu " << i + 1 << ":";
        cin >> a[i];
    }
}
void OutputArray1D(int*& a, int& n)
{
    for (int i = 0; i < n; i++)
    {
        cout << "Day la phan tu thu " << i + 1 << " trong mang:" << *(a + i) << endl;
    }
}
void FreeArray1D(int*& a)
{
    delete[] a;
    cout << "Mang vua duoc cap phat da bi huy!";
}
void InputArray2D(int**& a, int n)
{
    a = new int *[n];
    for (int i = 0; i < n; i++)
    {
        a[i] = new int[n];
        for (int j = 0; j < n; j++)
        {
            cout << "Xin hay nhap phan tu a[" << i << "][" << j << "]: ";
            cin >> a[i][j];
        }
    }
}
void OutputArray2D(int**& a, int n)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout << "a[" << i << "][" << j << "]: " << a[i][j]<<endl;
        }
    }
}
void FreeArray2D(int**& a, int& n)
{
    for (int i = 0; i < n; i++)
        delete[] a[i];
    delete[] a;
    cout << "Mang 2 chieu vua duoc cap phat da bi huy!";
}
int main()
{
    int* a = NULL;
    cout << "Day la bai 1:" << endl;
    cout << "Moi thay nhap so phan tu n cua mang 1 chieu :";
    cin >> n;
    InputArray1D(a, n);
    OutputArray1D(a, n);
    FreeArray1D(a);
    int** b = NULL;
    cout << endl;
    cout << "Day la bai 2: " << endl;
    cout << "Moi thay nhap so phan tu n cua ma tran vuong:";
    cin >> n;
    InputArray2D(b, n);
    OutputArray2D(b, n);
    FreeArray2D(b, n);
}

