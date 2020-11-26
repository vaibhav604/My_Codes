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
node* findNthNode(node* head,int n)
{
	node* slow=NULL;
	node* fast=head;
	int cnt=1;
	while(cnt<n)
	{
		if(fast)
		{
			fast=fast->next;
		}
		cnt++;
	}
	while(fast)
	{
		if(slow==NULL)
		{
			slow=head;
		}
		else
		{
			slow=slow->next;
		}
		fast=fast->next;
	}
	if(slow)
	{
		return slow;
	}
	return NULL;
}
int main()
{
	node *head=takeInput(); 
	int n;
	cin>>n;
	node* nth=findNthNode(head,n);
	cout<<nth->data<<endl;
	return 0;
}
