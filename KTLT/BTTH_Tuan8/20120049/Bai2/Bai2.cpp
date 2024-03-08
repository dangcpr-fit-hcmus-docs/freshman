#include <iostream>
using namespace std;

struct node {
    int data;
    node* next;
};

node* CreateNode(int key)
{
    node* p = new node;
    if (p == NULL) return NULL;
    p->data = key;
    p->next = NULL;
    return p;
}
void addLast(node*& head, int key) //Cau 1
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
void PrintList(node* head)
{
    if (head == NULL) return;
    else
    {
        node* p = head;
        while (p != NULL)
        {
            cout << p->data << " ";
            p = p->next;
        }
    }
}
void DestroyList(node*& head)
{
    node* p = NULL;
    if (head == NULL) return;
    else
    {
        while (head)
        {
            p = head;
            head = head->next;
            delete p;
        }
    }
}
void LLinput(node*& head)
{
    int n;
    do
    {
        cout << "Nhap n = ";
        cin >> n; if (n == 0)  return;
        cout << "Danh sach da nhap: ";
        addLast(head, n);
        PrintList(head);
        cout << "\n";
    } while (n != 0);
}
void DelNode(node*& head, int key)
{
    node* p = head;
    if (p == NULL) return;
    while (p->next != NULL)
    {
        if (p->data == key) {
            node* toDel = p;
            head = head->next;
            p = p->next;
            delete toDel;
        }
        else if (p->next->data == key && p->next->next == NULL)
        {
            node* toDel = p->next;
            p->next = NULL;
            delete toDel;
            p = p->next;
            if (p == NULL) return;
        }
        else if (p->next->data == key)
        {
            node* toDel = p->next;
            p->next = p->next->next;
            delete toDel;
        }
        else
        {
            p = p->next;
        }
    }
}
void DelNode2(node*& head, int key)
{
    node* p = head;
    node* q = NULL;
    bool spd = 1;
    if (p == NULL) return;
    while (p != NULL)
    {
        if ((key == p->data && spd == 1) || key != p->data)
        {
            if (key == p->data) spd = 0;
            addLast(q, p->data);
            p = p->next;
        }
        else
            p = p->next;
    }
    head = q;
    
    return;
}

int main()
{
    node* head = NULL;
    LLinput(head);
   // DelNode(head, 2);
    //cout << "\nDanh sach sau khi xoa node: ";
    //PrintList(head);
    DelNode2(head, 2);
    cout << "\nDanh sach sau khi xoa node: ";
    PrintList(head);
    DestroyList(head);
    return 0;
}