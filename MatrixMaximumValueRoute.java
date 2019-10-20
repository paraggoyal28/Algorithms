/**
Given the values in a matrix , this code calculates the 
maximum value path from start to the end.
**/

public class MatrixMaximumValueRoute{
            
	// variable to store the number of recursive calls to the function
	private int numRecursiveCalls = 0;

	public int getNumRecursiveCalls(){
		return numRecursiveCalls;	
	}

	public void incrementNumRecursiveCalls(){
		numRecursiveCalls++;
	}

	public int getMaxValuePath(int [][] matrix, int n,int m)
	{
		incrementNumRecursiveCalls();
		if(n < matrix.length && m<matrix[0].length)
		{
			if(n == matrix.length - 1 && m == matrix[0].length - 1)
			{
				return matrix[n][m];
			}

			// store the value of down path in variable downPath
			int downPath = getMaxValuePath( matrix, n+1, m);
			// store the value of rightward path in variabel rightPath
			int rightPath = getMaxValuePath( matrix, n, m+1);
			// take the max value from right and bottom path
			int max = Math.max(downPath,rightPath);
			// max value for this particular cell
			return max + matrix[n][m];
		}
		return INTEGER.MIN_VALUE;
	}

	public int getMaxValuePath(int [][] matrix)
	{
		// initialize the number of recursive calls to zero.
		numRecursiveCalls = 0;
		return getMaxValuePath( matrix, 0, 0);
	}
}
					
						
