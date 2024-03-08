#pragma once
#include <iostream>
#include <fstream>
using namespace std;

/*----- Khai bao Queue -----*/
struct Element {
	int key;
	int priority;
};
/* Node of Queue*/
struct NODE {
	Element data;
	NODE* pNext;
};
/* Queue */
struct QUEUE {
	NODE* pFront;
	NODE* pRear;
};

NODE* CreateNode(Element key);
void LQueue(QUEUE& L);
void input(Element& key);
//void addFirst(QUEUE& L, Element key);
//void addFirst2(QUEUE& L, NODE* t);
void addLast(QUEUE& L, Element key);
//void addLast2(QUEUE& L, NODE* t);
//void addMid(QUEUE& L, NODE*& pre, NODE* t);
void QInput(QUEUE& I); //Nhap du lieu
//void QOutput(QUEUE& I); //Tao hang doi
void QPrint(QUEUE I); //Xuat hang doi ra man hinh
void QOFile(QUEUE I); //Xuat hang doi ra file
void QIFile(QUEUE& O); //Doc du lieu tu file va xuat hang doi ra man hình
void QPop(QUEUE& I); //Lay mot phan tu ra khoi hang doi

void CauA(QUEUE& I);
void CauB(QUEUE I);
void CauC(QUEUE I);
void CauD(QUEUE& I);
void CauE(QUEUE& I);

void loadMenu();