//7. Nhap dien tich cua mot hinh tron. Tinh va  in ra ban kinh cua hinh tron.
#define _USE_MATH_DEFINES
#include <iostream>
#include <math.h>
using namespace std;
int main()
{
    float S;
    cout << "Nhap dien hinh tron S = ";
    cin >> S;
    cout << "Ban kinh hinh tron R = " << sqrt(S / M_PI) << "\n";
    return 0;
}
