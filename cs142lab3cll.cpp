//include libraries
#include<iostream>
using namespace std;
//declare class node
class node
{
	//public members : an integer (a), a character (b) and a pointer to an object of class node (next)
	public:
	int a;

	node *next;
	//write constructor to initialise next as NULL
	node()
	{
		next=NULL;
	}
	node(int value)
	{
		next=NULL;
		a=value;
	}
};
//declare class llist
class llist
{
	//public members : a pointer to an object of class node (head)
	public:
	node *head;
	//write constructor to initialise head as NULL
	llist()
	{
		head=NULL;
	}
};
//declare a void function insert() with the address of an object l of class llist as a parameter
void insert(llist &l,int value)
{
	node *temp=new node(value);
	if(l.head==NULL)
	{
		l.head=temp;
		temp=l.head;
	}
	else if(l.head!=NULL)
	{
		node *current=l.head;
		while(current->next!=l.head)
		current=current->next;
		current->next=temp;
	}
	temp->next=l.head;
}
//declare an int function countItems with an object l of llist as a parameter
int countItems(llist l)
{
	//declare a pointer of class node titled current and initialise it with the value of the node pointer head 
	node *current=l.head;
	//declare an int type counter count and initialise it with the value of 0
	int count=0;
	//while current is not NULL, run a loop and in each iteration, increment count by 1 and assign the value of the address to the next node to the current node to current
	do
	{
		count++;
		current=current->next;
	}while(current!=l.head);
	//return the value of count
	return count;
}
//declare a void function insertAt with the parameters being the address of object l of llist and an int variable pos
void insertAt(llist &l,int pos,int value)
{
	node *temp=new node(value);
	node *current=l.head;
	if(pos>countItems(l))
	cout<<"Wrong input";
	else
	{
		int count=1;
		while(count!=pos-1)
		{
			count++;
			current=current->next;
		}	
		temp->next=current->next;
		current->next=temp;
	}
}
//declare a void function deleteAt with parameters being the address of llist object l and an int variable p
void deleteAt(llist &l,int pos)
{
	//declare a node pointer current and initialise it with the value of the node pointer head of the object l
	node *current=l.head;
	//declare int variable i and initialise it as 1
	int i=1;
	//if the head of l points to NULL, display error message
	if(l.head==NULL)
	{
		cout<<"Underflow";
	}
	//if the value of the parameter pos is less than or equal to the number of nodes, run the loop, else display error message 
	else if(pos<=countItems(l))
	{
		//while i is less than pos-1, increment i and assign the value of the address of the next node to current with every iteration
		while(i<pos-1)
		{
			current=current->next;
			i++;
		}
		//assign temp the address of the node next to the one pointed to by current and that of the member next of the node pointed to by temp to the member next of the node pointed to by current
		node *temp=current->next;
		current->next=temp->next;
		delete temp;
	}
	else
	cout<<"LOL - Invalid input ";
}

//write a void function delet() with the parameter being the address of an object l of llist
void delet(llist &l)
{
	//if head is NULL, then display error message
	if(l.head==NULL)
	{
		cout<<"Underflow";
	}
	else if(l.head!=NULL)
	{
		node *current=l.head;
		if(l.head->next==l.head)
		{
			delete l.head;
			l.head=NULL;
		}
		else
		{	
			while(current->next!=l.head)
			{
				current=current->next;
			}
			node *temp=current;
			current=l.head;
			while(current->next!=temp)
			{
				current=current->next;
			}
			current->next=l.head;
			delete temp;
		}
	}
}
//write a function display with the object l of llist as a parameter
void display(llist l)	//recursion can also be utilised :P Kinda obvious
{

	node *current=l.head;
	int i=1;
	if(l.head==NULL)
	{
		cout<<"Underflow";
	}
	else
	{
		do		
		{
			cout<<"Node no. "<<i++<<endl;
			cout<<"Integer value - "<<current->a<<endl;
			current=current->next;
		}
		while(current!=l.head);
	}
}

int main()
{
	int ch;
	llist l;
	int pos,value;
	do
	{
		cout<<"\n\tLinked List Gen "<<endl<<"1. Insert a node"<<endl<<"3. Delete the last node"<<endl<<"4. Display the stored values"<<endl<<"5. Insert Node at a particular position"<<endl<<"6. Delete Node from a particular position"<<endl<<"7. Count the number of nodes present"<<endl<<"0. Exit";
		cout<<endl<<"Make your choice - ";
		cin>>ch;
		switch(ch)
		{
			case 1:cout<<"Enter an int value - ";
			       cin>>value;
			       insert(l,value);
			       break;
			case 3:delet(l);
			       break;
			case 4:display(l);
			       break;
			case 5:cout<<"Enter the position at which node is to be inserted - ";
			       cin>>pos;
			       cout<<"Enter an int value - ";
			       cin>>value;
			       insertAt(l,pos,value);
			       break;
			case 6:cout<<"Enter the position from which node is to be deleted - ";
			       cin>>pos;
			       deleteAt(l,pos);
			       break;
			case 7:cout<<"No. of nodes- "<<countItems(l);
			       break;
			case 0:break;
			default:cout<<"Give da right input, ya scallawag!";
				break;
		}
	}while(ch!=0);
	return 0;
}
			
