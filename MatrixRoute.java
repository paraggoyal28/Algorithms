/**
Question 
We are given a matrix of integers and start and end point . We have to find the number of unique paths from source to end point with 
end point assumed to be in the end and start point assumed to be at (0,0). We can always go right or go down to reach the end. 
It is assumed that the end point is always reachable from the start point
*/

public class MatrixBestRoute{

            // variable to keep track of the number of recursive calls.
            private int numRecursiveCalls = 0;
            
            public int getNumRecursiveCalls(){
                return numRecursiveCalls;
            }
            
            public void incrementNumRecursiveCalls(){
                numRecursiveCalls++;
            }
            
            public int countPaths(int [][] matrix, int n, int m){
                incrementNumRecursiveCalls();
                if(n < matrix.length && m < matrix[0].length){
                  if( n == matrix.length - 1 && m == matrix[0].length - 1 ){
                    // End Point E is supposed to be in end 
                    return 1;
                  }
                  
                   // Return the sum of unique paths reachable from going right or down
                  return countPaths( matrix, n+1, m ) + countPaths( matrix, n, m+1 ); 
               }
               // Return 0 in case of point not in the range
               return 0;
           }
           public int countPaths(int [][] matrix)
           {
              numRecursiveCalls = 0;
              // start from top left of the matrix;
              return countPaths( matrix, 0 ,0);
           }
}
