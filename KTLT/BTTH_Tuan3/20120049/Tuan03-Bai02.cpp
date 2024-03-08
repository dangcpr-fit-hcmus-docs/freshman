#include <iostream>
#include <math.h>
using namespace std;
struct place
{
	int x1;
	int y1;
	int x2;
	int y2;
};
int** arr2D_Alloc(int& m, int& n)
{
	int** a = (int**)malloc(m * sizeof(int*));
	for (int i = 0; i < m; i++)
	{
		a[i] = (int*)malloc(n * sizeof(int));
	}
	return a;
}
void arr2D_input(int** a, int ma, int na)
{
	for (int i = 0; i < ma; i++)
	{
		for (int j = 0; j < na; j++)
		{
			cout << "a[" << i << "][" << j << "] = ";
			cin >> a[i][j];
		}
	}
}
void arr2D_output(int** a, int ma, int na)
{
	cout << "Mang ban vua nhap la: \n";
	for (int i = 0; i < ma; i++)
	{
		for (int j = 0; j < na; j++)
		{
			cout << a[i][j] << "\t";
		}
		cout << "\n";
	}
}
void arr2D_free(int** a, int m, int n)
{
	for (int i = 0; i < m; i++)
	{
		free(a[i]);
	}
	free(a);
}
int* ChuyenMang(int** a, int m, int n);
void MaxSub(int** a, int m, int n)
{
	int max = a[0][0] - a[0][1];
	int* arr = ChuyenMang(a, m, n);
	place* ViTri = NULL; int k = 0;
	for (int i = 0; i < m * n; i++)
	{
		for (int j = i + 1; j < m * n; j++)
		{
			if (arr[i] - arr[j] > max)
				max = arr[i] - arr[j];
		}
	}
	for (int i = 0; i < m * n; i++)
	{
		for (int j = i + 1; j < m * n; j++)
		{
			if (arr[i] - arr[j] == max)
			{
				k++;
				ViTri = (place*)realloc(ViTri, sizeof(place) * k);
				ViTri[k - 1].x1 = i / n;
				ViTri[k - 1].y1 = i % n;
				ViTri[k - 1].x2 = j / n;
				ViTri[k - 1].y2 = j % n;
			}
		}
	}
	cout << "Cac cap phan tu thoa man yeu cau la: ";
	for (int i = 0; i < k; i++)
	{
		cout << "((" << ViTri[i].x1 << "," << ViTri[i].y1 << "),(" << ViTri[i].x2 << "," << ViTri[i].y2 << ")) ";
	}
	free((int*)arr);
	free((int*)ChuyenMang(a, m, n));
}
int* ChuyenMang(int** a, int m, int n)
{
	int* arr = (int*)malloc(sizeof(int) * m * n);
	int k = 0;
	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++)
		{
			arr[k] = a[i][j];
			k++;
		}
	}
	return arr;
}
int main()
{
	int** a;
	int m, n;
	cout << "Nhap so dong: "; cin >> m;
	cout << "Nhap so cot: "; cin >> n;
	a = arr2D_Alloc(m, n);
	arr2D_input(a, m, n);
	arr2D_output(a, m, n);
	MaxSub(a, m, n);
	arr2D_free(a, m, n);
	return 0;
}