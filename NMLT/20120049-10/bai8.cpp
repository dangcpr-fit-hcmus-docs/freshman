// Mot hinh chu nhat co dac diem chieu dai bang 1.5 lan chieu rong. Viet chuong trinh nhap chu vi của hinh, tinh và in ra dien tich cua hinh chu nhat.
#include <iostream>
using namespace std;

int main()
{
    float C;
    cout << "Nhap chu vi hinh chu nhat C = ";
    cin >> C;
    cout << "Dien tich hinh chu nhat la S = " << (C / 5) * 1.5 * (C / 5) << "\n";
    return 0;
}
