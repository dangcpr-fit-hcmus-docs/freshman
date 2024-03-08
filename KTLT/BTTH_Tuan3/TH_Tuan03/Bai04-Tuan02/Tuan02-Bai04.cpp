#include <iostream>
#include <windows.h>
#include <string>
using namespace std;
struct Student {
    char id[9]; // ma so
    char name[20];
    float Marks[3];
    float DTB; // Diem trung binh
};
void XepLoai(Student S)
{
    if (S.DTB >= 8)
        cout << "Gioi";
    else
        if (S.DTB >= 7 && S.DTB < 8)
            cout << "Kha";
        else
            if (S.DTB >= 5 && S.DTB < 7)
                cout << "Trung binh";
            else
                cout << "Yeu ";
}
void nhap_sv(Student& sv) {

    cout << "Nhap id: ";
    cin.get(sv.id, 9);
    /*Clearing the input buffer*/
    cin.ignore();
    cout << "Nhap name: ";
    cin.get(sv.name, 20);
    cout << "Marks: baitap, giuaky, cuoiky: ";
    for (int i = 0; i < 3; i++) {
        cin >> sv.Marks[i];
    }

    sv.DTB = sv.Marks[0] * 0.25 + sv.Marks[1] * 0.25 + sv.Marks[2] * 0.5;
    cin.ignore();
};
void XuatSV(Student SinhVien)
{
    cout << "MSSV: " << SinhVien.id << " - " << "Ten: " << SinhVien.name; 
    cout << " - BT(25%)=" << SinhVien.Marks[0] << ";GK(25%)=" << SinhVien.Marks[1] << ";CK(50%)=" << SinhVien.Marks[2];
    cout << " - DTB: " << SinhVien.DTB << " - XepLoai: ";
    XepLoai(SinhVien);
    cout << endl;
}

void ThemSV(Student *&SinhVien, int &n)
{
    n++;
    SinhVien = (Student*)realloc(SinhVien, n * sizeof(Student));
    nhap_sv(*(SinhVien + n - 1));
}
void XoaSV(Student* SinhVien, int& n)
{
    for (int i = 0; i < n; i++)
    {
        if ((SinhVien + i)->DTB < 5)
        {
            for (int j = i; j<n-1;j++)
            {
                *(SinhVien + j) = *(SinhVien + j + 1);
            }
            i--;
            n--;
        }
    }
}
int main()
{
    Student* SinhVien = NULL;
    int n;
    cout << "Nhap so luong SV: ";  cin >> n;
    cin.ignore();
    SinhVien = (Student*)malloc(n * sizeof(Student));
    for (int i = 0; i < n;i++)
        nhap_sv(*(SinhVien + i));
    for (int i = 0; i < n; i++)
        XuatSV(*(SinhVien + i));
    cout << "Them 1 SV:\n";
    ThemSV(SinhVien, n);
    XoaSV(SinhVien, n);

    cout << "Danh sach SV sau khi xoa la:\n";
    for (int i = 0; i < n; i++)
        XuatSV(*(SinhVien + i));
    free(SinhVien);
    return 0;
}