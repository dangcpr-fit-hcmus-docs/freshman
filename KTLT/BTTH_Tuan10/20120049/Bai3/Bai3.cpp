#include "QLSinhVien.h"

int main()
{
    List L;
    LList_input(L);
    cout << endl;
    LList_print(L);
    char* Maso = NULL;
    Maso = (char*)malloc(sizeof(char));
    node* p = searchNode(L, Maso);
    if (p != NULL) {
        cout << endl << "Node can tim la:\n";
        Output(p->data);
    }
    else {
        cout << endl << "Khong tim thay node.\n";
    }
    cout << endl;
    Diem5(L);
    TangDan(L);
    cout << "\nDanh sach sinh vien sau khi them:\n";
    LList_print(L);
    return 0;
}