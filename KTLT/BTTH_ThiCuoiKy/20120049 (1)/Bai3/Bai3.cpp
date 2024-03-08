#include "Bai3.h"

NODE* CreateNode(Element key)
{
    NODE* p = new NODE;
    if (p == NULL) return NULL;
    p->data = key;
    p->pNext = NULL;
    return p;
}
void LQueue(QUEUE& L)
{
    L.pFront = NULL;
    L.pRear = NULL;
}
void input(Element& key)
{
    cout << "Nhap du lieu va do uu tien: "; cin >> key.key >> key.priority;
}
/*void addFirst(QUEUE& L, Element key)
{
    NODE* t = CreateNode(key);
    if (L.pFront == NULL) L.pFront = L.pRear = t;
    else
    {
        t->pNext = L.pFront;
        L.pFront = t;
    }
}
void addFirst2(QUEUE& L, NODE* t)
{
    if (L.pFront == NULL) L.pFront = L.pRear = t;
    else
    {
        t->pNext = L.pFront;
        L.pFront = t;
    }
}*/
void addLast(QUEUE& L, Element key)
{
    QUEUE p = L;
    NODE* t = CreateNode(key);
    if (L.pFront == NULL) L.pFront = L.pRear = t;
    else
    {
        while (p.pFront->pNext != NULL)
        {
            p.pFront = p.pFront->pNext;
        }
        L.pRear = p.pFront;
        L.pRear->pNext = t;
        L.pRear = t;
        t->pNext = NULL;
    }
}
/*void addLast2(QUEUE& L, NODE* t)
{
    NODE* p = L.pFront;
    if (L.pFront == NULL) L.pFront = L.pRear = t;
    else
    {
        while (p->pNext != NULL)
        {
            p = p->pNext;
        }
        L.pRear = p;
        L.pRear->pNext = t;
        L.pRear = t;
        t->pNext = NULL;
    }
}*/
/*void addMid(QUEUE& L, NODE*& pre, NODE* t)
{
    t->pNext = pre->pNext->pNext;
    pre->pNext = t;
}*/
void QInput(QUEUE& I)
{
    int n;
    Element key;
    cout << "Nhap so phan tu trong hang doi: "; cin >> n;
    for (int i = 0; i < n; i++)
    {
        input(key);
        addLast(I, key);
        for (NODE* pTmp = I.pFront; pTmp != NULL; pTmp = pTmp->pNext)
        {
            for (NODE* pTmp2 = pTmp->pNext; pTmp2 != NULL; pTmp2 = pTmp2->pNext)
            {
                if (pTmp->data.priority > pTmp2->data.priority)
                {
                    Element tmp = pTmp->data;
                    pTmp->data = pTmp2->data;
                    pTmp2->data = tmp;
                }
            }
        }
    }
    cout << "\nDa tao hang doi uu tien.";
}
void QPrint(QUEUE I)
{
    QUEUE k = I;
    if (I.pFront == NULL) return;
    while (k.pFront != NULL)
    {
        if (k.pFront->pNext != NULL)
            cout << "[" << k.pFront->data.key << "," << k.pFront->data.priority << "]->";
        else
            cout << "[" << k.pFront->data.key << "," << k.pFront->data.priority << "]";
        k.pFront = k.pFront->pNext;
    }
}
void QOFile(QUEUE I)
{
    fstream f;
    f.open("qoutput.txt", ios::out);
    QUEUE k = I;
    if (I.pFront == NULL) return;
    while (k.pFront != NULL)
    {
        if (k.pFront->pNext != NULL)
            f << k.pFront->data.key << " " << k.pFront->data.priority << "\n";
        else
            f << k.pFront->data.key << " " << k.pFront->data.priority;
        k.pFront = k.pFront->pNext;
    }
    f.close();
}
void QIFile(QUEUE& O)
{
    int n;
    fstream f;
    Element key;
    LQueue(O);
    f.open("qinput.txt", ios::in);
    while(!f.eof())
    {
        f >> key.key >> key.priority;
        addLast(O, key);
        for (NODE* pTmp = O.pFront; pTmp != NULL; pTmp = pTmp->pNext)
        {
            for (NODE* pTmp2 = pTmp->pNext; pTmp2 != NULL; pTmp2 = pTmp2->pNext)
            {
                if (pTmp->data.priority > pTmp2->data.priority)
                {
                    Element tmp = pTmp->data;
                    pTmp->data = pTmp2->data;
                    pTmp2->data = tmp;
                }
            }
        }
    }
    f.close();
}
void QPop(QUEUE& I)
{
    if (I.pFront == NULL) return;
    NODE* pDel = I.pFront;
    cout << "\n\nPhan tu lay ra la: [" << I.pFront->data.key << "," << I.pFront->data.priority << "]";
    I.pFront = I.pFront->pNext;
    delete pDel;
    pDel = NULL;
    cout << "\nHang doi sau khi lay: ";
    QPrint(I);
}
void CauA(QUEUE& I) {
    QInput(I);
}
void CauB(QUEUE I) {
    if (I.pFront == NULL) { QInput(I); }
    cout << "\nHang doi uu tien da tao: "; QPrint(I);
}
void CauC(QUEUE I) {
    if (I.pFront == NULL) { QInput(I); }
    QOFile(I);
}
void CauD(QUEUE& O) {
    QIFile(O); cout << "\nHang doi uu tien da doc: "; QPrint(O);
}
void CauE(QUEUE& I) {
    if (I.pFront == NULL) { QInput(I); }
    cout << "\nHang doi uu tien da tao: "; QPrint(I); QPop(I);
}
void loadMenu()
{
    QUEUE I, O; LQueue(I);
    int choice;
    unsigned int n;
    float x;
    cout << "-----MENU-----\n\n";
    cout << "1. Cau a: Tao hang doi.\n";
    cout << "2. Cau b: Xuat hang doi ra man hinh\n";
    cout << "3. Cau c: Xuat hang doi ra file.\n";
    cout << "4. Cau d: Doc du lieu tu file va xuat hang doi ra man hình.\n";
    cout << "5. Cau e: Lay mot phan tu ra khoi hang doi.\n";
    cout << "6. Exit.\n\n";
    cout << "Nhap lua chon: "; cin >> choice;
    while (choice < 1 || choice > 6)
    {
        cout << "Nhap lai: "; cin >> choice;
    }
    cout << endl;
    switch (choice)
    {
    case 1: {CauA(I); break; }
    case 2: {CauB(I); break; }
    case 3: {CauC(I); break; }
    case 4: {CauD(O); break; }
    case 5: {CauE(I); break; }
    case 6: {exit(0); }
    }
    while (1)
    {
        cout << "\n\nNhap lua chon: "; cin >> choice;
        while (choice < 1 || choice > 6)
        {
            cout << "Nhap lai: "; cin >> choice;
        }
        switch (choice)
        {
        case 1: {CauA(I); break; }
        case 2: {CauB(I); break; }
        case 3: {CauC(I); break; }
        case 4: {CauD(O); break; }
        case 5: {CauE(I); break; }
        case 6: {exit(0); }
        }
    }
}