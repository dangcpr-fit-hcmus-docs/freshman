//Them node nhưng vẫn dữ thứ tự cho trước
#include<iostream>
#include <string.h>
using namespace std;

struct node
{
	int value;
	node* next;
};

node* getNode(int k)
{
	node* p = new node;
	if (p == NULL) return NULL;
	else
	{
		p->value = k;
		p->next = NULL;
		return p;
	}
}
bool ascending(int a, int b)
{
	return a < b;
}

bool descending(int a, int b)
{
	return a > b;
}

void ThemDS(node* head, int val, bool (*compare)(int, int))
{
	node* p1 = head;
	node* p2 = p1->next;
	//node* p = new node;
	while (p2 && compare(p2->value, val))
	{
		p1 = p2;
		p2 = p1->next;
	}
	node* p = getNode(val);
	p1->next = p;
	p->next = p2;
}

void XuatDS(node* head)
{
	while (head != NULL)
	{
		cout << head->value << " ";
		head = head->next;
	}
	cout << endl;
}

void DeleteList(node* head)
{
	node* p;
	while (head != NULL)
	{
		p = head;
		head = head->next;
		delete p;
	}
}
int main()
{
	node* head = new node;
	if(head != NULL)head->next = NULL;
	int cs;
	cout << "Nhap 1 de sap xep tang dan, nhap 2 de sap xep giam dan: ";
	cin >> cs;
    int tmp;
	do 
	{
		cout << "Hay nhap mot so, nhap 0 de dung.";
		cin >> tmp;
		if (tmp != 0)
		{
			switch (cs)
			{
			case 1:
				ThemDS(head, tmp, ascending); break;
			case 2:
				ThemDS(head, tmp, descending); break;
			}
			XuatDS(head->next);
		}
		else break;
	} while (1);
	DeleteList(head);
}