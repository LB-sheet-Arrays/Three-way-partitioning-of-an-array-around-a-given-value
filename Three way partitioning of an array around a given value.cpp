/*
A simple solution is to sort the array. This solution does a lot of extra rearrangements and requires O(n Log n) time.

An efficient solution is based on Dutch National Flag based QuickSort. We traverse given array elements from left. 
We keep track of two pointers, first (called start in below code) to store next position of smaller element 
(smaller than range) from beginning; and second (called end in below code) to store next position of greater element from end.

Time Complexity: O(n) 
Auxiliary Space: O(1) 
*/

#include<iostream>

using namespace std;

void swap(int *a,int *b)
{
	int temp;
	temp=*a;
	*a=*b;
	*b=temp;
}

void threeWayPartition(int a[], int n,int lowVal, int highVal)
{
	//declaring and initialising 2 pointers at starting and ending of array
	int start=0;
	int end=n-1;
	
	//instead of m in Dutch national flag Q, i is our iterator now
	for(int i=start;i<=end;)
	{
		if(a[i]<lowVal)
		{
			swap(&a[i],&a[start]);
			start++;                //start pe sahi element aaya hai
			i++;
		}
		else if(a[i]>highVal)
		{
			swap(&a[i],&a[end]);
			end--;
			//i mat badhaao bcoz we have to check for the present element at start with new end
		}
		else
		{
			i++;
		}
	}
	
}

int main()
{
	int arr[] = {1, 14, 5, 20, 4, 2, 54, 20, 87, 98, 3, 1, 32};
    int n = sizeof(arr)/sizeof(arr[0]);
 
    threeWayPartition(arr, n, 10, 20);
 
    cout << "Modified array \n";
    for (int i=0; i<n; i++)
        cout << arr[i] << " ";
	
	return 0;
}


