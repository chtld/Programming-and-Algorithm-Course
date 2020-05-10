#include <iostream>
using namespace std;

typedef struct LinkListNode
{
 int data;
 LinkListNode *next;
} Node;

int joseph(int sum, int cycle)
{
    int i;
    Node *p_old, *p_new, *head=NULL;

    head = new Node;
//此处创建一个循环链表(create a circular chained table)
    head->data = 1;
    p_old = head;
    for(i = 2; i <= sum; i++)
    {
        p_new = new Node;
        p_new->data = i;
        p_old->next = p_new;
        p_old = p_new;
    }
	p_old->next = head;

    p_old = head;
    i = 1;
//循环删除元素直到只剩下最后一个元素(delete elements circularly until the last element left)
    while(p_old->next != p_old)
    {
		for (i = 1; i < cycle - 1; ++ i) {
			p_old = p_old->next;
		}
		p_new = p_old->next;
		p_old->next = p_old->next->next;
		delete p_new;
		p_old = p_old->next;
    }

    return p_old->data;
}

int main(void)
{
 int n,m;
 while (cin>>n>>m) {
	 if (n == 0 || m == 0) return 0;
	cout<<joseph(n, m)<<endl;
 }
 return 0;
}