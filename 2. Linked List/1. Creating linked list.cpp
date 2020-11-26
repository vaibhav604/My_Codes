#include<iostream>
using namespace std;

class Node
{
	public:
		int data;
		Node * next;
		Node(int data)
		{
			this->data=data;
			this->next=NULL;
		}
};

Node *takeInput()  //Complexity=O(n^2) reduced by usingtail pointer
//Now Complexity=O(n)
{
	int data;
	Node *head=NULL;
	Node *tail=NULL;
	cin>>data;
	while(data!=-1)
	{
		Node *n=new Node(data);
		if(head==NULL)
		{
			head=n;
			tail=n;
		}
		else
		{
			tail->next=n;
			tail=tail->next; //tail=n;
		}
		cin>>data;
	}
	return head;
}
void print(Node *head)
{
	Node *temp=head;
	while(temp !=NULL)
	{
		cout<<temp->data<<" ";
		temp=temp->next;
	}
	//cout<<head->data<<endl;
	
}
int main()
{
	/*Node n1(1);
	Node *head=&n1;
	Node n2(2);
	n1.next=&n2;
	cout<<n1.data<<" "<<n2.data<<endl;
	cout<<n1.next->data<<endl;
	//dynamically
	Node *n3=new Node(12);
	Node *head2=n3;
	Node *n4= new Node(15);
	n3->next=n4;*/
	
	/*
	Node n1(1);
	Node *head=&n1;
	Node n2(2);
	n1.next=&n2;
	Node n3(3);
	n2.next=&n3;
	Node n4(4);
	n3.next=&n4;
	Node n5(5);
	n4.next=&n5;
	*/
	Node *head=takeInput();
	
	 print(head);
	return 0;
}

