/* 
Greedy is an algorithmic paradigm that builds up a solution piece by 
piece, always choosing the next piece that offers the most obvious and
immediate benefit. Greedy algorithms are used for optimization problems.
An optimizing problem can be solved using Greedy if the problem has the
following property: At every step, we can make a choice that looks best 
at the moment, and we get the optimal solution of the complete problem.
Following is the problem statement:
You are given n activities with their start and finish times.Select the
maximum number of activities that can be performed by a single person,
assuming that a person can only work on a single activity at a time.
Example:
Example 1: Consider the following 3 activities sorted by the finish time.
start[] = {10, 12, 20};
finish[] = {20, 25, 30};
A person can perform at most two activities. The maximum set of activities
that can be executed is {0, 2}.
Example 2: Consider the following 6 activities sorted by the finish time.
start[] = {1, 3, 0, 5, 8, 5};
finish[] = {2, 4, 6, 7, 9, 9};
A person can perform at most 4 activities. The maximum set of activities
that can be executed is {0, 1, 3, 4}.
The greedy choice is to always pick the next activity whose finish time
is least among the remaining activities and start tine is more than or 
equal to the finish time of previously selected activity. We can sort 
the activities according to their finishing times so that we always 
consider the next activity as the minimum finishing time activity.
1. Sort the activities according to their finishing times.
2. Select the first activity from the sorted array and print it.
3. Do following for the remaining activities in sorted array.
......a) If the start time of this activity is greater than or equal to 
the finish time of the previously selected activity then select this
activity and print it.
In below code it is assumed that the activities are already sorted
according to their finish times.
C/C++ Code:
*/
#include<stdio.h>
void printMaxActivities(int s[], int f[], int n)
{
    int i, j;
    printf("Following activities are selected\n");
    // the first activity always get selected
    i = 0;
    printf("%d", i);
    // Consider rest of the activities
    for(j = 1; j < n; j++)
    {
        if(s[j] >= f[i])
        {
            printf("%d ", j);
            i = j;
        }
    }
}
// driver program to test above function
int main()
{
    int s[] = {1, 3, 0, 5, 8, 5};
    int f[] = {2, 4, 6, 7, 9, 9};
    int n = sizeof(s)/sizeof(s[0]);
    printMaxActivities(s, f, n);
    return 0;
}
