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
	if(head==NULL)
	{
		return head;
	}
	if(i==0)
	{
		node *n=new node(data);
		n->next=head;
		head=n;
		return head;
	}
	head->next=insertNode(head->next,i-1,data);
	return head;	
}

node *deleteNode(node *head,int pos)
{
	if(head==NULL)
	{
		return head;
	}
	if(pos==0)
	{
		node* temp=head;
		head=head->next;
		delete(temp);
		return head;	
	}
	head->next=deleteNode(head->next,pos-1);
	return head;

}
int main()
{
	node *head=takeInput();
	print(head);
	/*int data,pos;
	cin>>pos>>data;
	head=insertNode(head,pos,data);
	print(head);*/
	int pos;
	cin>>pos;
	head=deleteNode(head,pos);
	print(head);
	
	return 0;
}
