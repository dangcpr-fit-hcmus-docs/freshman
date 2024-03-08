#include <iostream>
using namespace std;

long long GiaiThua(int n)
{
    if (n == 0) return 1;
    else if (n < 0) return 0;
    else {
        return n * GiaiThua(n - 1);
    }
}

int main()
{
    cout << GiaiThua(10);
    return 0;
}