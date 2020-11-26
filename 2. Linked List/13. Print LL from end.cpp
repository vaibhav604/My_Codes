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
void printReverse(node* head)
{
	if(!head)
	{
		return;
	}
	printReverse(head->next);
	cout<<head->data<<" ";
}
int main()
{
	node *head=takeInput(); 
	printReverse(head);
	return 0;
}
