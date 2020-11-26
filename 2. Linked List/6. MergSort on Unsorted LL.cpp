#include<iostream>
using namespace std;

class node
{
	public:
		int data;
		node *next;
	node(int data)
	{
		this->data=data;
		this->next=NULL;
	}
};

node *takeInput()
{
	int data;
	node *head=NULL;
	node *tail=NULL;
	cin>>data;
	while(data!=-1)
	{
		node *n=new node(data);
		if(head==NULL)
		{
			head=n;
			tail=n;
		}
		else
		{
			tail->next=n;
			tail=tail->next;
		}
		cin>>data;
	}
	return head;
}
void print(node *head)
{
	node *temp=head;
	while(temp!=NULL)
	{
		cout<<temp->data<<" ";
		temp=temp->next;
	}
	cout<<endl;
}
void split(node *head,node **a,node **b)
{
	if(head==NULL || head->next==NULL)
	{
		*a=head;
		*b=NULL;
		return;
	}
	node *slow=head;
	node *fast=head->next;
	
	while(fast!=NULL)
	{
		fast=fast->next;
		if(fast!=NULL)
		{
			slow=slow->next;
			fast=fast->next;
		}
	}
	*a=head;
	*b=slow->next;
	slow->next=NULL;
}
node* Merge(node *a,node *b)
{
	if(a==NULL)
	{
		return b;
	}
	else if(b==NULL)
	{
		return a;
	}
	node *fh=NULL;
	if(a->data <= b->data)
	{
		fh=a;
		fh->next=Merge(a->next,b);
	}
	else
	{
		fh=b;
		fh->next=Merge(a,b->next);
	}
	return fh;
}
node *mergeSort(node **head)
{
	if(*head==NULL || (*head)->next==NULL)
	{
		return *head;
	}
	node *a=NULL,*b=NULL;
	split(*head,&a,&b);
	mergeSort(&a);
	mergeSort(&b);
	
	*head=Merge(a,b);
	return *head;
}
int main()
{
	node *head1=takeInput();
	node *head=mergeSort(&head1);
	print(head);	
	
	return 0;
}
