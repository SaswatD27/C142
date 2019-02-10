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
	void insert(int a)
	{
		//if head of the linked list is NULL then assign a new node address to head and take input for data members of node
		if(head==NULL)
		{
			head=new node;
			cout<<"Enter an integer - ";
			cin>>head->a;
			head->next=NULL;
		}
		//else create a pointer of the class node titled current and initialise it with the address of head of the linked list
		else if(head!=NULL)
		{
			node *current=head;
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
			//assign a value of NULL to the pointer next of the object current of node
			current->next=NULL;
		}
	}
	//declare an int function countItems 
	int countItems()
	{
		//declare a pointer of class node titled current and initialise it with the value of the node pointer head 
		node *current=head;
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
	void insertAt(int pos,int n)
	{
		if(pos<=countItems()+1)
		{
			int i=1;
			node *current=head;
			while(i<pos)
			{
				i++;
				current=current->next;
			}
			node* temp=current;
			current=new node;
			current->a=n;
			current->next=temp;
			if(pos==1)
			head=current;
		}
		else cout<<"Invalid Input";
	}
	//declare a void function deleteAt with parameter(s) being an int variable p
	void deleteAt(int pos)
	{
		node *current=head;
		//declare int variable i and initialise it as 1
		int i=1;
		if(head==NULL)
		{
			cout<<"Underflow";
		}
		//if the value of the parameter pos is less than or equal to the number of nodes, run the loop, else display error message 
		else if(pos<=countItems())
		{
			//while i is less than pos-1, increment i and assign the value of the address of the next node to current with every iteration
			if(head->next!=NULL)
			{			
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
			else if(head->next==NULL)
			{
				delete head;
				head=NULL;
			}
		}
		else
		cout<<"LOL - Invalid input ";
	}
	void display()	//recursion can also be utilised :P Kinda obvious
	{
		node *current=head;
		int i=1;
		if(head==NULL)
		{
			cout<<"Underflow";
		}
		else
		{
			while(current!=NULL)
			{
				cout<<"Node no. "<<i++<<endl;
				cout<<"Integer value - "<<current->a<<endl;
				current=current->next;
			}
		}
	}
};
class Queue:public llist
{
	public:
	node *first;
	Queue()
	{
		first=NULL;
	}
	void enqueue(int value)
	{
		insertAt(1,value);
		node *current=head;
		while(current->next!=NULL)
		{	
			current=current->next;
		}
		first=current;
	}
	void dequeue()
	{
		if(isEmpty()) cout<<"HAHA";
		else
		{
			deleteAt(countItems());
			node *current=head;
			while(current->next!=NULL&&head!=NULL)
			{	
				current=current->next;
			}
			first=current;
		}
	}
	bool isEmpty()
	{
		if(first==NULL)
		return true;
		else return false;
	}
	int size()
	{
		return countItems();
	}
	void firstDisplay()
	{
		cout<<first->a;
	}
	void display()
	{
		if(head!=NULL)
		{
			node *current=head;
			while(current!=NULL)
			{
				cout<<"<-"<<current->a;
				current=current->next;
			}
		}
		else cout<<"Queue Underflow";
	}
};
class Stack:public llist
{
	public:
	node *top;
	Stack()
	{
		top=NULL;
	}
	void push(int value)
	{
		insertAt(1,value);
		top=head;
	}
	void pop()
	{
		if(isEmpty()) cout<<"HAHA";
		else
		{
			deleteAt(1);
			top=head;
		}
	}
	bool isEmpty()
	{
		if(top==NULL)
		return true;
		else return false;
	}
	int size()
	{
		return countItems();
	}
	void topDisplay()
	{
		cout<<top->a;
	}
	void display()
	{
		if(head!=NULL)
		{
			node *current=head;
			while(current!=NULL)
			{
				cout<<current->a<<"->";
				current=current->next;
			}
		}
		else cout<<"Stack Underflow";
	}
		
};
//write the driver function
int main()
{
	int ch,pos,value;
	cout<<"\t\tStack/Queue Gen"<<endl<<"Stack/Queue? (1/2) - ";	
	cin>>ch;
	if(ch==1)
	{
		Stack s;
		do
		{
			cout<<endl<<"1. Push"<<endl<<"2. Pop"<<endl<<endl<<"3. Check if stack is empty"<<endl<<"4. Display the number of elements"<<endl<<"5. Display top element"<<endl<<"6. Display elements of stack"<<endl<<"0. Exit";
			cout<<endl<<"Make your choice - ";			
			cin>>ch;
			switch(ch)
			{
				case 1:cout<<"Enter an integer value - ";
				       cin>>value;
				       s.push(value);
				       break;
				case 2:s.pop();
				       break;
				case 3:if(s.isEmpty())
				       cout<<"\nStack Underflow";
				       else cout<<"Not Empty";
				       break;
				case 4:cout<<"No. of elements = "<<s.size();
				       break;
				case 5:s.topDisplay();
				       break;
				case 6:s.display();
				       break;
				case 0:break;
				default:cout<<"Wrong Input";
			}
		}while(ch!=0);
	}
	else if(ch==2)
	{
		Queue q;
		do
		{
			cout<<endl<<"1. Enqueue element"<<endl<<"2. Dequeue element"<<endl<<"3. Check if queue is empty"<<endl<<"4. Display the number of elements"<<endl<<"5. Display front element"<<endl<<"6. Display elements of queue"<<endl<<"0. Exit";
			cout<<endl<<"Make your choice - ";			
			cin>>ch;
			switch(ch)
			{
				case 1:cout<<"Enter an integer value - ";
				       cin>>value;
				       q.enqueue(value);
				       break;
				case 2:q.dequeue();
				       break;
				case 3:if(q.isEmpty())
				       cout<<"\nQueue Underflow";
				       else cout<<"Not Empty";
				       break;
				case 4:cout<<"No. of elements = "<<q.size();
				       break;
				case 5:q.firstDisplay();
				       break;
				case 6:q.display();
				       break;
				case 0:break;
				default:cout<<"Wrong Input";
			}
		}while(ch!=0);
	}
	
	return 0;
}
			
