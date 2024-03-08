#include "SinhVien.h"
#include "QLSinhVien.h"

node* createNode()
{
    SinhVien key;
    node* p = new node;
    if (p == NULL) return NULL;
    Input(key);
    p->next = NULL;
    p->data = key;
    return p;
}
void init(List& l)
{
    l.Head = NULL;
    l.Tail = NULL;
}

void addLast(List& L, node* p)
{
    p = createNode();
    if (L.Head == NULL) L.Head = L.Tail = p;
    else
    {
        L.Tail->next = p;
        L.Tail = p;
    }
}

void addLast2(List& L, node* p)
{
    if (L.Head == NULL) L.Head = L.Tail = p;
    else
    {
        L.Tail->next = p;
        L.Tail = p;
    }
}

void LList_input(List& L)
{
    int n;
    node* p = NULL;
    cout << "Nhap so sinh vien: "; cin >> n;
    cin.ignore();
    init(L);
    for (int i = 0; i < n; i++)
    {
        addLast(L, p);
    }
}

void LList_print(List L)
{
    List p = L;
    if (p.Head == NULL) return;
    while (p.Head != NULL)
    {
        Output(p.Head->data);
        p.Head = p.Head->next;
    }
}

node* searchNode(List L, char* maso)
{
    List p = L;
    node* q = NULL;
    cout << endl << "Nhap ma so: "; cin.get(maso, 9);
    if (p.Head == NULL) return NULL;
    while (p.Head != NULL)
    {
        if (strcmp(p.Head->data.maso, maso) == 0)
        {
            q = p.Head;
            break;
        }
        else
        {
            p.Head = p.Head->next;
        }
    }
    return q;
}

void Diem5(List L)
{
    List p = L;
    bool a = 0;
    while (p.Head != NULL)
    {
        if (p.Head->data.Diem < 5) {
            if (a == 0) {
                a = 1;
                cout << "\nDanh sach hoc sinh co diem TB duoi 5:\n";
            }
            Output(p.Head->data);
        }
        p.Head = p.Head->next;
    }
    if (a == 0) cout << endl << "Khong co ai duoi 5.";
}

void TangDan(List& L)
{
    List p = L;
    cout << "\nThem sinh vien:\n";
    cin.ignore();
    node* key = createNode();
    if (strcmp(key->data.maso, L.Head->data.maso) < 0)
    {
        key->next = L.Head;
        L.Head = key;
        return;
    }
    else
    {
        while (p.Head->next != NULL)
        {
            if (strcmp(key->data.maso, p.Head->data.maso) > 0 && strcmp(key->data.maso, p.Head->next->data.maso) < 0) {
                key->next = p.Head->next;
                p.Head->next = key;
                return;
            }
            else
            {
                p.Head = p.Head->next;
            }
        }
        addLast2(p, key);
    }
}