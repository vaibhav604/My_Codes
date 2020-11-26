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
bool compareLL(node *head1,node* head2)
{
	if(head1==NULL && head2==NULL)
	{
		return 1;
	}
	else if(head1==NULL || head2==NULL)
	{
		return 0;
	}
	if(head1->data==head2->data)
	{
		return compareLL(head1->next,head2->next);
	}
	else
	{
		return 0;
	}
}
int main()
{
	node *head1=takeInput(); 
	node *head2=takeInput();
	cout<<compareLL(head1,head2)<<endl;
	return 0;
}
