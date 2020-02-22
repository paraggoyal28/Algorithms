/* Problem Description 
Given an integer N and an array seats[] where N is the number of people standing 
in a line to buy a movie ticket and seat[i] is the number of empty seats in the 
ith row of the movie theater. The task is to find the maximum amount a theater 
owner can make by selling movie tickets to N people. Price of a ticket is equal
to the maximum number of empty seats among all the rows.
Example:
Input: seats[] = {1,2,4}, N = 3
Output: 9
Input: seats[] = {2,3,5,3} , N = 4
Output: 15
Approach: Use priority_queue 
store count of empty_sets fro every row and maximum of them can be accessed at top
remove top
put top in a variable temp
do temp=temp-1
insert temp back in the priority queue.
*/
#include <bits/stdc++.h>
using namespace std;

int maxAmount(int M, int N, int seats[])
{
	
	priority_queue<int> q;
	
	for (int i = 0; i < M; i++) {
		q.push(seats[i]);
	}
	
	int ticketSold = 0;
	
	int ans = 0;
	
	while(ticketSold < N && q.top() > 0) {
		ans = ans + q.top();
		int temp = q.top();
		q.pop();
		q.push(temp - 1);
		ticketSold++;
	}
	
	return ans;
}

int main()
{
	int seats[] = {1, 2, 4};
	int M = sizeof(seats)/sizeof(int);
	int N = 3;
	cout << maxAmount(N, M, seats);
	return 0;
}

// Output
// 9

