# SrGrace's InterviewBit-Wiki

Collection of solution for problems on https://www.interviewbit.com

##Contents

* [Arrays](#arrays)  
* [Math](#math)
* [Heaps And Maps](#Heaps-And-Maps)
* [BackTracking](#backtracking)
* [Binary Search](#binary-search)
* [Bit Manipulation](#bit-manipulation)
* [Hashing](#hashing)
* [Linked List](#linked-list)
* [Stacks and Queues](#stacks-and-queues)
* [Strings](#strings)
* [Two Pointers](#two-pointers)


### Arrays
---

####[Add one to number](https://www.interviewbit.com/problems/add-one-to-number/)
Given a non-negative number represented as an array of digits, add 1 to the number ( increment the number represented by the digits ). 
The digits are stored such that the most significant digit is at the head of the list.
<br><br>
**Example:** If the vector has **[1, 2, 3]** the returned vector should be ***[1, 2, 4]***
as 123 + 1 = 124.
<br><br>
**Note**: The result may be very large, so you need to return a string instead of an integer.
<br><br>
[Solution](https://github.com/SrGrace/InterviewBit/blob/master/Arrays/AddOneToNumber.cpp)
<br>
<br>
<br>

####[Find duplicate in array](https://www.interviewbit.com/problems/find-duplicate-in-array/)
Given a read only array of n + 1 integers between 1 and n, find one number that repeats in linear time using less than O(n) space and traversing the stream sequentially O(1) times.
<br><br>
**Example:** For **[3, 4, 1, 4, 1]**, you should return ***1***.
<br><br>
**Note**: If there are multiple possible answers ( like in the sample case above ), output any one.
<br><br>
[Solution](https://github.com/SrGrace/InterviewBit/blob/master/Arrays/FindDuplicateInArray.cpp)
<br>
<br>
<br>

####[First missing integer](https://www.interviewbit.com/problems/first-missing-integer/)
Given an unsorted integer array, find the first missing positive integer.
<br><br>
**Example:** For **[1,2,0]** return ***3***, **[3,4,-1,1]** return ***2***, **[-8, -7, -6]** returns ***1***
<br><br>
**Note**: Your algorithm should run in O(n) time and use constant space.
<br><br>
[Solution](https://github.com/SrGrace/InterviewBit/blob/master/Arrays/FirstMissingInteger.cpp)
<br>
<br>
<br>

###[flip](https://www.interviewbit.com/problems/flip/)
You are given a binary string(i.e. with characters 0 and 1) S consisting of characters S1, S2, …, SN. In a single operation, you can choose two indices L and R such that 1 ≤ L ≤ R ≤ N and flip the characters SL, SL+1, …, SR. By flipping, we mean change character 0 to 1 and vice-versa.
<br>
Your aim is to perform ATMOST one operation such that in final string number of 1s is maximised. If you don’t want to perform the operation, return an empty array. Else, return an array consisting of two elements denoting L and R. If there are multiple solutions, return the lexicographically smallest pair of L and R.
<br><br>
**Notes:** Pair (a, b) is lexicographically smaller than pair (c, d) if a < c or, if a == c and b < d.
<br><br>
**Examples:** Given **S = 010**, 
<br>
Pair of [L, R] | Final string <br>
______________|_____________ <br>
[1 1]          |      110  <br>
[1 2]          |      100  <br>
[1 3]          |      101  <br>
[2 2]          |      000  <br>
[2 3]          |      001  <br>

<br>
We see that two pairs [1, 1] and [1, 3] give same number of 1s in final string. So, we return ***[1, 1]***
<br>

Given **S = 111**
No operation can give us more than three 1s in final string. So, we return ***empty array []***
<br><br>
[Solution](https://github.com/SrGrace/InterviewBit/blob/master/Arrays/Flip.cpp)
<br>
<br>
<br>

####[Largest number](https://www.interviewbit.com/problems/largest-number/)
Given a list of non negative integers, arrange them such that they form the largest number.
<br><br>
**Example:** Given **[3, 30, 34, 5, 9]**, the largest formed number is ***9534330***.
<br><br>
**Note:** The result may be very large, so you need to return a string instead of an integer.
<br><br>
[Solution](https://github.com/SrGrace/InterviewBit/blob/master/Arrays/LargestNumber.cpp)
<br>
<br>
<br>

####[Max sum contiguous subarray](https://www.interviewbit.com/problems/max-sum-contiguous-subarray/)
Find the contiguous subarray within an array (containing at least one number) which has the largest sum.
<br><br>
**Example:** For **[-2,1,-3,4,-1,2,1,-5,4]**, the contiguous subarray **[4,-1,2,1]** has the largest sum, which is ***6***.
<br><br>
For this problem, return the maximum sum.
<br><br>
[Solution](https://github.com/SrGrace/InterviewBit/blob/master/Arrays/MaxSumContiguousSubarray.cpp)
<br>
<br>
<br>

####[Merge overlapping intervals](https://www.interviewbit.com/problems/merge-overlapping-intervals/)
Given a collection of intervals, merge all overlapping intervals.
<br><br>
**Example:** Given **[1,3], [2,6], [8,10], [15,18]**, return ***[1,6] [8,10] [15,18]***.
<br><br>
**Note:** Make sure the returned intervals are sorted.
<br><br>
[Solution](https://github.com/SrGrace/InterviewBit/blob/master/Arrays/MergeOverlappingIntervals.cpp)
<br>
<br>
<br>

####[Min steps in infinite grid](https://www.interviewbit.com/problems/min-steps-in-infinite-grid/)
You are in an infinite 2D grid where you can move in any of the 8 directions :
<br>
 (x,y) to <br>
    (x+1, y), <br>
    (x - 1, y), <br>
    (x, y+1), <br>
    (x, y-1), <br>
    (x-1, y-1), <br>
    (x+1,y+1), <br>
    (x-1,y+1), <br>
    (x+1,y-1) <br><br>
You are given a sequence of points and the order in which you need to cover the points. Give the minimum number of steps in which you can achieve it. You start from the first point.
<br><br>
**Example:** For **[(0, 0), (1, 1), (1, 2)]**, return ***2***.
<br>
It takes 1 step to move from (0, 0) to (1, 1). It takes one more step to move from (1, 1) to (1, 2).
<br><br>
[Solution](https://github.com/SrGrace/InterviewBit/blob/master/Arrays/MinStepsInInfiniteGrid.cpp)
<br>
<br>
<br>

####[Repeat and missing number array](https://www.interviewbit.com/problems/repeat-and-missing-number-array/)
You are given a read only array of n integers from 1 to n.
Each integer appears exactly once except A which appears twice and B which is missing. Return A and B.
<br><br>
**Note:** Your algorithm should have a linear runtime complexity. Could you implement it without using extra memory?
<br>
**Note 2:** that in your output A should precede B.
<br><br>
**Example:** For ***[3, 1, 2, 5, 3]*** return ***[3, 4]***
<br><br>
[Solution](https://github.com/SrGrace/InterviewBit/blob/master/Arrays/RepeatAndMissingNumberArray.cpp)
<br>
<br>
<br>

####[Set matrix zeros](https://www.interviewbit.com/problems/set-matrix-zeros/)
Given an m x n matrix of 0s and 1s, if an element is 0, set its entire row and column to 0. Do it in place.
<br><br>
**Example:** For a given array A as **[ [1, 0 ,1], [1, 1, 1], [1, 1, 1,] ]**, on returning, the array A should be ***[ [0, 0 ,0], [1, 0, 1], [1, 0, 1] ]***
<br><br>
**Note:** Try to minimize the space and time complexity.
<br><br>
[Solution](https://github.com/SrGrace/InterviewBit/blob/master/Arrays/SetMatrixZeros.cpp)
<br>
<br>
<br>

### Math
---

### Heaps And Maps
- - -

### BackTracking
- - -

### Binary Search 
- - -

### Bit Manipulation
- - -

### Hashing
---

### Linked List
---

### Stacks and Queues
---

### Strings
---

### Two Pointers
---


<br>
<br>
<br>
<br>
<br>
<br>
<br>
<br>
<br>


### Jekyll Themes

Your Pages site will use the layout and styles from the Jekyll theme you have selected in your [repository settings](https://github.com/SrGrace/InterviewBit/settings). The name of this theme is saved in the Jekyll `_config.yml` configuration file.

### Support or Contact

Having trouble with Pages? Check out our [documentation](https://help.github.com/categories/github-pages-basics/) or [contact support](https://github.com/contact) and we’ll help you sort it out.
