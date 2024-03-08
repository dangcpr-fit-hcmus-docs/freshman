#include <iostream>
using namespace std;
struct NgaySinh {
    int ngay;
    int thang;
    int nam;
};
/* Khai bao Sinh Vien */
struct SinhVien {
    char maso[9];
    char hoten[40];
    NgaySinh ngsinh;
    float diem;
};
struct node {
    SinhVien data;
    node* next;
};

//Ham phu tro
node* CreateNode(SinhVien key)
{
    node* p = new node;
    if (p == NULL) return NULL;
    p->data = key;
    p->next = NULL;
    return p;
}
void addLast(node*& head, SinhVien key)
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
void addFirst(node*& head, SinhVien sv)
{
    node* p = CreateNode(sv);
    if (head == NULL) {
        head = p;
    }
    else
    {
        p->next = head;
        head = p;
    }
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
bool ngaysinh(NgaySinh sv1, NgaySinh sv2)
{
    if (sv1.nam < sv2.nam)
    {
        return true;
    }
    if (sv1.thang < sv2.thang)
    {
        return true;
    }
    if (sv1.ngay < sv2.ngay)
    {
        return true;
    }
    return false;
}
//Ham chinh
void nhap_sv(SinhVien& sv) 
{
    cout << "Nhap id: ";
    cin.get(sv.maso, 9);
    /*Clearing the input buffer*/
    cin.ignore();
    cout << "Nhap name: ";
    cin.get(sv.hoten, 40);
    cout << "Ngay sinh: ";
    cin >> sv.ngsinh.ngay >> sv.ngsinh.thang >> sv.ngsinh.nam;
    cout << "Diem: ";
    cin >> sv.diem;
    cin.ignore();
}
void DS(node*& head) //Cau 1
{
    unsigned int n;
    SinhVien sv;
    cout << "Nhap so sinh vien: "; cin >> n;
    cin.ignore();
    for (int i = 0; i < n; i++)
    {
        nhap_sv(sv);
        addLast(head, sv);
    }
}
int DemNode(node* head) //Cau 2
{
    node* p = head;
    int t = 0;
    while (p != NULL)
    {
        t++;
        p = p->next;
    }
    return t;
}
//Cau 3
node* findPreNode(node*& head, char key[9])
{
    if (strcmp(head->data.maso, key) == 0 || head == NULL)
    {
        cout << "Khong tim duoc PreNode";
        return NULL;
    }
    else {
        node* p = head;
        do
        {
            if (strcmp(p->next->data.maso, key) == 0) return p;
            p = p->next;
        } while (p);
        return NULL;
    }
}
void insertMidList(node*& head, char key[9])
{
    if (head == NULL)
        return;
    else
    {
        node* pre = findPreNode(head, key);
        if (pre != NULL) {
            SinhVien sv;
            nhap_sv(sv);
            node* q = CreateNode(sv);
            q->next = pre->next;
            pre->next = q;
        }
    }
}
void insertMidList2(node*& head, SinhVien sv, SinhVien newsv) //phuc vu cau 7
{
    if (head == NULL)
        return;
    else
    {
        node* pre = findPreNode(head, sv.maso);
        if (pre != NULL) {
            node* q = CreateNode(newsv);
            q->next = pre->next;
            pre->next = q;
        }
    }
}
float DiemTB(node* head, int n) //Cau 4
{
    node* p = head;
    float DTB = 0;
    while (p != NULL)
    {
        DTB += p->data.diem / n;
        p = p->next;
    }
    return DTB;
}
string XepLoai(SinhVien sv) //Cau 5
{
    if (sv.diem >= 8)
        return "Gioi";
    else if (sv.diem >= 7 && sv.diem < 8)
        return "Kha";
    else if (sv.diem >= 5 && sv.diem < 7)
        return "Trung binh";
    else
        return "Yeu";
}
void SVDuoiTB(SinhVien*& sv, node* head) //Cau 6
{
    node* p = head;
    int t = 0;
    if (DemNode(p) == 0)
    {
        cout << "Khong co sinh vien.";
    }
    else
    {
        while (p != NULL)
        {
            if (p->data.diem < 5)
            {
                t++;
                sv = (SinhVien*)realloc(sv, t * sizeof(SinhVien));
                sv[t - 1] = p->data;
            }
            p = p->next;
        }
    }

    if (t == 0)
        cout << "Khong co sinh vien duoi TB.";
    else
    {
        cout << "Cac sinh vien duoi TB co MSSV la: ";
        for (int i = 0; i < t; i++)
        {
            if (i != t - 1)
                cout << sv[i].maso << ", ";
            else
                cout << sv[i].maso;
        }
    }
    free(sv);
}
void DelNode(node*& head, const char key[9]) //Cau 7
{
    node* tail = head;
    if (head == NULL)
    {
        delete head;
        return;
    }
    else
    {
        while (tail->next != NULL)
        {
            tail = tail->next;
        }
    }

    node* p = head;
    if (strcmp(p->data.maso, key) == 0 && p == head)
    {
        head = p->next;
        delete p;
        return;
    }
    else
    {
        if (strcmp(tail->data.maso, key) == 0 && tail->next == NULL)
        {
            while (strcmp(p->next->data.maso, key) != 0)
            {
                p = p->next;
            } 
            delete p->next;
            p->next = NULL;
            return;
        }
        else
        {
            while (strcmp(p->next->data.maso, key) != 0)
            {
                p = p->next;
            }
            node* tmp = p->next->next;
            delete p->next;
            p->next = tmp;
        }
    }
}
void makeOrderListMSSV(node*& head, int n)
{
    int t = 0;
    node* p = head;
    node* q = NULL;
    node* tmp = NULL;
    if (head == NULL)
        return;
    while (p != NULL) {
        if (q == NULL)
        {
            t++;
            addFirst(q, p->data);
            p = p->next;
        }
        else if (t == 1)
        {
            if (strcmp(p->data.maso, q->data.maso) < 0)
                addFirst(q, p->data);
            else
                addLast(q, p->data);
            t++;
            p = p->next;
        }
        else if (t != 1 && t < n)
        {
            int dem = 1;
            tmp = q;
            while (tmp != NULL) {
                if (dem == 1 && strcmp(p->data.maso, tmp->data.maso) < 0) {
                    addFirst(q, p->data);
                    p = p->next;
                    t++;
                    break;
                }
                else if (dem < n && strcmp(p->data.maso, tmp->data.maso) < 0) {
                    insertMidList2(q, tmp->data, p->data);
                    p = p->next;
                    t++;
                    break;
                }
                else if (tmp->next == NULL)
                {
                    addLast(q, p->data);
                    p = p->next;
                    t++;
                    break;
                }
                else {
                    dem++;
                    tmp = tmp->next;
                }
            }
        }
    }
    head = q;
}
void makeOrderListngsinh(node*& head, int n)
{
    int t = 0;
    node* p = head;
    node* q = NULL;
    node* tmp = NULL;
    if (head == NULL)
        return;
    while (p != NULL) {
        if (q == NULL)
        {
            t++;
            addFirst(q, p->data);
            p = p->next;
        }
        else if (t == 1)
        {
            if (ngaysinh(p->data.ngsinh, q->data.ngsinh))
                addFirst(q, p->data);
            else
                addLast(q, p->data);
            t++;
            p = p->next;
        }
        else if (t != 1 && t < n)
        {
            int dem = 1;
            tmp = q;
            while (tmp != NULL) {
                if (dem == 1 && ngaysinh(p->data.ngsinh, tmp->data.ngsinh)) {
                    addFirst(q, p->data);
                    p = p->next;
                    t++;
                    break;
                }
                else if (dem < n && ngaysinh(p->data.ngsinh, tmp->data.ngsinh)) {
                    insertMidList2(q, tmp->data, p->data);
                    p = p->next;
                    t++;
                    break;
                }
                else if (tmp->next == NULL)
                {
                    addLast(q, p->data);
                    p = p->next;
                    t++;
                    break;
                }
                else {
                    dem++;
                    tmp = tmp->next;
                }
            }
        }
    }
    head = q;
}
void CungNgay(node* head, int n)
{
    makeOrderListngsinh(head, n);
    node* p = head;
    SinhVien* DS = NULL;
    int g = 0;
    while (p != NULL)
    {
        g++;
        DS = (SinhVien*)realloc(DS, g * sizeof(SinhVien));
        DS[g - 1] = p->data;
        p = p->next;
    }

    SinhVien** NS = NULL;
    int t = 0, k;
    //for (int i = 0; i < sizeof(NS) / sizeof(NgaySinh); i++)
   // {
    for (int j = 0; j < n; j++)
    {
        if (t == 0)
        {
            k = 0;
            t++; k++;
            NS = (SinhVien**)realloc((SinhVien**)NS, t * sizeof(SinhVien*));
            *(NS + t - 1) = NULL;
            *(NS + t - 1) = (SinhVien*)realloc((SinhVien*)*(NS + t - 1), k * sizeof(SinhVien));
            *(*(NS + t - 1) + (k - 1)) = *(DS + j);
            continue;
        }
        if ((DS + j)->ngsinh.ngay != (*(NS + t - 1))->ngsinh.ngay || (DS + j)->ngsinh.thang != (*(NS + t - 1))->ngsinh.thang || (DS + j)->ngsinh.nam != (*(NS + t - 1))->ngsinh.nam)
        {
            k = 0;
            t++; k++;
            NS = (SinhVien**)realloc((SinhVien**)NS, t * sizeof(SinhVien*));
            *(NS + t - 1) = NULL;
            *(NS + t - 1) = (SinhVien*)realloc((SinhVien*)*(NS + t - 1), k * sizeof(SinhVien));
            *(*(NS + t - 1) + (k - 1)) = *(DS + j);
        }
        else
        {
            k++;
            *(NS + t - 1) = (SinhVien*)realloc((SinhVien*)*(NS + t - 1), k * sizeof(SinhVien));
            *(*(NS + t - 1) + (k - 1)) = *(DS + j);
        }
    }
    //Xuat nhung SV cung ngay sinh
    for (int i = 0; i < t; i++)
    {
        cout << "\nNhung nguoi cung ngay sinh:\n";
        for (int j = 0; j < _msize(*(NS + i)) / sizeof(SinhVien); j++)
        {
            cout << "Ten: " << (*(*(NS + i) + j)).hoten << " - ";
            cout << "Ma so: " << (*(*(NS + i) + j)).maso << " - ";
            cout << "Ngay sinh: " << (*(*(NS + i) + j)).ngsinh.ngay << "/" << (*(*(NS + i) + j)).ngsinh.thang << "/" << (*(*(NS + i) + j)).ngsinh.nam << " - ";
            cout << "Diem: " << (*(*(NS + i) + j)).diem << " - ";
            cout << "Xep loai: " << XepLoai(*(*(NS + i) + j)) << endl;
        }
    }
    //Giai phong con tro
    for (int i = 0; i < t; i++)
    {
        free(*(NS + i));
    }
    free(NS);
    free(DS);
}
//Ham phu tro
void PrintList(node* head) //Da bao gom cau 5
{
    node* p = head;
    if (head == NULL) return;
    else {
        while (p != NULL) {
            cout << "Ten: " << p->data.hoten << " - ";
            cout << "Ma so: " << p->data.maso << " - ";
            cout << "Ngay sinh: " << p->data.ngsinh.ngay << "/" << p->data.ngsinh.thang << "/" << p->data.ngsinh.nam << " - ";
            cout << "Diem: " << p->data.diem << " - ";
            cout << "Xep loai: " << XepLoai(p->data) << endl;
            p = p->next;
        }
    }
}

int main() //Ham PrintList() da bao gom cau 5
{
    node* head = NULL;
    SinhVien* sv = NULL;
    SinhVien them;
    char mssv[9];
    DS(head); //Cau 1
    cout << endl << "Danh sach da nhap:\n";
    PrintList(head);
    int n = DemNode(head); //Cau 2
    cout << endl << "So node: " << n; 
    cout << endl << endl << "DTB = " << DiemTB(head, n) << endl; // Cau 3
    int t;
    do
    {
        cout << "Ban muon them sinh vao dau (nhan 0), giua (nhan 1), cuoi (nhan 2) danh sach: ";
        cin >> t;
    } while (t != 0 && t != 1 && t != 2);
    if (t == 0)
    {
        cin.ignore();
        nhap_sv(them);
        addFirst(head, them);
    }
    else if (t == 1)
    {
        cin.ignore();
        cout << endl << "Ban muon them 1 sv truoc sv co mssv la: ";
        cin.get(mssv, 10);
        cin.ignore();
        insertMidList(head, mssv);
    }
    else if (t == 2)
    {
        cin.ignore();
        nhap_sv(them);
        addLast(head, them);
    }
    cout << endl;
    PrintList(head); //In dssv sau cau 3
    cout << endl << endl << "DTB = " << DiemTB(head, DemNode(head)); // Cau 4
    cout << endl << endl;
    SVDuoiTB(sv, head); //In dssv theo yeu cau cau 6

    cout << endl << endl << "Ma so can xoa: " ; // Cau 7
    cin.get(mssv, 9);
    DelNode(head, mssv);
    PrintList(head);
    makeOrderListMSSV(head, n); //Cau 8
    cout << endl << "\nDanh sach da nhap:\n";
    PrintList(head); //In dssv theo yeu cau cau 8
    CungNgay(head, n); //Cau 9
    destroyList(head);
    return 0;
}