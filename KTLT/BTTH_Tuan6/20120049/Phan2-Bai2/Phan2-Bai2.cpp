// Phan2-Bai2.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <fstream>
using namespace std;

struct PhanSo {
    int Tu;
    int Mau;
};

PhanSo* DocFile(const char File[], int& n)
{
    fstream f1;
    f1.open(File, ios::in);
    f1 >> n;
    PhanSo* PS = (PhanSo*)malloc(n * sizeof(PhanSo));
    for (int i = 0; i < n; i++)
    {
        f1 >> PS[i].Tu >> PS[i].Mau;
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

void SapXep(const char File[], PhanSo*& PS, int& n)
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
    f << endl << "------ Danh sach Phan so da sap xep ------" << endl;
    f << n << endl;
    for (int i = 0; i < n; i++)
    {
        if (i != n - 1)
            f << PS[i].Tu << PS[i].Mau << endl;
        else
            f << PS[i].Tu << PS[i].Mau;
    }
    f.close();
    free(PS);
}
int main()
{
    int n;
    PhanSo* PS;
    //DocFile("phanso.txt", n);
    SapXep("phanso.txt", PS, n);
    //free(PS);
    return 0;
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
