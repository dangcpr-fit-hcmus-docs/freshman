#include <iostream>
using namespace std;

long long Fib(int n)
{
    if (n == 1 || n == 0) return n;
    else if (n < 0) return 0;
    else {
        return Fib(n - 1) + Fib(n - 2);
    }
}

int main()
{
    cout << Fib(7);
    return 0;
}