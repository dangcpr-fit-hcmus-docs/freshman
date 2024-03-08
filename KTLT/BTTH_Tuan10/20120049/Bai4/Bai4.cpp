#include <iostream>
using namespace std;

struct node {
	int data;
	struct node* next;
};

node* createNode()
{
	node* p = new node;
	if (p == NULL) return NULL;
	cin >> p->data;
	p->next = NULL;
	return p;
}
void addFrist(node*& head, node*& tail, node* key)
{
	node* p = head;
	if (head == NULL) head = tail = key;
	else
	{
		key->next = p;
		head = key;
	}
}
void addLast(node*& head, node*& tail)
{
	node* p = head;
	node* key = createNode();
	if (head == NULL) head = tail = key;
	else
	{
		while (p->next != NULL)
		{
			p = p->next;
		}
		tail = p;
		tail->next = key;
		tail = key;
	}
}
void List_input(node*& head, node*& tail, int n)
{
	for (int i = 0; i < n; i++)
	{
		cout << "Nhap n = ";
		addLast(head, tail);
	}
}
void List_print(node* head)
{
	node* p = head;
	while (p != NULL)
	{
		cout << p->data << ' ';
		p = p->next;
	}
}
void VongLap(node* head, node* tail)
{
	node* p = head;
	node* q = NULL;
	while (p != NULL)
	{
		head = head->next;
		p->next = NULL;
		addFrist(q, tail, p);
		p = head;
	}
	cout << "\nDanh sach dao nguoc (vong lap):";
	List_print(q);
}
void DeQuy(node* head, node*& tail, node*& q)
{
	node* p = head;
	if (head == NULL)
	{
		cout << "\nDanh sach dao nguoc (de quy):";
		List_print(q);
		return;
	}
	else
	{
		head = head->next;
		p->next = NULL;
		addFrist(q, tail, p);
		p = head;
		DeQuy(head, tail, q);
	}
}
int main()
{
	node* head = NULL;
	node* tail = NULL;
	node* q = NULL;
	int n;
	cout << "Nhap so luong node: "; cin >> n;
	List_input(head, tail, n);
	cout << "Danh sach da nhap: ";
	List_print(head);
	VongLap(head, tail); //Dao nguoc bang vong lap
	//DeQuy(head, tail, q); //Dao nguoc bang de quy
	return 0;
}