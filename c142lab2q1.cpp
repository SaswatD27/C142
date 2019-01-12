//include libraries
#include<iostream>
using namespace std;
//declare class node
class node
{
	//public members : an integer (a), a character (b) and a pointer to an object of class node (next)
	public:
	int a;
	char b;
	node *next;
	//write constructor to initialise next as NULL
	node()
	{
		next=NULL;
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
void insert(llist &l)
{
	//if head of the linked list is NULL then assign a new node address to head and take input for data members of node
	if(l.head==NULL)
	{
		l.head=new node;
		cout<<"Enter an integer - ";
		cin>>l.head->a;
		cout<<"Enter a character - ";
		cin>>l.head->b;
		l.head->next=NULL;
	}
	//else create a pointer of the class node titled current and initialise it with the address of head of the linked list
	else if(l.head!=NULL)
	{
		node *current=l.head;
		//run while loop till the value of next of the node object current is NULL, updating current with the address of the next node with each iteration
		while(current->next!=NULL)
		{
			current=current->next;
		}
		//assign a new node address to current and take input for data members of node
		current->next=new node;
		current=current->next;
		cout<<"Enter an integer - ";
		cin>>current->a;
		cout<<"Enter a character - ";
		cin>>current->b;
		//assign a value of NULL to the pointer next of the object current of node
		current->next=NULL;
	}
}
//declare an int function countItems with an object l of llist as a parameter
int countItems(llist l)
{
	//declare a pointer of class node titled current and initialise it with the value of the node pointer head 
	node *current=l.head;
	//declare an int type counter count and initialise it with the value of 0
	int count=0;
	//while current is not NULL, run a loop and in each iteration, increment count by 1 and assign the value of the address to the next node to the current node to current
	while(current!=NULL)
	{
		count++;
		current=current->next;
	}
	//return the value of count
	return count;
}
//declare a void function insertAt with the parameters being the address of object l of llist and an int variable pos
void insertAt(llist &l,int pos)
{
	//declare a node pointer current and initialise it with the value of the node pointer head of the object l
	node *current=l.head;
	//declare int variable i and initialise it as 1
	int i=1;
	//if the value of the parameter pos is less than or equal to the number of nodes, run the loop, else display error message 
	if(pos<=countItems(l))
	{
		//while i is less than pos-1, increment i and assign the value of the address of the next node to current with every iteration
		while(i<pos-1)
		{
			current=current->next;
			i++;
		}
		//declare a node pointer temp and point at it the address pointed to by current
		node *temp=current;
		//assign the address of a new node to current and enter the values of the data members pointed to by current now
		current=new node;
		cout<<"Enter an integer - ";
		cin>>current->a;
		cout<<"Enter a character - ";
		cin>>current->b;
		//assign the value of next of the node pointed to by current the value of the address of the next node to temp
		current->next=temp->next;
		//assign the value of current to the pointer next of the node pointed to by temp
		temp->next=current;
	}
	else
	cout<<"U mad bruh? - Invalid input ";
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
//BONUS: write a function delete l with the address of the object l of class llist as a parameter
void deletenodel(llist &l)
{
	//if the head of l points to NULL, display error message
	if(l.head==NULL)
	{
		cout<<"Underflow";
	}
	//otherwise : if the member pointer next of the object pointed to by head has the value NULL, delete the node pointed to by head and assign head a value of NULL  
	else if(l.head!=NULL)
	{
		if(l.head->next==NULL)
		{
			delete l.head;
			l.head=NULL;
		}
		//else declare and point a node pointer current and point it at the head node; then point head to the node next to the one it was originally pointing to and delete the node pointed to by current
		else
		{	
			node *current=l.head;
			l.head=l.head->next;
			delete current;	
		}
	}
}
//write a void function delet() with the parameter being the address of an object l of llist
void delet(llist &l)
{
	//if head is NULL, then display error message
	if(l.head==NULL)
	{
		cout<<"Underflow";
	}
	//else declare a node pointer current and assign it the value of head
	else if(l.head!=NULL)
	{
		node *current=l.head;
		//if the next node pointer of head has the value NULL, delete the head node and assign NULL to head 
		if(l.head->next==NULL)
		{
			delete l.head;
			l.head=NULL;
		}
		//else while the value of the node pointer next of the node pointed to by current is not NULL, assign current the value of its next node with each iteration
		else
		{	
			while(current->next!=NULL)
			{
				current=current->next;
			}
			//declare a node pointer temo and point it at the current node and point current to the head node
			node *temp=current;
			current=l.head;
			//while current's next node is not temp, assign current the value of its next node with each iteration
			while(current->next!=temp)
			{
				current=current->next;
			}
			//assign current's node pointer next a value of NULL
			current->next=NULL;
			//delete the node pointed to by temp
			delete temp;
		}
	}
}
//write a function display with the object l of llist as a parameter
void display(llist l)
{
	//
	node *current=l.head;
	int i=1;
	if(l.head==NULL)
	{
		cout<<"Underflow";
	}
	else
	{
		while(current!=NULL)
		{
			cout<<"Node no. "<<i++<<endl;
			cout<<"Integer value - "<<current->a<<endl<<"Character value - "<<current->b<<endl;
			current=current->next;
		}
	}
}

int main()
{
	int ch;
	llist l;
	int pos;
	do
	{
		cout<<"\n\tLinked List Gen "<<endl<<"1. Insert a node"<<endl<<"2. Delete the first node"<<endl<<"3. Delete the last node"<<endl<<"4. Display the stored values"<<endl<<"5. Insert Node at a particular position"<<endl<<"6. Delete Node from a particular position"<<endl<<"7. Count the number of nodes present"<<endl<<"0. Exit";
		cout<<endl<<"Make your choice - ";
		cin>>ch;
		switch(ch)
		{
			case 1:insert(l);
			       break;
			case 2:deletenodel(l);
			       break;
			case 3:deletenoder(l);
			       break;
			case 4:display(l);
			       break;
			case 5:cout<<"Enter the position at which node is to be inserted - ";
			       cin>>pos;
			       insertAt(l,pos);
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
			
