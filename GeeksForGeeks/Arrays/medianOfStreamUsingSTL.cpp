/* Given that integers are being read from a data stream. Find median
of all the elements read so far starting from the first integer till
the last integer. This is also called Median of Running Integers.
The data stream can be any source of data, example: a file, an array
of integers, input stream, etc.
What is Median ?
Median can be defined as the element in the data set which separates
the higher half of the data sample from the lower half. In other words,
we can get the median element as, when the input size is odd, we take
the middle element of sorted data. If the input size is even, we pick
average of middle two elements in sorted stream.
Example:
Input: 5 10 15
Output: 5
        7.5
        10
    
Explanation: Given the input stream as an array of integers [5, 10, 15].
We will now read integers one by one and print the median 
correspondingly. So, after reading first element 5, median is 5. After
reading 10, median is 7.5. After reading 15, median is 10.

The idea is to use max heap and min heap to store the elements of 
higher half and lower half. Max Heap and min heap can be implemented
usign priority_queue in C++ STL. Below is the step by step algorithm
to solve this problem.
Algorithm:
1. Create two heaps. One max heap to 