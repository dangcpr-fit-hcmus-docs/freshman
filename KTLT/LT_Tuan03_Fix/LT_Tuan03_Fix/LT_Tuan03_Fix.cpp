#include <iostream>
#include <memory.h>
using namespace std;

struct Fraction
{
    float x;
    float y;
};

ostream& operator << (ostream& os, Fraction m)
{
    os << m.x << "/" << m.y;
    return os;
}


template<class T, int n>
ostream& operator << (ostream& os, const T(&a)[n])
{
    for (int i = 0; i < n; i++)
        os << a[i] << ' ';
    os << endl;
    return os;
}

bool operator > (Fraction m, Fraction n) {
    return ((m.x / m.y) > (n.x / n.y));
}
bool operator < (Fraction m, Fraction n) {
    return ((m.x / m.y) < (n.x / n.y));
}

template<class T>
bool increase(T a, T b)
{
    return (a > b);
}
template<class T>
bool decrease(T a, T b)
{
    return (a < b);
}
template<class T>
void sort(T a[], int n, bool (*SoSanh)(T, T))
{
    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (SoSanh(a[i], a[j]))
            {
                T temp = a[i];
                a[i] = a[j];
                a[j] = temp;
            }
        }
    }
}

int main()
{
    //string a[] = { "all", "taa", "bcc", "ddf" };
    //float a[] = { 2,3,6,5 };
    Fraction a[] = { {2,5}, {3, 7}, {4, 6} };
    int n = sizeof(a) / sizeof(a[0]);
    sort(a, n, increase);
    cout << a;
    cout << endl;
    sort(a, n, decrease);
    cout << a;
    return 0;
}