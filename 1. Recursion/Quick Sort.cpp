#include<iostream>
using namespace std;
void swap(int* a,int *b)
{
	int t=*a;
	*a=*b;
	*b=t;
}
int partition(int arr[],int si, int li)
{
	//from left to right traversal
	/*int pivot=arr[li];
	int i=si-1;
	for(int j=si;j<li;j++)
	{
		if(arr[j]<=pivot)
		{
			i++;
			swap(&arr[i],&arr[j]);
		}
	}
	swap(&arr[i+1],&arr[li]);
	return (i+1);*/
	//from right to left traversal
	int pivot=arr[si];
	int i=li+1;
	for(int j=li;j>si;j--)
	{
		if(arr[j]>pivot)
		{
			i--;
			swap(&arr[i],&arr[j]);
		}
	}
	swap(&arr[i-1],&arr[si]);
	return (i-1);
}
void quicksort(int arr[],int si, int li)
{
	if(si<li)
	{
		int m=partition(arr,si,li);
		quicksort(arr,si,m-1);
		quicksort(arr,m+1,li);		
	}
}

int main()
{
	int arr[]={2,8,6,3,55,23,12,12,34,34,56,67,34,2,8};
	int n=sizeof(arr)/sizeof(arr[0]);
	quicksort(arr,0,n-1);
	for(int i=0;i<n;i++)
	{
		cout<<arr[i]<<" ";
	}
	return 0;
}
