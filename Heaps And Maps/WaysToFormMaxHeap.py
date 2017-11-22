"""

https://www.interviewbit.com/problems/ways-to-form-max-heap/



Max Heap is a special kind of complete binary tree in which for every node the value present in that node is greater than 
the value present in it’s children nodes. If you want to know more about Heaps, please visit this link

So now the problem statement for this question is:

How many distinct Max Heap can be made from n distinct integers

In short, you have to ensure the following properties for the max heap :

    Heap has to be a complete binary tree ( A complete binary tree is a binary tree in which every level, except possibly 
    the last, is completely filled, and all nodes are as far left as possible. )
    Every node is greater than all its children

Let us take an example of 4 distinct integers. Without loss of generality let us take 1 2 3 4 as our 4 distinct integers

Following are the possible max heaps from these 4 numbers :

         4 
       /  \ 
      3   2 
     / 
    1

         4 
       /  \ 
      2   3 
     / 
    1

        4 
       /  \ 
      3   1 
     / 
    2

These are the only possible 3 distinct max heaps possible for 4 distinct elements.

Implement the below function to return the number of distinct Max Heaps that is possible from n distinct elements.

As the final answer can be very large output your answer modulo 1000000007

Input Constraints : n <= 100

    NOTE: Note that even though constraints are mentioned for this problem, for most problems on InterviewBit, constraints 
    are intentionally left out. In real interviews, the interviewer might not disclose constraints and ask you to do the best 
    you can do. 

"""


# Approach

"""


    Suppose there are n distinct elements to be used in Max heap. Now it is for sure that the maximum element among this n 
    distinct element will surely be placed on the root of the heap.

    Now there will be remaining (n-1) elements to be arranged.

    Now point to be remembered here is that the structure of the heap will remain the same. That is only the values within the 
    node will change however the overall structure remaining the same.

    As structure of the heap remains the same, the number of elements that are present in the left sub-tree of the root (L) 
    will be fixed. And similarly the number of the elements on the right sub-tree (R) of the root. And also following equality 
    holds .

    L + R = (n-1) 

    Now as all the remaining (n-1) elements are less than the element present at the root(The Max Element), whichever L 
    elements among ‘n-1` elements we put in the left sub-tree, it doesn’t matter because it will satisfy the Max Heap 
    property.

    So now there are (n-1)CL ways to pickup L elements from (n-1) elements. And then recurse the solution.

    So final equation will be as follows :

    (n-1)CL * getNumberOfMaxHeaps(L) * getNumberOfMaxHeaps(R) 

    So now the question remains only of finding L for given n. It can be found as follows:

    Find the height of the heap h = log2(n)

    Find the max number of elements that can be present in the hth level of any heap . Lets call it m. m = 2h

    Find the number of elements that are actually present in last level(hth level) in heap of size n. Lets call it p. 
    p = n - (2h - 1)

    Now if the last level of the heap is more than or equal to exactly half filled, then L would be 2h - 1

    However if it is half filled then it will reduced by the number of elements in last level left to fill exactly half of the 
    last level.

    So final equation for L will be as follows :

       = 2h - 1 if p >= m/2
    L= 
       = 2h - 1 - (m/2 - p) if p<(m/2) 


"""



MOD = 10**9+7

class Solution:
    # @param A : integer
    # @return an integer
    
    def comb(self,r,n) :
        if 2*r > n : 
            return self.comb(n-r,n)
        c = 1
        for i in range(r) :
            c = c*(n-i)//(i+1)
        return c
    
    def solve(self, A):
        ans,h = [1,1], 0
        for n in range(2,A+1) :
            if 2<<h <= n :
                h += 1
            m = n-(1<<h)+1
            l = (1<<(h-1))-1 + min(m,1<<(h-1))
            r = (1<<(h-1))-1 + max(0,m-(1<<(h-1)))
            ans.append((self.comb(l,n-1)*ans[l]*ans[r])%MOD)
        return ans[A]

            
    

