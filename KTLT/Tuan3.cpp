#include<iostream>
#include<stdlib.h>

using namespace std;
const int hsize = 2 * sizeof(int);
struct Sophuc
{
	float phanthuc, phanao;
};

istream& operator>>(istream& inDev, Sophuc& p)
{
	inDev >> p.phanthuc >> p.phanao;
	return inDev;
}

ostream& operator<<(ostream& os, const Sophuc& p)
{
	os << p.phanthuc << " + " << p.phanao << "i   ";
	return os;
}
void* origin_addr(void* aData) //địa chỉ lưu số lượng phần tử
{
	if (aData != NULL)
		return (char*)aData - 2 * sizeof(int);
	return NULL;
}

void* szItem_addr(void* aData) //địa chỉ lưu kích thước của mỗi phần tử 
{
	if (aData != NULL)
		return (char*)aData - sizeof(int);
	return NULL;
}

void* Data_addr(void* aOrigin) //địa chỉ của data
{
	if (aOrigin != NULL)
		return (char*)aOrigin + 2 * sizeof(int);
	return NULL;
}

void set_nItem(void* aData, int nItem) //lưu số lượng phần tử của mảng vào origin_addr
{
	*((int*)origin_addr(aData)) = nItem;
}

int ArrSize(void* aData) // lấy số lượng phần tử trong mảng
{
	if (aData != NULL)
		return *((int*)origin_addr(aData));
	return 0;
}

void arrFree(void* aData)
{
	if (aData != NULL)
	{
		free(origin_addr(aData));
	}
}

void* ArrResize(void* aData, int nItem)
{
	if (aData == NULL || nItem < 0) return NULL;
	void* aOrigin = origin_addr(aData);
	int szItem = *((int*)szItem_addr(aData));
	int sz = szItem * nItem + hsize;
	void* anew = realloc(aOrigin, sz);
	if (anew != NULL)
	{

		aData = Data_addr(anew);
		set_nItem(aData, nItem);
		*((int*)szItem_addr(aData)) = szItem;
		return aData;
	}
	return NULL;
}
bool ArrPushBack(void** aData, void* x)
{
	int nItem = ArrSize(*aData), szItem = *((int*)szItem_addr(*aData));
	void* anew = ArrResize(*aData, nItem + 1);
	if (anew != NULL)
	{
		memmove((char*)anew + nItem * szItem, x, szItem);
		*aData = anew;
		return 1;
	}
	return 0;
}
void* ArrPopBack(void** aData)
{
	int nItem = ArrSize(*aData), szItem = *((int*)szItem_addr(*aData));
	void* x = malloc(szItem);
	if (*aData != NULL && nItem > 0)
	{
		nItem--;
		memmove(x, (char*)*aData + nItem * szItem, szItem);
		void* anew = ArrResize(*aData, nItem);
		if (anew != NULL) *aData = anew;
	}
	return x;
}

void* soPhucArrInput()
{
	Sophuc* a = (Sophuc*)malloc(0);
	if (a != NULL)
	{
		a = (Sophuc*)Data_addr(a);
		*((int*)origin_addr(a)) = 0;
		*((int*)szItem_addr(a)) = sizeof(Sophuc);
	}
	Sophuc x = { 0, 0 };
	while (cin >> x)
	{
		ArrPushBack((void**)&a, &x);
	}
	cin.clear();
	return a;
}

void soPhucArrOut(Sophuc* aData)
{
	int nItem = ArrSize(aData), szItem = *((int*)szItem_addr(aData));
	cout << "Mang B gom cac so phuc la: ";
	for (int i = 0; i < nItem; i++)
	{
		cout << *(Sophuc*)(aData + i);
	}
	cout << endl;
}

void main()
{
	cout << " nhap cac phan tu so phuc\n";
	Sophuc* B = (Sophuc*)soPhucArrInput();
	Sophuc* x = (Sophuc*)ArrPopBack((void**)&B);
	cout << "\nAfter pop: \n";
	soPhucArrOut(B);
	cout << "\nPopped element: " << *x << endl;
	free(x);
	arrFree(B);
}