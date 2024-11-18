#include "head.h"
// #include <bits/stdc++.h>
// #include<iostream>
using namespace std;

class List
{
public:
	string name;
	Node *head; // 头节点地址
	int len;	// 链表长度
public:
	// 初始化
	List(const string &objName)
	{
		len = 0;
		head = new Node;
		head->next = NULL;
		name = objName; // 记录名字
	}
	// 销毁
	~List()
	{
		Node *current = head;
		while (current != NULL)
		{
			Node *temp = current;
			current = current->next;
			delete temp;
		}
	}
	// 插入元素到指定位置//默认在末尾
	List &Insert(int e, int n = 0)
	{
		Node *head1 = head;
		Node *preNode;
		Node *temp = new Node;
		temp->next = NULL;
		temp->data = e;
		len++;
		// 末尾
		if (n == 0)
		{
			if (head->next == NULL)
			{
				head->next = temp;
				return *this;
			}
			while (head1->next != NULL)
			{
				head1 = head1->next;
			}
			head1->next = temp;
			return *this;
		}
		else
		{
			// 指定位置
			for (int i = 0; i < n - 1; i++)
			{
				preNode = head1;
				head1 = head1->next;
			}
			temp->next = head1;
			preNode->next = temp;
			return *this;
		}
	}
	// 输出节点数及元素
	List &Print()
	{
		cout << name << "共有" << len << "个结点\t";
		Node *head1 = NULL;
		head1 = head->next;
		while (head1 != NULL)
		{
			cout << head1->data << " ";
			head1 = head1->next;
		}
		cout << endl;
		return *this;
	}
	// 删除某个元素
	void Delete(int n = -1)
	{
		while (n <= 0 || n > len)
		{
			cout << "删除第几个元素？";
			cin >> n;
		}
		Node *head1 = head;
		for (int i = 0; i < n - 1; i++)
		{
			head1 = head1->next;
		}
		Node *temp = head1->next;
		head1->next = temp->next;
		delete temp;
		len--;
	}
	// 查找指定元素位置
	List &Locate(int e, int *n)
	{
		Node *head1 = head;
		int i = 0;
		while (head1 != NULL && head1->data != e)
		{
			i++;
			head1 = head1->next;
		}
		if (i <= len)
		{
			*n = i;
			return *this;
		}
		else
		{
			*n = -1;
			return *this;
		}
	}
	// 获取指定位置的元素
	List &Get(int i, int *e)
	{
		if (i > len)
		{
			cout << "元素不存在";
			return *this;
		}
		Node *head1 = head;
		for (int i = 0; i < i - 1; i++)
		{
			head1 = head1->next;
		}
		*e = head1->data;
		return *this;
	}
	// 倒置
	void Reverse()
	{
		if (head->next == NULL || head->next->next == NULL)
		{
			return;
		}
		Node *t = NULL;
		Node *p = head->next;
		Node *q = p->next;
		while (q != NULL)
		{
			t = q->next;
			q->next = p;
			p = q;
			q = t;
		}
		head->next->next = NULL;
		head->next = p;
	}
	// 销毁链表
	void DestroyList()
	{
		Node *current = head;
		while (current != NULL)
		{
			Node *temp = current;
			current = current->next;
			delete temp;
		}
	}
	// 获取长度
	List &GetLength()
	{
		int i = 0;
		Node *p = this->head->next;
		while (p != NULL)
		{
			p = p->next;
			i++;
		}
		this->len = i;
		return *this;
	}
	// 返回长度
	int ListLength()
	{
		return len;
	}
	// 是否为空表
	bool ListEmpty()
	{
		return (len == 0);
	}
	// 获取指定元素的前一个元素
	void PriorElem(int e)
	{
		Node *head1 = head;
		int i = 0;
		while (head1 != NULL && head1->data != e)
		{
			i++;
			head1 = head1->next;
		}
	}
	// 获取指定元素的后一个元素
	int NextElem(int e)
	{
		Node *head1 = head;
		int i = 0;
		while (head1 != NULL && head1->data != e)
		{
			i++;
			head1 = head1->next;
		}
		return head1->next->data;
	}
	// 提纯
	List &Pure()
	{
		List l("");
		Node *head = this->head->next;

		while (head != NULL)
		{
			int n;
			l.Locate(head->data, &n);
			if (n == -1)
			{
				l.Insert(head->data);
			}
			head = head->next;
		}
		this->DestroyList();
		this->head->next = l.head->next;
		this->len = l.len;

		return *this;
		// Node* head = this->head->next;

		// do
		// {
		// 	l.Insert(head->data);
		// } while(head != NULL);{
		//      head = head->next;
		// 	 int n;
		// 	 if (head == NULL)
		//      l.Locate(head->data,&n);
		// 	 if (n == -1) {
		//          l.Insert(head->data);
		// 	 }
		// }
		// l.Print();
		// this->head = l.head;
		// this->len = l.len;

		// return *this;
	}
	// 连接一个链表到末尾
	List &InterLinkList(List *l)
	{
		Node *head = this->head->next;
		while (head->next != NULL)
		{
			head = head->next;
		}
		head->next = l->head->next;
		this->len += l->len;
		return *this;
	}

