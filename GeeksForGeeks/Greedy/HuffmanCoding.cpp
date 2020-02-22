/* Prefix Codes, means the codes (bit sequences) are assigned in such 
a way that the code assigned to one character is not the prefix of code
assigned to any other character. This is how Huffman Coding makes sure
that there is no ambiguity when decoding the generated bit stream.
Let us understand prefix codes with a counter example. Let there be four
characters a,b,c, and d, and their corresponding variable length codes
be 00, 01, 0 and 1. This coding leads to ambiguity because code assigned
to c is the prefix of codes assigned to a and b. If the compressed bit
stream is 0001, the de-compressed output may be "cccd" or "ccb" or
"acd" or "ab".

There are mainly two major parts in Huffman Coding
1) Build a Huffman Tree from input characters.
2) Traverse the Huffman Tree and assign codes to characters.
Steps to build Huffman Tree
Input is an array of unique characters along with their frequency of
occurences and output is Huffman Tree.
1. Create a leaf node for each unique character and build a min heap
of all leaf nodes (Min Heap is used as a Priority queue. The value of 
frequency field is used to compare two nodes in min heap. Initially
the least frequent character is at the root).
2. Extract two nodes with the minimum frequency from the min heap.
3. Create a new internal node with a frequency equal to the sum of the
two nodes frquencies. Make the first extracted node as its left child
and other extracted node as its right child. Add this node to the min
heap.
4. Repeat steps #2 and #3 until the heap contains only one node. The
remaining node is the root node and the tree is complete.

Let us understand the algorithm with an example:
character                          Frequency
  a                                  5
  b                                  9
  c                                  12
  d                                  13
  e                                  16
  f                                  45

Step 1. Build a min heap that contains 6 nodes where each node 
represents root of a tree with single node.
Step 2. Extract two minimum frequency nodes from min heap. Add a 
new internal node with frequency 5 + 9 = 14
                14
               /  \ 
              5    9
Now min heap contains 5 nodes where 4 nodes are roots of trees 
with single element each, and one heap node is root of tree with 
3 elements 