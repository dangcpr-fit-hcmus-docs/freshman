#include <iostream>
#include <fstream>
using namespace std;

struct SinhVien {
    char maso[9];
    char ten[10];
    float diem;
};
// Struct node of sinh vien
struct node {
    SinhVien data;
    node* next;
};
// LList of SinhVien
struct List {
    node* head;
    node* tail;
};

void nhapSV(SinhVien& sv)
{
    cout << "Nhap MSSV: ";
    cin.get(sv.maso, 9);
    cin.ignore();
    cout << "Nhap ten: ";
    cin.get(sv.ten, 10);
    cout << "Nhap diem: "; cin >> sv.diem;
    cin.ignore();
}
void xuatSV(List L)
{
    List p = L;
    while (p.head != NULL) {
        cout << p.head->data.maso << "-";
        cout << p.head->data.ten << "-";
        cout << p.head->data.diem << "\n";
        p.head = p.head->next;
    }
}
node* CreateNode(SinhVien sv)
{
    node* p = new node;
    if (p == NULL) return NULL;
    p->data = sv;
    p->next = NULL;
    return p;
}
void LList(List& L)
{
    L.head = NULL;
    L.tail = NULL;
}
void addLast(List& L)
{
    node* p = L.head;
    SinhVien sv;
    nhapSV(sv);
    node* key = CreateNode(sv);
    if (L.head == NULL) L.head = L.tail = key;
    else
    {
        while (p->next != NULL)
        {
            p = p->next;
        }
        L.tail = p;
        L.tail->next = key;
        L.tail = key;
    }
}
void addLast2(List& L, SinhVien sv)
{
    node* p = L.head;
    node* key = CreateNode(sv);
    if (L.head == NULL) L.head = L.tail = key;
    else
    {
        while (p->next != NULL)
        {
            p = p->next;
        }
        L.tail = p;
        L.tail->next = key;
        L.tail = key;
    }
}
void nhapDS(List& L, int n)
{
    for (int i = 0; i < n; i++)
    {
        addLast(L);
    }
}
void ghiSV(List L, const char* file)
{
    fstream f;
    List p = L;
    f.open(file, ios::app);
    while (p.head != NULL)
    {
        //if (p.head->next != NULL)
            f << p.head->data.maso << "-" << p.head->data.ten << "-" << p.head->data.diem << endl;
        //else
            //f << p.head->data.maso << "-" << p.head->data.ten << "-" << p.head->data.diem;
        p.head = p.head->next;
    }
    f.close();
}
void docSV(List& L, const char* file)
{
    ifstream f;
    SinhVien sv;
    f.open(file, ios::in);
    while (!f.eof())
    {
        f.getline(sv.maso, 9, '-');
        if (strcmp(sv.maso, "") == 0) break;
        f.getline(sv.ten, 10, '-');
        f >> sv.diem;
        f.ignore();
        addLast2(L, sv);
    }
    f.close();
}
void Duoi5(List L, List& P, const char* file)
{
    List p = L;
    fstream f;
    f.open(file, ios::app);
    while (p.head != NULL)
    {
        if (p.head->data.diem < 5)
        {
            //if (p.head->next != NULL)
                f << p.head->data.maso << "-" << p.head->data.ten << "-" << p.head->data.diem << endl;
                addLast2(P, p.head->data);
            //else
               //f << p.head->data.maso << "-" << p.head->data.ten << "-" << p.head->data.diem;
        }
        p.head = p.head->next;
    }
    f.close();
}
int main()
{
    List L, P, K;
    LList(L);
    LList(P);
    LList(K);
    int n;
    cout << "Nhap so sv: "; cin >> n; cin.ignore();
    nhapDS(L, n);
    ghiSV(L, "SV.txt");
    docSV(P, "SV.txt");
    cout << endl << "Danh sach sinh vien da doc:\n";
    xuatSV(P);
    Duoi5(L, K, "Duoi5.txt");
    return 0;
}