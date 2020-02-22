/* Given an array arr[] of distinct integers from 1 to N. The task is to
find the minimum number of swaps required to sort the array.
Example:
Input: arr[ ] = {7, 1, 3, 2, 4, 5, 6}
Output: 5
Explanation:
i                arr                        swap      (indices)
0         [7, 1, 3, 2, 4, 5, 6]             swap      (0,6)
1         [6, 1, 3, 2, 4, 5, 7]             swap      (0,5)
2         [5, 1, 3, 2, 4, 6, 7]             swap      (0,4)
3         [4, 1, 3, 2, 5, 6, 7]             swap      (0,3)
4         [2, 1, 3, 4, 5, 6, 7]             swap      (0,1)
5         [1, 2, 3, 4, 5, 6, 7]             done
Therefore, the total number of swaps = 5

Input: arr[] = {2, 3, 4, 1, 5}
Output: 3
Explanation:
i                arr                        swap       (indices)
0             [2, 3, 4, 1, 5]               swap       (0,1)
1             [3, 2, 4, 1, 5]               swap       (0,2)
2             [4, 2, 3, 1, 5]               swap       (0,3)
3             [1, 2, 3, 4, 5]

Approach:
1. For each index in arr[].
2. Check if the current element is in it's right position or not. Since
the array contains distinct elements from 1 to N, we can simply compare
the element with it's index in array to check if it is at its right
position.
3. If the current element is not at its right position then swap the 
element with the elemnt which has occupied its place.
4. Else check for the next index.
Below is the implementation detail of the above explanation

Java program to find the minimum number of swaps required to sort 
the given array
*/
import java.io.*;
import java.util.*;

class GFG {
    // Function to find the minimum swaps
    static int minimumSwaps(int [] arr){
        int count = 0;
        int  i = 0;
        while (i < arr.length) {
            
            // If current element is not at the right position
            if (arr[i] != i+1){
                while(arr[i] != i+1){
                    int temp = 0;
                    // Swap current element with the correct position
                    // of that element
                    temp = arr[arr[i] - 1];
                    arr[arr[i] - 1 ] = arr[i];
                    arr[i] = temp;
                    count++;
                }
            }
            // Increment for the next index
            // when current element is at the correct position
            i++;
        }
        return count;
    }
    // Driver Code
    public static void main(String[] args){
        int arr[] = {2, 3, 4, 1, 5};
        
        // Function to find the minimum swaps
        System.out.println(minimumSwaps(arr));
    }
}