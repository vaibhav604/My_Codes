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

node* insertNode(node* head,int i,int data)
{
	node *n=new node(data);
	int count=0;
	node *temp=head;
	if(i==0)
	{
		n->next=head;
		head=n;
		return head;
	}
	while(temp!=NULL && count<i-1)
	{
		temp=temp->next;
		count++;
	}
	if(temp!=NULL)
	{
			n->next=temp->next;
			temp->next=n;
	}	
	return head;
}
node *reverse(node *head)
{
	if(head==NULL || head->next==NULL)
	{
		return head;
	}
	node *smallAns=reverse(head->next);
	node *temp=smallAns;
	while(temp->next!=NULL)
	{
		temp=temp->next;
	}
	temp->next=head;
	head->next=NULL;
	return smallAns;
}
int main()
{
	node *head=takeInput();
	head=reverse(head); //O(n2) complexity
	print(head);
	return 0;
}
