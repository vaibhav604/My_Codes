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
int main()
{
	node *head=takeInput();
	print(head); 
	return 0;
}
