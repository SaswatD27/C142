#include<iostream>
using namespace std;
void swap(int i,int j,int arr[])
{
	int temp=arr[i];
	arr[i]=arr[j];
	arr[j]=temp;
}
void partition(int arr[],int &pivot,int low,int high)
{
	int i=low-1,temp,j=low;
	while(j<high)
	{
		if(arr[j]<=arr[pivot])
		{
			i++;
			swap(i,j,arr);
		}
		j++;
	}
	swap(arr[pivot],arr[i+1]);
	pivot=i+1;
}
void qsort(int arr[],int low,int high)
{
	if(low<high)
	{
		int pivot=high;
		partition(arr,pivot,low,high);
		qsort(arr,low,pivot-1);
		qsort(arr,pivot+1,high);
	}
	else
	{
		cout<<"DONE ";
	}
}	
int main()
{
	int arr[50],low=0,high;
	cout<<"Enter the no. of elements you want to enter - ";
	cin>>high;
	high--;
	for(int i=0;i<=high;i++)
	{
		cout<<endl<<"Enter element no. "<<i+1<<" - ";
		cin>>arr[i];
	}
	qsort(arr,low,high);
	for(int i=0;i<=high;i++)
	{
		cout<<arr[i]<<" ";
	}
	return 0;
}
