#include <iostream>
#include <fstream>
using namespace std;

struct PhanSo {
    int Tu;
    int Mau;
};

PhanSo* DocFile(const char File[], int& n)
{
    ifstream f1;
    f1.open(File, ios::in);
    PhanSo* PS = NULL;
    if (!f1.is_open())
    {
        cout << "Khong mo duoc file!";
    }
    else {
        f1 >> n;
        PS = (PhanSo*)malloc(n * sizeof(PhanSo));
        for (int i = 0; i < n; i++)
        {
            f1 >> PS[i].Tu >> PS[i].Mau;
        }
    }
    f1.close();
    return PS;
}

void DoiCho(PhanSo& a, PhanSo& b)
{
    PhanSo tmp = a;
    a = b;
    b = tmp;
}

void SapXep(const char File[], PhanSo* PS, int& n)
{
    PS = DocFile(File, n);
    free(DocFile(File, n));
    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if ((float)PS[i].Tu / PS[i].Mau > (float)PS[j].Tu / PS[j].Mau)
            {
                DoiCho(PS[i], PS[j]);
            }
        }
    }
    fstream f;
    f.open(File, ios::app);
    if (!f.is_open())
    {
        cout << "Khong mo duoc file!";
    }
    else {
        f << endl << "------ Danh sach Phan so da sap xep ------" << endl;
        f << n << endl;
        for (int i = 0; i < n; i++)
        {
            if (i != n - 1)
                f << PS[i].Tu << ' ' << PS[i].Mau << endl;
            else
                f << PS[i].Tu << ' ' << PS[i].Mau;
        }
    }
    f.close();
}
int main()
{
    int n;
    PhanSo* PS = NULL;
    SapXep("phanso.txt", PS, n);
    free(PS);
    return 0;
}