	// 合并递增链表到本链表
	List &MergeNode(List *l)
	{
		Node *p = this->head;
		Node *t = l->head->next;

		while (t != NULL && p->next != NULL)
		{
			if (t->data <= p->next->data)
			{
				Node *temp = t->next;
				t->next = p->next;
				p->next = t;
				t = temp;
				this->len++;
			}
			else
			{
				p = p->next;
			}
		}

		if (t != NULL)
		{
			p->next = t;
		}

		return *this;
	}

	// 找到第一个共同结点并覆盖本链表
	List &FindCommonNode(List *la, List *lb)
	{
		Node *pa = la->head->next;
		Node *pb = lb->head->next;

		while (pa != NULL)
		{
			Node *b = pb;
			while (b != NULL)
			{
				if (pa == b)
				{
					this->head->next = b;
					this->name = "CommonNode";
					this->GetLength();
					return *this;
				}
				b = b->next;
			}
			pa = pa->next;
		}

		this->name = "未找到";
		this->head->next = NULL;
		return *this;
	}
};

// 求并，并到la
void Union(List *la, List *lb)
{

	Node *head2 = lb->head->next;

	while (head2 != NULL)
	{
		int n;
		int e = head2->data;
		(*la).Locate(e, &n);
		if (n == -1)
		{

			(*la).Insert(e);
		}
		head2 = head2->next;
	}
}

void GetOnly(List *la, List *lb, List *l)
{
	Node *head1 = la->head->next;
	Node *head2 = lb->head->next;

	while (head1 != NULL)
	{
		int n;
		int e = head1->data;
		(*lb).Locate(e, &n);
		if (n == -1)
		{

			(*l).Insert(e);
		}
		head1 = head1->next;
	}

	while (head2 != NULL)
	{
		int n;
		int e = head2->data;
		(*la).Locate(e, &n);
		if (n == -1)
		{

			(*l).Insert(e);
		}
		head2 = head2->next;
	}
}

// 取异或
void GetOnly(List *la, List *lb)
{
	List l("l");
	Node *head1 = la->head->next;
	Node *head2 = lb->head->next;

	while (head1 != NULL)
	{
		int n;
		int e = head1->data;
		(*lb).Locate(e, &n);
		if (n == -1)
		{

			l.Insert(e);
		}
		head1 = head1->next;
	}
	while (head2 != NULL)
	{
		int n;
		int e = head2->data;
		(*la).Locate(e, &n);
		if (n == -1)
		{

			l.Insert(e);
		}
		head2 = head2->next;
	}
	la->DestroyList();
	la->head = l.head;
	la->len = l.len;
}

int main()
{
	List l1("l1"), l2("l2"), l3("l3"), l4("l4");

	// List l;
	cout << "递增表合并" << endl;
	l1.Insert(1).Insert(3).Insert(5).Insert(7).Insert(9).Print();
	l2.Insert(2).Insert(4).Insert(6).Print();
	l1.MergeNode(&l2).Print();

	cout << "寻找共同结点" << endl;
	l3.Insert(1).Insert(2).Insert(3).Insert(4).Print();
	l4.Insert(101).Insert(102).Insert(103).Print();
	l3.InterLinkList(&l4).Print();
	l1.InterLinkList(&l4).Print();

	List l("");
	l.FindCommonNode(&l1, &l3).Print();
	cout << "end" << endl;
}