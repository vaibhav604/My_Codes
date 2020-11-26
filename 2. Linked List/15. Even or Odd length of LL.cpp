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
	node*temp=head;
	while(temp!=NULL)
	{
		cout<<temp->data<<" ";
		temp=temp->next;
	}
}
int lengthOddEven(node* head)
{
	node* fast=head;
	while(fast && fast->next)
	{
		fast=fast->next->next;
	}
	if(!fast)
		return 0;
	return 1;
}
int main()
{
	node *head=takeInput(); 
	int k=lengthOddEven(head);
	cout<<k<<endl;
	return 0;
}
