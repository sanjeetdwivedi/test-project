//******DCLL********
#include<iostream>
#include<stdlib.h>
#include<string.h>
using namespace std;
class Node
{
	public:
		Node *prev;
		int data;
		Node *next;
		Node()
		{
			cout<<"Enter Data: ";
			cin>>data;
			prev=next=NULL;
		}
		Node(int a)
		{
			data=a;
			prev=next=NULL;
		}
};
class DCLL
{
	Node *front,*rear;
	public:
		DCLL()
		{
			front=rear=NULL;
		}
		void create();
		void show();
		int search(int s);
		int count();
		void add_at_beg();
		void add_at_end(int);
		void add_by_pos(int);
		void del_at_beg();
		void del_at_end();
		void del_by_pos(int);
};
int main()
{
	DCLL T;
	int choice;
	do
	{
		cout<<"\n-------------------------------------\n";
		cout<<"\n*****OPERATIONS ON DCLL******";
		cout<<"\n\t0: To Exit.";
		cout<<"\n\t1: Create Linked list.";
		cout<<"\n\t2: Show linked list.";
		cout<<"\n\t3: Add node at beg.";
		cout<<"\n\t4: Add node at end.";
		cout<<"\n\t5: Add node by position.";
		cout<<"\n\t6: Delete node at beg.";
		cout<<"\n\t7: Delete node at end.";
		cout<<"\n\t8: Delete node by position.";
		cout<<"\n\t9: To search a number.";
		cout<<"\n\t10: To count total number of Nodes.";
		cout<<"\nEnter your choice: ";
		cin>>choice;
		switch(choice)
		{
			case 1:T.create();
				break;
			case 2:T.show();
				break;
			case 3:T.add_at_beg();
				break;
			case 4:int c;
				cout<<"\nEnter data: ";
				cin>>c;
				T.add_at_end(c);
				break;
			case 5:int p;
				cout<<"\nEnter the position at which node to be added :  ";
				cin>>p;
				T.add_by_pos(p);
				break;
			case 6:T.del_at_beg();
				break;
			case 7:T.del_at_end();
				break;
			case 8:int d;
				cout<<"\nEnter the position of node to be deleted :  ";
				cin>>d;
				T.del_by_pos(d);
				break;
			case 9:int x;
				cout<<"\nEnter number to search\n";
				cin>>x;
				if(T.search(x))
				{
					cout<<"Found";
				}
				else
				{
					cout<<"Not found";
				}
				break;
			case 10:cout<<"\n\nTotal Nodes= "<<T.count();
				break;
			default:cout<<"\nInvalid choice.\n";
		}
	}while(choice!=0);
	return 0;
}
void DCLL::create()
{
	cin.ignore(1);
	char ch[10];
	int x;
	cout<<"\nKeep Entering nodes.";
	cout<<"\nIf iu want to stop,Enter 'STOP'\n";
	while(1)
	{
		cout<<"Enter Data : ";
		cin.getline(ch,9);
		if(strcmp(ch,"STOP")==0)
		{
			break;
		}
		x=atoi(ch);
		add_at_end(x);
	}
	cout<<"\n List Created.";
}
void DCLL::show()
{
	Node *p=front;
	do
	{
		cout<<"\nData= "<<p->data;
		p=p->next;
	}while(p!=front);
}
int DCLL::count()
{
	int cnt;
	Node *p=front;
	do
	{
		cnt++;
		p=p->next;
	}while(p!=front);
	return cnt;
}
int DCLL::search(int s)
{
	Node *p=front;
	do
	{
		if(p->data==s)
		{
			return 1;
		}
		p=p->next;
	}while(p!=front);
	return 0;
}
void DCLL::add_at_beg()
{
	Node*q;
	q=new Node();
	if(front==NULL)
	{
		front=rear=q;
		front->prev=rear;
	}
	else
	{
		q->next=front;
		q->prev=rear;
		front->prev=q;
		front=q;
	}
	rear->next=front;
}
void DCLL::add_at_end(int e)
{
	Node *q;
	q=new Node(e);
	if(front==NULL)
	{
		front=rear=q;
		rear->next=front;
		front->prev=q;
	}
	else
	{
		q->next=front;
		q->prev=rear;
		rear->next=q;
		front->prev=q;
		rear=q;
	}
}
void DCLL::add_by_pos(int pos)
{
	Node *p,*q;
	int n,i;
	n=count();
	if(pos<1 || pos>n+1)
	{
		cout<<"\nInvalid position.";
		return ;
	}
	if(pos==1)
	{
		add_at_beg();
	}
	else
	{
		q=new Node();
		p=front;
		for(i=1;i<pos-1;i++)
		{
			p=p->next;
		}
		q->next=p->next;
		q->prev=p;
		p->next=q;
		q->next->prev=q;
		if(p==rear)
		{
			rear=q;
		}
	}
}
void DCLL::del_at_beg()
{
	Node *p;
	if(front==NULL)
	{
		cout<<"\nList Empty, can't Delete.\n";
		return ;
	}
	if(front==rear)
	{
		delete front;
		rear=front=NULL;
	}
	else
	{
		p=front;
		front=front->next;
		rear->next=front;
		front->prev=rear;
		delete p;
	}
}
void DCLL::del_at_end()
{
	Node *p;
	if(front==NULL)
	{
		cout<<"\nList Empty, can't Delete.\n";
		return ;
	}
	if(front==rear)
	{
		delete front;
		rear=front=NULL;
	}
	else
	{
		p=front;
		while(p->next!=rear)
		{
			p=p->next;
		}
		p->next=rear->next;
		delete rear;
		rear=p;
		front->prev=rear;
	}
}
void DCLL::del_by_pos(int pos)
{
	int n,i;
	Node *p,*q;
	n=count();
	if(pos<1 || pos>n)
	{
		cout<<"\nInvalid Position\n";
		return ;
	}
	if(pos==1)
	{
		del_at_beg();
	}
	else
	{
		p=front;
		for(i=1;i<pos-1;i++)
		{
			p=p->next;
		}
		q=p->next;
		p->next=q->next;
		q->next->prev=p;
		if(q==rear)
		{
			rear=p;
		}
		delete q;
	}
}
