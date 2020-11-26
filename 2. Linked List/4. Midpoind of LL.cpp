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
int length(node *head)
{
	node *temp=head;
	if(temp->next==NULL)
	{
		return 1;
	}
	return 1+length(temp->next);
}
int main()
{
	node *head=takeInput();
	int l=length(head);
	node *slow=head;
	node *fast=head;
	while(fast!=NULL)
	{
		fast=fast->next;
		if(fast!=NULL)
		{
			slow=slow->next;
			fast=fast->next;
		}
	}
	cout<<slow->data<<endl;
	
	return 0;
}
