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
void addFirst(node*& head, int key)
{
    node* p = CreateNode(key);
    if (head == NULL) {
        head = p;
    }
    else
    {
        p->next = head;
        head = p;
    }
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
    node* p = head;
    if (head == NULL) return;
    else {
        while (p != NULL) {
            cout << p->data << " ";
            p = p->next;
        }
    }
}
int LLinput(node*& head)
{
    int n, t = 0;
    do
    {
        cout << "Nhap n = ";
        cin >> n; if (n == 0) return t;
        cout << "Danh sach da nhap: ";
        addLast(head, n);
        PrintList(head);
        cout << "\n";
        t++;
    } while (n != 0);
}
node* findPreNode(node*& head, int key)
{
    if (head->data == key || head == NULL)
    {
        cout << "Khong tim duoc PreNode";
        return NULL;
    }
    else {
        node* p = head;
        do
        {
            if (p->next->data == key) return p;
            p = p->next;
        } while (p);
        return NULL;
    }
}
void insertMidList(node*& head, int key, int newkey) //phuc vu cau 7
{
    if (head == NULL)
        return;
    else
    {
        node* pre = findPreNode(head, key);
        if (pre != NULL) {
            node* q = CreateNode(newkey);
            q->next = pre->next;
            pre->next = q;
        }
    }
}
void makeOrderList(node*& head, int n)
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
            if (p->data < q->data)
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
                if (dem == 1 && p->data < tmp->data) {
                    addFirst(q, p->data);
                    p = p->next;
                    t++;
                    break;
                }
                else if (dem < n && p->data < tmp->data) {
                    insertMidList(q, tmp->data, p->data);
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
int main()
{
    node* head = NULL;
    int n = LLinput(head);
    makeOrderList(head, n);
    cout << "\nDanh sach sau khi sap xep: ";
    PrintList(head);
    DestroyList(head);
    return 0;
}
