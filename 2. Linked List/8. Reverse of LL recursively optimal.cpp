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
class Pair
{
	public:
		node* head;
		node *tail;
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
Pair reverse(node *head)
{
	if(head==NULL || head->next==NULL)
	{
		Pair ans;
		ans.head=head;
		ans.tail-head;
	}
	Pair smallAns=reverse(head->next);
	smallAns.tail->next=head;
	head->next=NULL;
	Pair ans;
	ans.head=smallAns.head;
	ans.tail=head;
	return ans;
}
int main()
{
	node *head=takeInput();
	Pair ans=reverse(head); //O(n) complexity
	print(ans.head);
	return 0;
}
