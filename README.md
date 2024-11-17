# SrGrace's InterviewBit-Wiki

Collection of solution for problems on [InterviewBit](https://www.interviewbit.com)

[![Open Source Love](https://badges.frapsoft.com/os/v2/open-source.svg?v=103)](https://github.com/ellerbrock/open-source-badges/)
![InterviewBit](https://img.shields.io/badge/InterviewBit-purple)
![GitHub Forks](https://img.shields.io/github/forks/SrGrace/InterviewBit?style=social)
![GitHub Stars](https://img.shields.io/github/stars/SrGrace/InterviewBit?style=social)
![GitHub Contributors](https://img.shields.io/github/contributors/SrGrace/InterviewBit?style=social)

### Contents

* [Arrays](#arrays)  
* [Math](#math)
* [Binary Search](#binary-search)
* [Strings](#strings)
* [Bit Manipulation](#bit-manipulation)
* [Two Pointers](#two-pointers)
* [Linked List](#linked-list)
* [Stacks And Queues](#stacks-and-queues)
* [BackTracking](#backtracking)
* [Hashing](#hashing)
* [Heaps And Maps](#heaps-and-maps)
* [Trees](#trees)
* [Dynamic Programming](#dynamic-programming)
* [Greedy](#greedy)
* [Graphs](#graphs)


### Arrays
---

####[Add one to number](https://www.interviewbit.com/problems/add-one-to-number/)
<br>
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
<br>
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
<br>
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

####[flip](https://www.interviewbit.com/problems/flip/)
<br>
You are given a binary string(i.e. with characters 0 and 1) S consisting of characters S1, S2, …, SN. In a single operation, you can choose two indices L and R such that 1 ≤ L ≤ R ≤ N and flip the characters SL, SL+1, …, SR. By flipping, we mean change character 0 to 1 and vice-versa.
<br>
Your aim is to perform ATMOST one operation such that in final string number of 1s is maximised. If you don’t want to perform the operation, return an empty array. Else, return an array consisting of two elements denoting L and R. If there are multiple solutions, return the lexicographically smallest pair of L and R.
<br><br>
**Notes:** Pair (a, b) is lexicographically smaller than pair (c, d) if a < c or, if a == c and b < d.
<br><br>
**Example:** Given **S = 010**, 

|Pair of [L, R] | Final string |
|---------------|--------------|
|[1 1]          |      110     |
|[1 2]          |      100     |
|[1 3]          |      101     |
|[2 2]          |      000     |
|[2 3]          |      001     |

<br>

We see that two pairs [1, 1] and [1, 3] give same number of 1s in final string. So, we return ***[1, 1]***.
<br><br>
**Example:** Given **S = 111**, 
<br>
No operation can give us more than three 1s in final string. So, we return ***empty array []***.
<br><br>
[Solution](https://github.com/SrGrace/InterviewBit/blob/master/Arrays/Flip.cpp)
<br>
<br>
<br>

####[Largest number](https://www.interviewbit.com/problems/largest-number/)
<br>
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
<br>
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
<br>
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
<br>
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
<br>
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
<br>
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

####[Rearrange Array](https://www.interviewbit.com/problems/rearrange-array/)
<br>
Rearrange a given array so that Arr[i] becomes Arr[Arr[i]] with O(1) extra space.
<br><br>
**Example:** For a given array Arr as **[1, 0]**, on returning, the array Arr should be ***[0, 1]***
<br><br>
**Note:**  Lets say N = size of the array. Then, following holds true :
* All elements in the array are in the range [0, N-1]
* N * N does not overflow for a signed integer
<br>

[Solution](https://github.com/SrGrace/InterviewBit/blob/master/Math/RearrangeArray.cpp)
<br>
<br>
<br>

####[Excel Column Title](https://www.interviewbit.com/problems/excel-column-title/)
<br>
Given a positive integer, return its corresponding column title as appear in an Excel sheet.
<br><br>
**Example:** <br>
1 -> A <br>
2 -> B <br>
3 -> C <br>
...   <br>
26 -> Z <br>
27 -> AA <br>
28 -> AB  
<br>
[Solution](https://github.com/SrGrace/InterviewBit/blob/master/Math/ExcelColumnTitle.cpp)
<br>
<br>
<br>

####[Excel Column Number](https://www.interviewbit.com/problems/excel-column-number/)
<br>
Given a column title as appears in an Excel sheet, return its corresponding column number.
<br><br>
**Example:** <br>
A -> 1 <br>
B -> 2 <br>
C -> 3 <br>
...  <br>
Z -> 26  <br>
AA -> 27  <br>
AB -> 28   
<br>
[Solution](https://github.com/SrGrace/InterviewBit/blob/master/Math/ExcelColumnNumber.cpp)
<br>
<br>
<br>

####[FizzBuzz](https://www.interviewbit.com/problems/fizzbuzz/)
<br>
Given a positive integer N, print all the integers from 1 to N. But for multiples of 3 print “Fizz” instead of the number and for the multiples of 5 print “Buzz”. Also for number which are multiple of 3 and 5, prints “FizzBuzz”.
<br><br>
**Example:** Given **N = 5** Return: ***[1 2 Fizz 4 Buzz]***
<br><br>
**Note:**  Instead of printing the answer, you have to return it as list of strings.
<br><br>
[Solution](https://github.com/SrGrace/InterviewBit/blob/master/Math/FizzBuzz.cpp)
<br>
<br>
<br>

####[Palindrome Integer](https://www.interviewbit.com/problems/palindrome-integer/)
<br>
Determine whether an integer is a palindrome. Do this without extra space. <br>
A palindrome integer is an integer x for which reverse(x) = x where reverse(x) is x with its digit reversed.
Negative numbers are not palindromic.
<br><br>
**Example:** <br>
Input : **12121** <br>
Output : ***True*** <br><br>
Input : **123** <br>
Output : ***False*** 
<br><br>
[Solution](https://github.com/SrGrace/InterviewBit/blob/master/Math/PalindromeInteger.cpp)
<br>
<br>
<br>

####[Power Of Two Integers](https://www.interviewbit.com/problems/power-of-two-integers/)
<br>
Given a positive integer which fits in a 32 bit signed integer, find if it can be expressed as A^P where P > 1 and A > 0. <br>
A and P both should be integers.
<br><br>
**Example:** <br>
Input : **4** <br>
Output : ***True*** <br>
as 2^2 = 4. 
<br><br>
[Solution](https://github.com/SrGrace/InterviewBit/blob/master/Math/PowerOfTwoIntegers.cpp)
<br>
<br>
<br>

####[Prime Sum](https://www.interviewbit.com/problems/Prime-Sum/)
<br>
Given an even number ( greater than 2 ), return two prime numbers whose sum will be equal to given number.
<br><br>
**Example:** <br>
Input : **4** <br>
Output : ***2 + 2 = 4***
<br><br>
**Note:** If there are more than one solutions possible, return the lexicographically smaller solution.<br>
If [a, b] is one solution with a <= b, <br>
and [c,d] is another solution with c <= d, then <br>
[a, b] < [c, d] <br>
If a < c OR a==c AND b < d. 
<br><br>
[Solution](https://github.com/SrGrace/InterviewBit/blob/master/Math/PrimeSum.cpp)
<br>
<br>
<br>

####[Greatest Common Divisor](https://www.interviewbit.com/problems/greatest-common-divisor/)
<br>
Given 2 non negative integers m and n, find gcd(m, n). <br>
GCD of 2 integers m and n is defined as the greatest integer g such that g is a divisor of both m and n.
Both m and n fit in a 32 bit signed integer.
<br><br>
**Example:** <br>
Input : **m = 6, n = 9** <br>
Output : ***GCD(m, n) = 3*** 
<br><br>
**Note:** DO NOT USE LIBRARY FUNCTIONS
<br><br>
[Solution](https://github.com/SrGrace/InterviewBit/blob/master/Math/greatestCommonDivisor.cpp)
<br>
<br>
<br>


### Binary Search 
- - -

### Strings
---

### Bit Manipulation
- - -

### Two Pointers
---

### Linked List
---

### Stacks and Queues
---

### BackTracking
- - -

### Hashing
---

### Heaps And Maps
- - -

####[Merge K Sorted Lists](https://www.interviewbit.com/problems/merge-k-sorted-lists/)
<br>
Merge k sorted linked lists and return it as one sorted list.
<br><br>
**Example:** <br>
**1 -> 10 -> 20 <br>
4 -> 11 -> 13 <br>
3 -> 8 -> 9** <br>
will result in <br> ***1 -> 3 -> 4 -> 8 -> 9 -> 10 -> 11 -> 13 -> 20***
<br><br>
[Solution](https://github.com/SrGrace/InterviewBit/blob/master/Heaps%20And%20Maps/MergeKSortedLists.cpp)
<br>
<br>
<br>

### Trees
---

### Dynamic Programming
---

### Greedy
---

### Graphs
---


<br><br><br><br>

**NOTE:** PRs and Stars are always welcome :sparkles:
