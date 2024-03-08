#define _CRT_SECURE_NO_WARNINGS
#pragma once
#include <iostream>
#include <ctime>
#include <fstream>
//#include <string>
using namespace std;

struct Ngay {
    int ng, th, nam;
};
struct SINHVIEN {
    char maso[9]; // "19120100",
    char hoten[50]; // "Nguyen Van Tung"
    bool GioiTinh; // 1: "Nam"; 0: "Nu"
    Ngay NgaySinh; // 01/01/2000
    float Diem; // 6.75
};
struct node {
    SINHVIEN data;
    node* next;
};
struct List {
    node* head;
    node* tail;
};

node* CreateNode(SINHVIEN sv);
void LList(List& L);
void addLast(List& L);
void addLast2(List& L, node* p);
void nhapSV(SINHVIEN& sv);
void xuatSV(SINHVIEN sv);
void ghiFile(List L);
void Func1(List& L); //a. nhap du lieu
void Func2(List L); //b. xuat du lieu ra man hinh
void Func3(List& L); //c. them sv co mssv tang dan
void Func4(List L); //d. tim sinh nhat
void Func5(List L); //e. Xuat sv diem duoi 5 ra man hinh
void Func6(List L); //f. Xuat sv diem duoi 5 ra file
void Func7(List& L); //g. Xuat sv diem duoi 5 ra man hinh, du lieu sv doc tu tep tin
void Func8(List& L); //h. Xoa sv diem duoi 5

void CauA(List& L);
void CauB(List L);
void CauC(List& L);
void CauD(List L);
void CauE(List L);
void CauF(List L);
void CauG(List& L);
void CauH(List& L);


void loadMenu();
