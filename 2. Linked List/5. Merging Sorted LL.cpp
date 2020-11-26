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
node *mergeLL(node *head1,node *head2)
{
	node *fh=NULL;
	node *ft=NULL;
	if(head1->data > head2->data)
	{
		fh=head2;
		ft=head2;
		head2=head2->next;	
	}
	else
	{
		fh=head1;
		ft=head1;
		head1=head1->next;
	}
	while(head1!=NULL && head2!=NULL)
	{
		if(head1->data > head2->data)
		{
			ft->next=head2;
			ft=ft->next;
			head2=head2->next;
		}
		else
		{
			ft->next=head1;
			ft=ft->next;
			head1=head1->next;
		}
	}
	if(head1==NULL)
	{
		ft->next=head2;
	}
	if(head2==NULL)
	{
		ft->next=head1;
	}
	return fh;
}
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
	node *temp=head;
	while(temp!=NULL)
	{
		cout<<temp->data<<" ";
		temp=temp->next;
	}
	cout<<endl;
}

int main()
{
	node *head1=takeInput();
	node *head2=takeInput();
	node *head=mergeLL(head1,head2);
	print(head);	
	
	return 0;
}
