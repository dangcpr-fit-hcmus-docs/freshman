#include <iostream>
#include <string>
#include <malloc.h>
using namespace std;
struct NgaySinh {
    int ngay, thang, nam;
};
struct Student {
    char id[9]; // ma so
    char name[20];
    NgaySinh day;
    float Marks[3], DTB;
};

void nhap_sv(Student& sv) {

    cout << "Nhap id: ";
    cin.get(sv.id, 9);
    /*Clearing the input buffer*/
    cin.ignore();
    cout << "Nhap name: ";
    cin.get(sv.name, 20);
    cout << "Ngay sinh: ";
    cin >> sv.day.ngay >> sv.day.thang >> sv.day.nam;
    cout << "Marks: baitap, giuaky, cuoiky: ";
    for (int i = 0; i < 3; i++) {
        cin >> sv.Marks[i];
    }
    sv.DTB = sv.Marks[0] * 0.25 + sv.Marks[1] * 0.25 + sv.Marks[2] * 0.5;
    cin.ignore();
};

void XuatSV(Student sv)
{
    cout << "MSSV: " << sv.id << " - " << "Ten: " << sv.name;
    cout << " - BT(25%)=" << sv.Marks[0] << ";GK(25%)=" << sv.Marks[1] << ";CK(50%)=" << sv.Marks[2];
    cout << " - DTB: " << sv.DTB << " - Ngay sinh: " << sv.day.ngay << "/" << sv.day.thang << "/" << sv.day.nam;
    cout << endl;
}
void DoiCho(Student& sv1, Student& sv2)
{
    Student tmp = sv1;
    sv1 = sv2;
    sv2 = tmp;
}

void SapXep(Student* DS, int n) //Sap xep de tim sv co cung ngay sinh
{
    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if ((DS + i)->day.nam > (DS + j)->day.nam)
            {
                DoiCho(*(DS + i), *(DS + j));
                break;
            }
            if ((DS + i)->day.thang > (DS + j)->day.thang)
            {
                DoiCho(*(DS + i), *(DS + j));
                break;
            }
            if ((DS + i)->day.ngay > (DS + j)->day.ngay)
            {
                DoiCho(*(DS + i), *(DS + j));
                break;
            }
        }
    }
}
void CungNgay(Student* DS, int n)
{
    Student** NS = NULL;
    int t = 0, k;
    //for (int i = 0; i < sizeof(NS) / sizeof(NgaySinh); i++)
   // {
    for (int j = 0; j < n; j++)
    {
        if (t == 0)
        {
            k = 0;
            t++; k++;
            NS = (Student**)realloc((Student**)NS, t * sizeof(Student*));
            *(NS + t - 1) = NULL;
            *(NS + t - 1) = (Student*)realloc((Student*)*(NS + t - 1), k * sizeof(Student));
            *(*(NS + t - 1) + (k-1)) = *(DS + j);
            continue;
        }
        if ((DS + j)->day.ngay != (*(NS + t - 1))->day.ngay || (DS + j)->day.thang != (*(NS + t - 1))->day.thang || (DS + j)->day.nam != (*(NS + t - 1))->day.nam)
        {
            k = 0;
            t++; k++;
            NS = (Student**)realloc((Student**)NS, t * sizeof(Student*));
            *(NS + t - 1) = NULL;
            *(NS + t - 1) = (Student*)realloc((Student*)*(NS + t - 1), k * sizeof(Student));
            *(*(NS + t - 1) + (k - 1)) = *(DS + j);
        }
        else
        {
            k++;
            *(NS + t - 1) = (Student*)realloc((Student*)*(NS + t - 1), k * sizeof(Student));
            *(*(NS + t - 1) + (k - 1)) = *(DS + j);
        }
    }
    //Xuat nhung SV cung ngay sinh
    for (int i = 0; i < t; i++)
    {
        cout << "\nNhung nguoi cung ngay sinh:\n";
        for (int j = 0; j < _msize(*(NS + i)) / sizeof(Student); j++)
        {
            XuatSV(*(*(NS + i) + j));
        }
    }
    //Giai phong con tro
    for (int i = 0; i < t; i++)
    {
        free(*(NS + i));
    }
    free(NS);
}
int main()
{
    Student* SinhVien = NULL;
    int n, x;
    cout << "Nhap so luong SV: ";  cin >> n;
    cin.ignore();
    SinhVien = (Student*)malloc(n * sizeof(Student));
    for (int i = 0; i < n; i++)
        nhap_sv(*(SinhVien + i));

    for (int i = 0; i < n; i++)
        XuatSV(*(SinhVien + i));
    SapXep(SinhVien, n); //Sap xep de tim sv co cung ngay sinh
    CungNgay(SinhVien, n);
    free(SinhVien);
    return 0;
}