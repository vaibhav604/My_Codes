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
	tail->next=head;
	return head;
}
void print(node *head)
{
	node* temp=head;
	cout<<temp->data<<" ";
	temp=temp->next;
	while(temp!=head)
	{
		cout<<temp->data<<" ";
		temp=temp->next;
	}
}
void splitLL(node** head,node** head1, node** head2)
{
	if(head==NULL)
	{
		return;
	}
	node* fast=*head;
	node* slow=*head;
	while(fast->next!=*head && fast->next->next!=*head)
	{
		fast=fast->next->next;
		slow=slow->next;
	}
	if(fast->next->next==*head)
	{
		fast=fast->next;
	}
	*head1=*head;
	if((*head)->next!=(*head))
	{
		*head2=slow->next;
	}
	fast->next=slow->next;
	slow->next=*head;
}
int main()
{
	node *head=takeInput();
	node *head1=head;
	node *head2=head;
	splitLL(&head,&head1,&head2);
	print(head1);
	cout<<endl;
	print(head2);
	return 0;
}
