/**
This class finds the number of unique ways to reach from start point to end point going only right and down 
with memoziation to reduce number of recursive calls 
**/

public class MatrixRouteMemo {
    
        // variable to keep track of number of recursive calls
        private int numRecursiveCalls = 0;
        
        // variable to hold the memoized matrix
        private Integer[][] memo;
        
        public int getNumRecursiveCalls(){
            return numRecursiveCalls;
        }
        
        public void incrementNumRecursiveCalls(){
            numRecursiveCalls++;
        }
        
        public Integer[][] getMemo(){
           return memo;
        }
        
        public int countPaths(int [][] matrix){
          numRecursiveCalls = 0;
          // initialize memo
          memo = new Integer[matrix.length][matrix[0].length];
          // start from top left of the matrix
          return countPaths(matrix, 0, 0);
       }
       
       public int countPaths(int [][] matrix, int n, int m){
           incrementNumRecursiveCalls();
          if(n < matrix.length && m < matrix[0].length)
          {
            if(n == matrix.length - 1 && m == matrix[0].length - 1)
            {
                memo[n][m] = 1;
                return memo[n][m];
            }
            // if memo[n][m] is already calculated return it
            
            if(memo[n][m] != null)
              return memo[n][m];
            
            // else calculate memo[n][m]
            
            memo[n][m] = countPaths(matrix, n+1, m) + countPaths(matrix, n, m+1);
            return memo[n][m];
          }
          return 0;
       }
}
