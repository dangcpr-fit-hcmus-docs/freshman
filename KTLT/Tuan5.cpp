#include<iostream>
#include<stdlib.h>

using namespace std;
//#pragma GCC diagnostic ignored "-Wpedantic"

typedef union
{
	double value;
	unsigned long dword[2];
	unsigned short word[4];
	unsigned char bytes[8];
	struct
	{
		unsigned long long m : 52;
		unsigned long long ex : 11;
		unsigned long long s : 1;
	};
}doubleStruct;


void doubleDump(doubleStruct* ds)
{
	//cout << ds->bytes[0];
	cout << "-------------------------------------------\n";
	cout << "+ value: " << ds->value << endl;;
	cout << "+ Dword: " << hex << ds->dword[0] <<" " <<ds->dword[1] << endl;
	cout << "+ Word: ";
	for (int i = 0; i < 4; i++)
		cout << ds->word[i] << " ";
	cout << "\n+ bytes: ";
	for (int i = 0; i < 8; i++)
	{
		//printf("0x%02X ", ds->bytes[i]);
		cout << (unsigned short)ds->bytes[i] << " ";
		//cout << endl;
	}
	cout << "\nIEEE stored parts: ";
		cout << "\nSign: " << ds->s;
		cout << "\nExpo: " << ds->ex;
		cout << "\nMantissa: " << ds->m;
}
void main()
{
	double x = -12.09;
	doubleStruct* p = (doubleStruct*)&x;
	doubleDump(p);
}