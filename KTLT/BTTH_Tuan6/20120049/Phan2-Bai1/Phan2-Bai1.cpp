#include <iostream>
#include <fstream>
using namespace std;

void GhiFile(const char File[], int* arr, int n)
{
    fstream f;
    f.open(File, ios::out);
    for (int i = 0; i < n; i++)
    {
        f << arr[i] << ' ';
    }
    f.close();
}

int* DocFile(const char File[], int n)
{
    fstream f1;
    int* So = (int*)malloc(n * sizeof(int));
    f1.open(File, ios::in);
    for (int i = 0; i < n; i++)
    {
        f1 >> So[i];
    }
    f1.close();
    return So;
}

void DoiCho(int& a, int& b)
{
    int tmp = a;
    a = b;
    b = tmp;
}

void DocSoChan(const char File[], const char Save[], int arr[], int n)
{
    int* So = DocFile("dayso.txt", n);
    free(DocFile("dayso.txt", n));
    int* Chan = NULL;
    fstream f2;
    f2.open(Save, ios::out);
    int t = 0;
    for (int i = 0; i < n; i++)
    {
        if (So[i] % 2 == 0)
        {
            t++;
            Chan = (int*)realloc(Chan, t * sizeof(int));
            f2 << So[i] << ' ';
        }
    }
    f2.close();
    free(So);
    free(Chan);
}

void SapXep(const char[], int arr[], int n)
{
    int* So = DocFile("dayso.txt", n);
    free(DocFile("dayso.txt", n));
    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (So[i] < So[j])
                DoiCho(So[i], So[j]);
        }
    }
    fstream f;
    f.open("dayso.txt", ios::app);
    f << endl << "Day so da sap xep giam dan" << endl;
    for (int i = 0; i < n; i++)
    {
        f << So[i] << ' ';
    }
    f.close();
    free(So);
}

int main()
{
    int a[] = { 10,15,20,25,30,35,40 };
    int n = sizeof(a) / sizeof(int);
    GhiFile("dayso.txt", a, n);
    DocSoChan("dayso.txt", "daysochan.txt", a, n);
    SapXep("dayso.txt", a, n);
    return 0;
}