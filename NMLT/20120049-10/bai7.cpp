// Viet chuong trinh nhap vao ban kinh cua hinh tron. Tinh va in ra chu vi, dien tich cua hinh tron do.
#define _USE_MATH_DEFINES
#include <iostream>
#include <math.h>
using namespace std;
int main()
{
    float R;
    cout << "Nhap ban kinh hinh tron R = ";
    cin >> R;
    cout << "Dien tich hinh tron la S = " << M_PI * R * R << "\n";
    cout << "Chu vi hinh tron la C = " << M_PI * 2 * R << "\n";
    return 0;
}
