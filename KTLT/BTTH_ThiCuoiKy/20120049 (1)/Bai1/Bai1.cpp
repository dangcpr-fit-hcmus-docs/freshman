#include "Bai1.h"

node* CreateNode(SINHVIEN sv)
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
    SINHVIEN sv;
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
void addLast2(List& L, node* p)
{
    if (L.head == NULL) L.head = L.tail = p;
    else
    {
        node* k = L.head;
        while (k->next != NULL)
        {
            k = k->next;
        }
        L.tail = k;
        L.tail->next = p;
        L.tail = p;
    }
}
void nhapSV(SINHVIEN& sv)
{
    cout << "Nhap MSSV: ";
    cin.get(sv.maso, 9);
    cin.ignore();
    cout << "Nhap ten: ";
    cin.get(sv.hoten, 50);
    cout << "Nhap gioi tinh: "; cin >> sv.GioiTinh;
    cout << "Nhap ngay sinh: "; cin >> sv.NgaySinh.ng >> sv.NgaySinh.th >> sv.NgaySinh.nam;
    cout << "Nhap diem: "; cin >> sv.Diem;
    cout << "\n";
    cin.ignore();
}
void xuatSV(SINHVIEN sv)
{
    cout << "MSSV: " << sv.maso << " - ";
    cout << "Ho ten: " << sv.hoten << " - ";
    if (sv.GioiTinh == 1) cout << "Gioi tinh: " << "Nam"; else cout << "Gioi tinh: " << "Nu";
    cout << " - ";
    cout << "Ngay sinh: " << sv.NgaySinh.ng << "/" << sv.NgaySinh.th << "/" << sv.NgaySinh.nam << " - ";
    cout << "Diem: " << sv.Diem << "\n";
}
void ghiFile(List L)
{
    List p = L;
    fstream f;
    f.open("sv.txt", ios::out);
    while (p.head != NULL)
    {
        f << p.head->data.maso << ";";
        f << p.head->data.hoten << ";";
        f << p.head->data.GioiTinh << ";";
        f << p.head->data.NgaySinh.ng << "/" << p.head->data.NgaySinh.th << "/" << p.head->data.NgaySinh.nam << ";";
        f << p.head->data.Diem << "\n";
        p.head = p.head->next;
    }
    f.close();
}
void Func1(List& L)//Cau a
{
    int n;
    SINHVIEN sv;
    cout << "Nhap so sv: "; cin >> n; cout << "\n";
    cin.ignore();
    for (int i = 0; i < n; i++)
    {
        addLast(L);
    }
}
void Func2(List L)//Cau b
{
    List p = L;
    if (L.head == NULL) return;
    cout << "\nDanh sach sinh vien da nhap:\n";
    while (p.head != NULL) {
        xuatSV(p.head->data);
        p.head = p.head->next;
    }
}
void Func3(List& L)//Cau c
{
    List p = L;
    if (L.head == NULL) return;
    cout << "\nThem sinh vien:\n";
    SINHVIEN sv;
    nhapSV(sv);
    node* key = CreateNode(sv);
    if (strcmp(key->data.maso, L.head->data.maso) < 0)
    {
        key->next = L.head;
        L.head = key;
    }
    else
    {
        while (p.head->next != NULL)
        {
            if (strcmp(key->data.maso, p.head->data.maso) > 0 && strcmp(key->data.maso, p.head->next->data.maso) < 0) {
                key->next = p.head->next;
                p.head->next = key;
                break;
            }
            else
            {
                p.head = p.head->next;
            }
        }
        if (p.head->next == NULL) addLast2(p, key);
    }
    cout << "\nDanh sach sv sau khi them:";
    Func2(L);
}
void Func4(List L)//Cau d
{
    List p = L;
    if (L.head == NULL) return;
    time_t now = time(0);
    tm* ltm = localtime(&now);
    int ng_now = ltm->tm_mday;
    int th_now = ltm->tm_mon + 1;
    cout << "\nNhung sinh vien co ngay sinh la hom nay:\n";
    while (p.head != NULL)
    {
        if (p.head->data.NgaySinh.ng == ng_now && p.head->data.NgaySinh.th == th_now)
        {
            xuatSV(p.head->data);
        }
        p.head = p.head->next;
    }
}
void Func5(List L)//Cau e
{
    List p = L;
    if (L.head == NULL) return;
    cout << "\nNhung sinh vien diem duoi 5:\n";
    while (p.head != NULL)
    {
        if (p.head->data.Diem < 5)
        {
            xuatSV(p.head->data);
        }
        p.head = p.head->next;
    }
}
void Func6(List L)//Cau f
{
    List p = L;
    if (L.head == NULL) return;
    fstream f;
    f.open("dssvDuoi5.dat", ios::out);
    while (p.head != NULL)
    {
        if (p.head->data.Diem < 5) {
            f << p.head->data.maso << ";";
            f << p.head->data.hoten << ";";
            f << p.head->data.GioiTinh << ";";
            f << p.head->data.NgaySinh.ng << "/" << p.head->data.NgaySinh.th << "/" << p.head->data.NgaySinh.nam << ";";
            f << p.head->data.Diem << "\n";
        }
        p.head = p.head->next;
    }
    f.close();
}
void Func7(List& L) //Cau g
{
    List p = L;
    if (L.head == NULL) return;
    List K; LList(K);
    SINHVIEN sv;
    fstream f;
    f.open("sv.txt", ios::in);
    while (!f.eof())
    {
        f.getline(sv.maso, 9, ';');
        if (strcmp(sv.maso, "") == 0) break;
        f.getline(sv.hoten, 50, ';');
        f >> sv.GioiTinh;
        f.seekg(1, 1);
        f >> sv.NgaySinh.ng;
        f.seekg(1, 1);
        f >> sv.NgaySinh.th;
        f.seekg(1, 1);
        f >> sv.NgaySinh.nam;
        f.seekg(1, 1);
        f >> sv.Diem;
        f.ignore();
        node* a = CreateNode(sv);
        addLast2(K, a);
    }
    cout << "\Nhung sv duoi diem 5:\n";
    while (K.head != NULL)
    {
        if (K.head->data.Diem < 5) {
            cout << "MSSV: " << K.head->data.maso << " - ";
            cout << "Ho ten: " << K.head->data.hoten << " - ";
            if (K.head->data.GioiTinh == 1) cout << "Gioi tinh: " << "Nam"; else cout << "Gioi tinh: " << "Nu";
            cout << " - ";
            cout << "Ngay sinh: " << K.head->data.NgaySinh.ng << "/" << K.head->data.NgaySinh.th << "/" << K.head->data.NgaySinh.nam << " - ";
            cout << "Diem: " << K.head->data.Diem << "\n";
        }
        K.head = K.head->next;
    }
}
void Func8(List& L)
{
    List p = L;
    if (L.head == NULL) return;
    while (p.head != NULL)
    {
        if (p.head->data.Diem < 5)
        {
            node* pDel = p.head;
            p.head = p.head->next;
            L.head = p.head;
            delete pDel;
            pDel = NULL;
        }
        else if (p.head->next->next != NULL)
        {
            if (p.head->next->data.Diem < 5) {
                node* pDel = p.head->next;
                p.head->next = p.head->next->next;
                pDel->next = NULL;
                delete pDel;
                pDel = NULL;
            }
            else {
                p.head = p.head->next;
            }
        }
        else if (p.head->next->next == NULL)
        {
            if (p.head->next->data.Diem < 5) {
                node* pDel = p.head->next;
                L.tail = p.head;
                p.head->next = NULL;
                pDel->next = NULL;
                delete pDel;
                pDel = NULL;
                break;
            }
            else
            {
                break;
            }
        }
        else
        {
            p.head = p.head->next;
        }
    }
    cout << "\nDanh sach sv sau khi xoa:\n";
    p = L;
    while (p.head != NULL)
    {
        xuatSV(p.head->data);
        p.head = p.head->next;
    }
}
void CauA(List& L)
{
    Func1(L); ghiFile(L); cout << "\nDa them vao danh sach.";
}
void CauB(List L) {
    if (L.head == NULL) { Func1(L); ghiFile(L); } 
    Func2(L);
}
void CauC(List& L) {
    if (L.head == NULL) { Func1(L); ghiFile(L);  Func3(L); ghiFile(L); }
    else {
        cin.ignore();
        Func3(L); ghiFile(L);
    }
}
void CauD(List L) {
    if (L.head == NULL) { Func1(L); ghiFile(L); } Func4(L);
}
void CauE(List L) {
    if (L.head == NULL) { Func1(L); ghiFile(L); } Func5(L);
}
void CauF(List L) {
    if (L.head == NULL) { Func1(L); ghiFile(L); } Func6(L);
}
void CauG(List& L) {
    Func7(L);
}
void CauH(List& L) {
    if (L.head == NULL) { Func1(L); ghiFile(L); } Func8(L);
}
void loadMenu()
{
    List L; LList(L);
    int choice;
    cout << "-----MENU-----\n\n";
    cout << "1. Cau a: Nhap du lieu.\n";
    cout << "2. Cau b: Xuat du lieu ra man hinh.\n";
    cout << "3. Cau c: Them sv co mssv tang dan.\n";
    cout << "4. Cau d: Tim sinh nhat.\n";
    cout << "5. Cau e: Xuat sv diem duoi 5 ra man hinh.\n";
    cout << "6. Cau f: Xuat sv diem duoi 5 ra file.\n";
    cout << "7. Cau g: Xuat sv diem duoi 5 ra man hinh, du lieu sv doc tu tep tin.\n";
    cout << "8. Cau h: Xoa sv diem duoi 5.\n";
    cout << "9. Exit.\n\n";
    cout << "Nhap lua chon: "; cin >> choice;
    while (choice < 1 || choice > 9)
    {
        cout << "Nhap lai: "; cin >> choice;
    }
    cout << endl;
    switch (choice)
    {
    case 1: {CauA(L);  break; }
    case 2: {CauB(L); break; }
    case 3: {CauC(L); break; }
    case 4: {CauD(L); break; }
    case 5: {CauE(L); break; }
    case 6: {CauF(L); break; }
    case 7: {CauG(L); break; }
    case 8: {CauH(L); break; }
    case 9: {exit(0); }
    }
    while (1)
    {
        int n;
        cout << "\nNhap lua chon: "; cin >> n;
        while (choice < 1 || choice > 9)
        {
            cout << "Nhap lai: "; cin >> choice;
        }
        switch (n)
        {
        case 1: {CauA(L);  break; }
        case 2: {CauB(L); break; }
        case 3: {CauC(L); break; }
        case 4: {CauD(L); break; }
        case 5: {CauE(L); break; }
        case 6: {CauF(L); break; }
        case 7: {CauG(L); break; }
        case 8: {CauH(L); break; }
        case 9: {exit(0); }
        }
    }
}