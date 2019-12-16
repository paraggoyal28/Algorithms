/**
 * Problem:
 * A sorted array is rotated at some unknown point, find the minimum element in it.
 * Eg. {5, 6, 1, 2, 3, 4} returns 1
 * Eg. {1, 2, 3, 4} returns 1
 * Eg. {2, 1} returns 1
 */
/** 
 * We can do the problem in O(logn) time with binary search.
 * Algorithm:
 * 1. The minimum element is the only element whose previous element is greater than it.If there are no previous elements, 
 * then there is no rotation. We check this condition for middle element by comparing it with (mid-1)th element and (m+1)th element.
 * 2. If the minimum element is not in the middle (neither mid nor mid + 1), then minimum element lies in either the left half or the 
 * right half. 
 *    a. If middle element is smaller than the last element, then the minimum element lies in the left half.
 *    b. Else minimum element lies in the right half.
 */
// Implementation in C++
#include <bits/stdc++.h>
using namespace std;

int findMin(int arr[], int low, int high)
{
	// when array is not rotated at all
	if (high < low)
	{
		return arr[0];
	}
	
	// else if there is only one element left in array
	if (high == low)
	{
		return arr[low];
	}
	
	// Find mid
	int mid = low + (high - low)/2;
	
	// Check if element (mid + 1) is the minimum element. Consider the case like {3, 4, 5, 1, 2}
	if (mid < high && arr[mid + 1] < arr[mid])
	{
		return arr[mid + 1];
	}
	
	// Check if mid itself is the minimum element
	if (mid > low && arr[mid] < arr[mid - 1])
	{
		return arr[mid];
	}
	
	// Decide whether to go left or right
	if (arr[high] > arr[mid])
	{
		return findMin(arr, low, mid - 1);
	}
	else
	{
		return findMin(arr, mid + 1, high);
	}
}

// Driver program
int main()
{
	int arr1[] = {5, 6, 1, 2, 3, 4};
	int n1 = sizeof(arr1)/sizeof(arr1[0]);
	cout << "The minimum element is " << findMin(arr1, 0, n1-1) << endl;
	return 0;
}


