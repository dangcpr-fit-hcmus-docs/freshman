#ifndef SINHVIEN_H
#define SINHVIEN_H
#include<iostream>
#include<string>
#include<memory.h>
using namespace std;

struct SinhVien {
	char maso[9]; // 19120500
	char hoten[30];
	char ngaysinh[11]; //eg., "01/01/2000"
	double Diem;
};

void Ini(SinhVien& sv);
void Input(SinhVien& sv);
void Output(SinhVien sv);
#endif;
