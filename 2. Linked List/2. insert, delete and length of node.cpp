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
	/*node* a=temp->next;
	temp->next=n;
	n->next=a;*/
	if(temp!=NULL)
	{
			n->next=temp->next;
			temp->next=n;
	}	
	return head;
}

node *deleteNode(node *head,int pos)
{
	node *temp=head;
	int count=0;
	if(pos==0)
	{
		head=head->next;
		delete temp;
		return head;
	}
	while(count<pos-1 && temp!=NULL)
	{
		temp=temp->next;
		count++;
	}
	if(temp!=NULL)
	{
		node *n=temp->next->next;
		delete temp->next;
		temp->next=n;
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
	print(head);
	//int data,pos;
	//cin>>pos>>data;
	//head=insertNode(head,pos,data);
	//print(head);
	/*int pos;
	cin>>pos;
	head=deleteNode(head,pos);
	print(head);
	*/
	int l=length(head);
	cout<<endl<<l<<endl;
	return 0;
}
