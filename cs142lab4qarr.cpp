#include<iostream>
using namespace std;
class QueueArr
{
	public:
	int arr[50];
	int first,n;
	QueueArr()
	{
		first=0;
		n=0;
	}
	void enqueue(int val)
	{
		arr[n++]=val;
	}
	void dequeue()
	{
		if(n>1)
		{
			for(int i=1;i<n;i++)
			{
				arr[i-1]=arr[i];
			}
		}
		n--;
	}
	void Display()
	{
		if(isEmpty())
		cout<<"Underflow";
		else
		{
			for(int i=first;i<n;i++)
			{
				cout<<arr[i]<<" , ";
			}
		}
	}
	bool isEmpty()
	{
		if(n==0) return 1;
		else return 0;
	}
	int size()
	{
		return n;
	}
};
int main()
{
	QueueArr s;
	int ch,value;
	do
	{
		cout<<"\n\nQueue Gen\n\n1. Enqueue element\n2. Dequeue element\n3. Display contents of queue\n4. Display size of queue\n5. Check if queue is empty\n0. Exit Menu\n";
		cin>>ch;
		switch(ch)
		{
			case 1:cout<<"Enter int value - ";
			       cin>>value;
			       s.enqueue(value);
			       break;
			case 2:if(s.isEmpty())
			       {
			       		cout<<"Underflow";
			       }
			       else
			       cout<<"Deleting first element - "<<s.arr[s.first];
			       s.dequeue();
			       break;
			case 3:s.Display();
			       break;
			case 4:cout<<"Size of queue is "<<s.size();
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
