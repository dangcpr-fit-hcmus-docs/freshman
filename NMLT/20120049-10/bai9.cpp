// T�nh dien t�ch h�nh sau (phan duoc t� x�m). Biet rang c�c tam gi�c th�nh phan l� tam gi�c deu v� duoc ve doi xung. Du lieu deu v�o l� chieu d�i canh tam gi�c deu v� b�n k�nh h�nh tr�n.
#define _USE_MATH_DEFINES
#include <iostream>
#include <math.h>
using namespace std;
int main()
{
	float a, R;
	cout << "Nhap chieu dai canh tam giac deu a = ";
	cin >> a;
	cout << "Nhap ban kinh hinh tron R = ";
	cin >> R;
	cout << "Dien tich phan duoc to xam la " << ((a * a * sqrt(3)) / 4) * 3 + 0.5 * M_PI * R * R << "\n";
	return 0;
}
