#include <iostream>
#include <fstream>
using namespace std;

struct SinhVien {
    char maso[9];
    char ten[10];
    float diem;
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
void xuatSV(SinhVien* P, int t)
{
    for (int i = 0; i < t; i++) {
        cout << P[i].maso << "-";
        cout << P[i].ten << "-";
        cout << P[i].diem << "\n";
    }
}
void nhapDS(SinhVien*& DSSV, int n)
{
    DSSV = (SinhVien*)malloc(n * sizeof(SinhVien));
    for (int i = 0; i < n; i++)
    {
        nhapSV(DSSV[i]);
    }
}
void ghiSV(SinhVien*& DSSV, const char* file, int n)
{
    fstream f;
    f.open(file, ios::app);
    for (int i = 0; i < n; i++)
    {
        f << DSSV[i].maso << "-" << DSSV[i].ten << "-" << DSSV[i].diem << endl;
    }
    f.close();
}
void docSV(SinhVien*& DSSV, const char* file, int& n)
{
    ifstream f;
    SinhVien sv;
    n = 0;
    f.open(file, ios::in);
    while (!f.eof())
    {
        f.getline(sv.maso, 9, '-');
        if (strcmp(sv.maso, "") == 0) break;
        n++;
        f.getline(sv.ten, 10, '-');
        f >> sv.diem;
        f.ignore();
        DSSV = (SinhVien*)realloc(DSSV, n * sizeof(SinhVien));
        DSSV[n - 1] = sv;
    }
    f.close();
}
void Duoi5(SinhVien* L, SinhVien*& K, const char* file, int n)
{
    fstream f;
    f.open(file, ios::app);
    int t = 0;
    for (int i = 0; i < n; i++)
    {
        if (L[i].diem < 5)
        {
            f << L[i].maso << "-" << L[i].ten << "-" << L[i].diem << endl;
            t++;
            K = (SinhVien*)realloc(K, t * sizeof(SinhVien));
            K[t - 1] = L[i];
        }
    }
    f.close();
}
int main()
{
    SinhVien* L = NULL;
    SinhVien* P = NULL;
    SinhVien* K = NULL;
    int n, t;
    cout << "Nhap so sv: "; cin >> n; cin.ignore();
    nhapDS(L, n);
    ghiSV(L, "SV.txt", n);
    docSV(P, "SV.txt", t);
    cout << endl << "Danh sach sinh vien da doc:\n";
    xuatSV(P, t);
    Duoi5(L, K, "Duoi5.txt", n);
    free(L);
    free(P);
    free(K);
    return 0;
}