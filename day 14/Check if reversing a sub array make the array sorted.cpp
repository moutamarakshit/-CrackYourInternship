// read the gfg article then practised the checkReverse section on an online IDE 
/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

// C++ program to check whether reversing a
// sub array make the array sorted or not
#include<bits/stdc++.h>
using namespace std;

// Return true, if reversing the subarray will
// sort the array, else return false.
bool checkReverse(int arr[], int n)
{
	int temp[n];
	int front=0,end=n-1;
	for(int i=0; i<n; i++)
		temp[i]=arr[i];
	sort(temp,temp+n);
	for(front=0; front<n; front++) {
		if(temp[front]!=arr[front])
			break;
	}
	for(end=n-1; end>=0; end--) {
		if(temp[end]!=arr[end])
			break;
	}
	if(front>=end) return true;
	front++;
	while(front<=end) {
		if(arr[front]>arr[front-1])
			return false;
		else
			front++;
	}
	return true;
}

// Driver Program
int main()
{
	int arr[] = { 1, 2, 4, 5, 3 };
	int n = sizeof(arr)/sizeof(arr[0]);

	checkReverse(arr, n)? (cout << "Yes" << endl):
	(cout << "No" << endl);
	return 0;
}
