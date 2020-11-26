#include<iostream>
using namespace std;

void merge(int arr[],int si,int li,int m)
{
	int n1,n2;
	n1=m-si+1;
	n2=li-m;
	int L[n1],R[n2];
	for(int i=0;i<n1;i++)
	{
		L[i]=arr[i+si];
	}
	for(int i=0;i<n2;i++)
	{
		R[i]=arr[i+m+1];
	}
	int i=0;
	int j=0;
	int k=si;
	while(i<n1 && j<n2)
	{
		if(L[i]<=R[j])
		{
			arr[k]=L[i];
			i++;
		}
		else
		{
			arr[k]=R[j];
			j++;
		}
		k++;
	}
	while(i<n1)
	{
		arr[k]=L[i];
		i++;
		k++;
	}
	while(j<n2)
	{
		arr[k]=R[j];
		j++;
		k++;
	}
	
	
}
void mergesort(int arr[],int si,int li)
{
	if(si<li)
	{
		int m=(si+li)/2;
		mergesort(arr,si,m);
		mergesort(arr,m+1,li);
		merge(arr,si,li,m);
	}

}
int main()
{
	int arr[]={2,8,6,3,55,23,12,12,34,34,56,67,34,2,8};
	int n=sizeof(arr)/sizeof(arr[0]);
	mergesort(arr,n-3,n-1);
	for(int i=0;i<n;i++)
	{
		cout<<arr[i]<<" ";
	}
	return 0;
}
