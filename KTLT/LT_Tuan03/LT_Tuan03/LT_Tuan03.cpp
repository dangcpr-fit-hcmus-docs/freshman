#include <iostream>
#include <memory.h>
using namespace std;
struct Fraction
{
    int TuSo;
    int MauSo;
};
template<class T>
void PhepToan(T* a, int n, bool compare)
{
    T* buf = (T*)calloc(n, sizeof(T));
    if (buf == NULL)
    {
        a[0] = NULL; 
        return;
    }
    if (compare == 1)
    {
        for (int i = 0; i < n; i++)
        {
            for (int j = i + 1; j < n; j++)
            {
                if (*(a + i) < *(a + j))
                {
                    int temp = *(a + i);
                    *(a + i) = *(a + j);
                    *(a + j) = temp;
                }
            }
        }
    }
    else
    {
        for (int i = 0; i < n; i++)
        {
            for (int j = i + 1; j < n; j++)
            {
                if (*(a + i) > *(a + j))
                {
                    int temp = *(a + i);
                    *(a + i) = *(a + j);
                    *(a + j) = temp;
                }
            }
        }
    }
}
template <class T>
void GiaiPhong(T* a)
{
    delete[] a;
}
int main()
{
    int a[] = { 2, 3, 8, 5 };
    //Fraction a[] = { {2,5}, {3, 7}, {4, 6} }
    int n = sizeof(a) / sizeof(a[0]);
    PhepToan(a, n, 0);
    for (int i = 0; i < n; i++)
    {
        cout << a[i] << " ";
    }
    GiaiPhong(a);
    return 0;
}