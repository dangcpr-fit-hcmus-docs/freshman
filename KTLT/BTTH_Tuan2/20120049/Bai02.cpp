#include <iostream>
#include <memory.h>
#include <malloc.h>
using namespace std;
void NhapMang(int*& arr, int& n)
{
    arr = new int[n];
    for (int i = 0; i < n; i++)
    {
        cout << "arr[" << i << "] = ";
        cin >> *(arr + i);
    }
}
int* ViTri(int* arr, const int& n, int x)
{
    int* p = NULL;
    int t = 0;
    for (int i = 0; i < n; i++)
    {
        if (x == *(arr + i))
        {
            t++;
            p = (int*)realloc(p, t * sizeof(int));
            *(p + t - 1) = i;
        }
    }
    return p;
}
int main()
{
    int n, x;
    int* arr;
    cout << "So luong phan tu: ";
    cin >> n;
    NhapMang(arr, n);
    cout << "Phan tu can xet: ";
    cin >> x;
    cout << "Nhung vi tri thoa man la: ";
    int BoNho = _msize(ViTri(arr, n, x));
    for (int i = 0; i < BoNho / sizeof(int); i++)
    {
        cout << ViTri(arr, n, x)[i] << " ";
    }
    free(ViTri(arr, n, x));
    delete[] arr;
    return 0;
}