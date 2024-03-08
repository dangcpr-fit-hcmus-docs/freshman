#ifndef QLSINHVIEN_H
#define QLSINHVIEN_H
#include "SinhVien.h"
// node of Sinh Vien
struct node {
	SinhVien data;
	node* next;
};

struct List {
	node* Head;
	node* Tail;
};

node* createNode();
void init(List& l);
void addLast(List& L, node* p);
void addLast2(List& L, node* p);
void LList_input(List& L);
void LList_print(List L);
node* searchNode(List L, char* maso);
void Diem5(List L);
void TangDan(List& L);
#endif