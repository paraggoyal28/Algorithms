/*
Given the values in a matrix, this class calculated the maximum value path from start to the end node.
It internally uses memoization to store intermediate results to reduce the number of calls while
backtracking
*/

public class MatrixMaximumValueRouteWithMemo{
	
		// a variable to store the number of recursive calls made 
		private int numRecursiveCalls = 0;
		
		// a matrix to store intermediate values
		private Integer [][] memo;
		
		public int getNumRecursiveCalls(){
			return numRecursiveCalls;
		}
		
		public void incrementNumRecursiveCalls(){
			numRecursiveCalls++;
		}
		
		public Integer[][] getMemo{
			return memo;
		}
		
		public int getMaxValue(int [][] matrix){
			numRecursiveCalls = 0;
			// initialize the number of Recursive Calls to 0.
			memo = new Integer[matrix.length][matrix[0].length];
			return getMaxValue(matrix, 0, 0);
		}
		
		public int getMaxValue(int [][] matrix, int n, int m){
			incrementNumRecursiveCalls();
			if( n < matrix.length && m < matrix[0].length)
			{
				if( n == matrix.length-1 && m == matrix[0].length-1)
				{
					// return the matrix value at n,m and store it in memo[n][m]
					memo[n][m] = matrix[n][m];
					return memo[n][m];
				}
				
				// return the value of memo[n][m] if previously calculated
				if(memo[n][m] != null)
					return memo[n][m];
				
				int downPath = getMaxValue(matrix, n+1, m);
				int rightPath = getMaxValue(matrix, n, m+1);
				
				// calculate maximum of both paths
				int max = Math.max(downPath, rightPath);
				
				// store max + current matrix value
				memo[n][m] = max + matrix[n][m];
				return memo[n][m];
			}
			// if gone out of bounds return 0;
			return INTEGER.MIN_VALUE;
		}
		
		// A utility function to print the values of the memo matrix
		public void printResults(){
			System.out.println("Memo: ");
			for(Integer[] row : memo){
				System.out.print("{");
				for(Integer[] col : row){
					System.out.print(col+", ");
				}
				System.out.print("}, ");
				System.out.println();
			}
			System.out.println();
		}
		
		public static void main(String args[]){
			int [][] matrix1 =	new int[][] {
									{1, 2},
									{3, 4}
			};
			
			int [][] matrix2 = new int[][] {
								{1, 8, 7},
								{3, 4, 2},
								{5, 6, 9}
			};
			
			int [][] matrix3 = new int[][] {
					{1, 2, 3, 4, 5, 6, 7, 8},
					{9, 10, 3, 0, 1, 2, 11, 12},
					{1, 20, 3, 8, 4, 21, 3, 4}
			};
			
			int [][] matrix4 = new int[][] {
					{1, 2, 3, 4, 5, 6, 7, 8},
					{9, 10, 3, 0, 1, 2, 11, 12},
					{1, 20, 3, 8, 4, 21, 3, 4},
					{1, 20, 3, 8, 6, 21, 3, 4},
					{1, 20, 3, 9, 7, 2, 3, 4},
					{1, 21, 7, 2, 14, 29, 3, 4},
					{1, 13, 2, 11, 4, 25, 3, 4},
					{10, 20, 4, 8, 9, 21, 3, 9}
			};
			
			MatrixMaximumValueRouteWithMemo m = new MatrixMaximumValueRouteWithMemo();
			String info = "Matrix dimensions = %s; Max Path Value = %s; Recursive Calls = %s";
			
			System.out.println(String.format(info, "2X2", m.getMaxValue(matrix1), m.getNumRecursiveCalls());
			m.printResults();
			
			System.out.println(String.format(info, "3X3", m.getMaxValue(matrix2), m.getNumRecursiveCalls());
			m.printResults();
			
			System.out.println(String.format(info, "3X8", m.getMaxValue(matrix3), m.getNumRecursiveCalls());
			m.printResults();
			
			System.out.println(String.format(info, "8X8", m.getMaxValue(matrix4), m.getNumRecursiveCalls());
			m.printResults();
			
		}
}
			
		
		
}
			
