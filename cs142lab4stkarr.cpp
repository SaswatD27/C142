#include<iostream>
using namespace std;
class StackArr
{
	public:
	int arr[50];
	int top;
	StackArr()
	{
		top=-1;
	}
	void push(int val)
	{
		arr[++top]=val;
	}
	void pop()
	{
		top--;
	}
	void Display()
	{
		for(int i=top;i>=0;i--)
		{
			cout<<arr[i]<<" , ";
		}
	}
	bool isEmpty()
	{
		if(top==-1) return 1;
		else return 0;
	}
	int size()
	{
		return top+1;
	}
};
int main()
{
	StackArr s;
	int ch,value;
	do
	{
		cout<<"\n\nStack Gen\n\n1. Push element\n2. Pop element\n3. Display contents of stack\n4. Display size of stack\n5. Check if stack is empty\n0.Exit Menu";
		cin>>ch;
		switch(ch)
		{
			case 1:cout<<"Enter int value - ";
			       cin>>value;
			       s.push(value);
			       break;
			case 2:if(s.isEmpty())
			       {
			       		cout<<"Underflow";
			       }
			       else
			       cout<<"Deleting top element - "<<s.arr[s.top];
			       s.pop();
			       break;
			case 3:s.Display();
			       break;
			case 4:cout<<"Size of stack is "<<s.size();
			       break;
			case 5:if(s.isEmpty())
			       cout<<"You have exactly nada. Congratulations.";
			       else cout<<"Not empty.";
			       break;
			case 0:
			default:break;
		}
	}while(ch!=0);
	return 0;
}
