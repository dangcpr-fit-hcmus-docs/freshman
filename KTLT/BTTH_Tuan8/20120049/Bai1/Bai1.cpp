#include <iostream>
using namespace std;

struct Phim {
    char maso[10]; // mã số, Ex. 123456789
    char tenPhim[30]; // tên phim: Before Sunrise, Bo gia
    char nhaSX[30]; // nhà sản xuất, ex. HBO, Phim Giai Phong
    int namSX; // 1975, 2000, 2020
    float XepHang; // 8, 9.2, trong khoang (1,10)
};

struct node {
    Phim data;
    node* next;
};

struct LList {
    node* head;
    node* tail;
};
node* CreateNode(Phim key)
{
    node* p = new node;
    if (p == NULL) return NULL;
    p->next = NULL;
    p->data = key;
    return p;
}
void addLast(node*& head, Phim key) //Cau 1
{
    node* p = CreateNode(key);
    if (head == NULL) {
        head = p;
        return;
    }
    else
    {
        node* tail = head;
        while (tail->next != NULL) {
            tail = tail->next;
        }
        tail->next = p;
    }
}
void addFirst(node*& head, Phim key)
{
    node* p = CreateNode(key);
    if (head == NULL)
    {
        head = p;
        return;
    }
    else
    {
        p->next = head;
        head = p;
    }
}

void nhap_phim(Phim& key)
{
    cout << "Nhap ma so: ";
    cin.get(key.maso, 10);
    cin.ignore();
    cout << "Nhap ten phim: ";
    cin.get(key.tenPhim, 30);
    cin.ignore();
    cout << "Nhap nha san xuat: ";
    cin.get(key.nhaSX, 30);
    cout << "Nam san xuat: ";
    cin >> key.namSX;
    cout << "Xep hang: ";
    cin >> key.XepHang;
    cin.ignore();
}
void DS(node*& head) //Cau 2
{
    unsigned int n;
    Phim key;
    cout << "Nhap so luong phim: "; cin >> n;
    cin.ignore();
    for (int i = 0; i < n; i++)
    {
        nhap_phim(key);
        addLast(head, key);
    }
}
void PrintList(node* head) //Cau 3
{
    node* p = head;
    if (head == NULL) return;
    else {
        while (p != NULL) {
            cout << "Ma so: " << p->data.maso << " - ";
            cout << "Ten phim: " << p->data.tenPhim << " - ";
            cout << "Nha san xuat: " << p->data.nhaSX << " - ";
            cout << "Nam san xuat: " << p->data.namSX << " - ";
            cout << "Xep hang: " << p->data.XepHang << endl;
            p = p->next;
        }
    }
}
void DelNode(node*& head, const char key[10])
{
    node* p = head;
    if (p == NULL) return;
    while (p->next != NULL)
    {
        if (strcmp(p->data.nhaSX, key) == 0)
        {
            node* toDel = p;
            head = head->next;
            p = p->next;
            delete toDel;
        }
        else if (strcmp(p->next->data.nhaSX, key) == 0 && p->next->next == NULL)
        {
            node* toDel = p->next;
            p->next = NULL;
            delete toDel;
            p = p->next;
            if (p == NULL) return;
        }
        else if (strcmp(p->next->data.nhaSX, key) == 0)
        {
            node* toDel = p->next;
            p->next = p->next->next;
            delete toDel;
        }
        else
        {
             p = p->next;
        }
    }
}
void addNode(node*& head, Phim& key)
{
    node* p = head;
    nhap_phim(key);
    node* q = CreateNode(key);
    if (head == NULL) addFirst(head, key);
    if (key.namSX < head->data.namSX)
    {
        addFirst(head, key);
    }
    else 
    {
        while (p != NULL)
        {
            if (p->next != NULL)
            {
                if (key.namSX < p->next->data.namSX) {
                    q->next = p->next;
                    p->next = q;
                    return;
                }
            }
            else if (key.namSX > p->data.namSX && p->next == NULL)
            {
                addLast(head, key);
                return;
            }
            else
            {
                p = p->next;
            }
        }    
    }
    delete q;
}
void destroyList(node*& head) {
    node* p;
    if (head == NULL) return;
    while (head) {
        p = head;
        head = head->next;
        delete p;
    }
}
int main()
{
    node* head = NULL;
    Phim key;
    DS(head);
    cout << endl << "Danh sach phim da nhap: " << endl;
    PrintList(head);
    DelNode(head, "HBO");
    cout << endl << "Danh sach phim sau khi xoa: " << endl;
    PrintList(head);
    cout << endl << "Them phim: " << endl;
    addNode(head, key);
    cout << endl << "Danh sach phim sau khi them: " << endl;
    PrintList(head);
    destroyList(head);
    return 0;
}