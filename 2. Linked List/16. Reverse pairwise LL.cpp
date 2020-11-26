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
node *pairReverse(node *head)
{
	if(head==NULL || head->next==NULL)
	{
		return head;
	}
	else
	{
		node* temp=head->next;
		head->next=temp->next;
		temp->next=head;
		head=temp;
		head->next->next=pairReverse(head->next->next);
		return head;
	}
}
int main()
{
	node *head=takeInput(); 
	head=pairReverse(head);
	print(head);
	return 0;
}
