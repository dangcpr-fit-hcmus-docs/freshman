#include <iostream>
using namespace std;
struct node {
    int data;
    node* next;
};
struct dbnode {
    dbnode* pre;
    int data;
    dbnode* next;
};

node* CreateNode(int key)
{
    node* p = new node;
    if (p == NULL) return NULL;
    p->data = key;
    p->next = NULL;
    return p;
}
dbnode* CreateDBNode(int key)
{
    dbnode* p = new dbnode;
    if (p == NULL) return NULL;
    p->pre = NULL;
    p->data = key;
    p->next = NULL;
    return p;
}
dbnode* DBLList(node* head)
{
    if (head == NULL) return NULL;
    node* p = head;
    dbnode* q = NULL;
    dbnode* tmp1 = NULL;
    dbnode* tmp2 = NULL;
    while (p != NULL)
    {
        if (q == NULL)
        {
            tmp1 = CreateDBNode(p->data);
            q = tmp1;
            p = p->next;
        }
        else if (q != NULL)
        {
            tmp2 = q;
            while (tmp2->next != NULL)
            {
                tmp2 = tmp2->next;
            }
            tmp1 = CreateDBNode(p->data);

            tmp2->next = tmp1;
            tmp1->pre = tmp2;
            p = p->next;
        }
    }
    return q;
}
void addFirst(node*& head, int key) //Cau 1
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
void addLast(node*& head, int key) //Cau 2
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
        while(p != NULL){
            cout << p->data << " ";
            p = p->next;
        }
    }
}
void PrintDBList(dbnode* head)
{
    dbnode* p = head;
    if (head == NULL) return;
    else {
        while (p != NULL) {
            cout << p->data << " ";
            p = p->next;
        }
    }
}
void LList_input(node*& head) //Cau 3
{
    int n;
    do
    {
        cout << "nhap n = ";
        cin >> n;
        addLast(head, n);
        //addFirst(head, n);
        cout << "Danh sach da nhap: ";
        PrintList(head);
        cout << "\n";
    } while (n != 0);
}
node* findPreNode(node*& head, int key) //Cau 4
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
void insertMidList(node*& head, int key, int newKey) //Cau 5
{
    if (head == NULL) 
        return;
    else 
    {
        node* pre = findPreNode(head, key);
        if (pre != NULL) {
            node* q = CreateNode(newKey);
            q->next = pre->next;
            pre->next = q;
        }
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
void destroyDBList(dbnode*& head) {
    dbnode* p;
    if (head == NULL) return;
    while (head) {
        p = head;
        head = head->next;
        delete p;
    }
}
void DelNode(node*& head, int key) //Cau 6
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
    if (p->data == key && p == head)
    {
        head = p->next;
        delete p;
        return;
    }
    else
    {
        if (tail->data == key && tail->next == NULL)
        {
            while (p->next->data != key)
            {
                p = p->next;
            } 
            delete p->next;
            p->next = NULL;
            return;
        }
        else
        {
            while (p->next->data != key)
            {
                p = p->next;
            }
            node* tmp = p->next->next;
            delete p->next;
            p->next = tmp;
        }
    }
}
dbnode* DelDBNode(dbnode* head, int key) //Cau 7
{
    if (head == NULL) return NULL;
    dbnode* p = head;
    
    if (p->pre == NULL && p->next == NULL)
    {
        delete p;
    }
    if (p->data == key)
    {
        dbnode* tmp = p->next;
        tmp->pre = NULL;
        delete p;
        return tmp;
    }
    while (p->next->data != key)
    {
        p = p->next;
    }
    if (p->next->next == NULL)
    {
        delete p->next;
        p->next = NULL;
        return head;
    }
    else
    {
        p->next = p->next->next;
        p->next->next->pre = p;
        return head;
    }
}
int main()
{
    node* head = NULL;
    LList_input(head);
    node* p = head;
    int x;
    cout << "Nhap x = ";
    cin >> x;
    cout << "Node truoc do co gia tri: ";
    cout << findPreNode(p, x)->data;
    int y;
    cout << "\nThem node: Nhap y = ";
    cin >> y;
    insertMidList(head, x, y);
    PrintList(head);
    int z;
    cout << "\nXoa node: Nhap z = ";
    cin >> z;
    DelNode(head, z);
    //Danh sach lien ket doi, xoa node
    dbnode* dbhead = NULL;
    dbhead = DBLList(head);
    cout << "\nDanh sach node: ";
    PrintDBList(dbhead);
    cout << "\n";
    dbhead = DelDBNode(dbhead, 0); //Xoa node co so 0
    cout << "\nDanh sach node sau khi xoa: ";
    PrintDBList(dbhead);
    destroyList(head);
    destroyDBList(dbhead);
    return 0;
}
