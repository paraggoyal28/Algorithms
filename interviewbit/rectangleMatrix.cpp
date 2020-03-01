/* print concentric rectangular pattern in a 2d matrix.
let us show you some examples to clarify what we mean.
Example 1.
Input: A=4
Output:
4 4 4 4 4 4 4
4 3 3 3 3 3 4
4 3 2 2 2 3 4
4 3 2 1 2 3 4
4 3 2 2 2 3 4
4 3 3 3 3 3 4
4 4 4 4 4 4 4

Example 2:
Input: A=3
Output:
3 3 3 3 3
3 2 2 2 3
3 2 1 2 3
3 2 2 2 3
3 3 3 3 3

The outermost rectangle is formed by A, then the next outermost is formed by A-1
and so on.

*/
vector<vector<int> > Solution::prettyPrint(int A){
	vector<vector<int> > vec(2*A-1, vector<int>(2*A-1,0));
	for(int i = 0;i < 2*A-1;i++){
		for(int j = 0;j < 2*A-1; j++){
			vec[i][j] = A - min(min(i, 2*A-2-i),min(j, 2*A-2-j));
		}
	}
	return vec;
}
