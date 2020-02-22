# We are given an unsorted array with both positive and negative 
# elements.We have to find the smallest positive number missing from 
# the array in O(n) time using constant extra space. We can modify the
#original array.
#Examples:
#Input: {2, 3, 7, 6, 8, -1, -10, 15}
#Output: 1
#Input: {2, 3, -7, 6, 8, 1, -10, 15}
#Output: 4
#Input: {1, 1, 0, -1, -2}
#Output: 2
#A naive method to solve this problem is to search all positive integers,
#starting from 1 in the given array. We may have to search at most n+1
#numbers in the given array. So this solution takes O(n^2) in worst case.
#We can use sorting to solve it in lesser time complexity. We can sort
#the array in O(nlogn) time. Once the array is sorted, than all we need
#to do is linear scan of the array. So this approach takes O(nlogn + n)
#time which is O(nlogn).
#We can also use hashing. We can build a hash table of all positive 
#lements in the given array. Once the hash table is built. We can look
#in the hash table for all positive integers, starting from 1. As 
# soon as we find a number which is not there in hash table, we return it.
#This approach may take O(n) time on average, but it requires O(n) 
#extra space.
#A O(n) time and O(1) extra space solution:
#We use array elements as index. To mark presence of an element x, we
#change the value at the index x to negative. But this approach doesn't 
#work if there are non positive numbers. So we segregate positive from
#negative numbers as first step and then apply the approach.
#Following is the two step algorithm.
#1) Segregate positive numbers from others i.e, move all non-positive 
#numbers to left side. In the following code, segregate() function does
#this part.
#2) Now we can ignore non-positive elements and consider only the part
#of the array which contains all positive elements. We traverse
#the array containing all positive numbers and to mark presence of an
#element x, we change the sign of value at index x to negative. We
#traverse the array again and print the first index which has positive 
#value. In the following code, findMissingPositive() function does this
#part. Note that in findMissingPositive, we have subtracted 1 from the
#values as indexes start from 0 in C.
#Note that this method modifies the original array. We can change the 
#sign of the elements in the segregated array to get the same set of 
#elements back. But we still loose the order of elements. If we want
#to keep the original array as it was, then we can create a copy of the
#array and run this approach on the temp array.
#Another approach: In this problem, we have created a list full of 0's
#with size of the max() value of our given array. Now, whenever we encounter
#any positive value in our original array, we change the index value of 
#our list to 1. So, after we are done, we simply iterate through our 
#modified list, the first 0 we encounter, its (index value + 1) should 
#be our answer since index in python starts from 0.
#Below is the implementation of above approach:
# Python Program to find the smallest 
# positive missing number

def solution(A): #Our original array
    m = max(A)
    if m < 1:
        # In case all values in our array are negative
        return 1
    if len(A) == 1:
        # If it contains only one element
        return 2 if A[0] == 1 else 1
    l = [0] * m
    for i in range(len(A)):
        if A[i] > 0:
            if l[A[i] - 1] != 1:
                # Changing the value status at the index of our list
                l[A[i] - 1] = 1
    for i in range(len(l)):
        # Encountering first 0, i.e, the element with least value
        if l[i] == 0:
            return i + 1
            # In case all values are filled between 1 and m
    return i + 2

A = [0, 10, 2, -10, -20]
print(solution(A))

