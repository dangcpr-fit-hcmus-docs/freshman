#include <iostream>
#include <memory.h>
using namespace std;
enum type { increase, decrease };
template<class T>
void PhepToan(T* a, int n, type compare)
{
    T* buf = (T*)malloc(sizeof(T) * n);
    if (buf == NULL)
    {
        return;
    }
    if (compare == increase)
    {
        for (int i = 0; i < n; i++)
        {
            for (int j = i + 1; j < n; j++)
            {
                if (*(a + i) < *(a + j))
                {
                    T temp = *(a + i);
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
                    T temp = *(a + i);
                    *(a + i) = *(a + j);
                    *(a + j) = temp;
                }
            }
        }
    }
}
template <class U>
void GiaiPhong(U* a)
{
    free(a);
}
int main()
{
    string a[] = { "all", "taa", "bcc", "ddf" };
    //float a[] = { 2,3,6,5 };
    //Fraction a[] = { {2,5}, {3, 7}, {4, 6} }
    int n = sizeof(a) / sizeof(a[0]);
    PhepToan(a, n, increase);
    for (int i = 0; i < n; i++)
    {
        cout << a[i] << " ";
    }
    GiaiPhong(a);
    return 0;
}