/*

https://www.interviewbit.com/problems/allocate-books/


N number of books are given.
The ith book has Pi number of pages.
You have to allocate books to M number of students so that maximum number of pages alloted to a student is minimum. A book will be 
allocated to exactly one student. Each student has to be allocated at least one book. Allotment should be in contiguous order, 

for example: A student cannot be allocated book 1 and book 3, skipping book 2.

NOTE: Return -1 if a valid assignment is not possible

Input:

List of Books
M number of students

Your function should return an integer corresponding to the minimum number.

Example:

P : [12, 34, 67, 90]
M : 2

Output : 113

There are 2 number of students. Books can be distributed in following fashion : 
  1) [12] and [34, 67, 90]
      Max number of pages is allocated to student 2 with 34 + 67 + 90 = 191 pages
  2) [12, 34] and [67, 90]
      Max number of pages is allocated to student 2 with 67 + 90 = 157 pages 
  3) [12, 34, 67] and [90]
      Max number of pages is allocated to student 1 with 12 + 34 + 67 = 113 pages

Of the 3 cases, Option 3 has the minimum pages = 113. 

*/


//# Solution Approach: Same as Painter's Partition Problem 



int getMax(vector<int> &A)
{
    int max = INT_MIN;
    for(auto i=0; i<A.size(); i++)
        if(A[i] > max)
            max = A[i];
    
    return max;
}
int getSum(vector<int> &A)
{
    int sum = 0;
    for(auto i=0; i<A.size(); i++)
        sum += A[i];
    
    return sum;
}
int getReqStuds(vector<int> &A, int maxPagePerStud)
{
    int tot = 0; int numStuds = 1;
    for(auto i=0; i<A.size(); i++)
    {
        tot += A[i];
        if(tot > maxPagePerStud)
        {
            tot = A[i];
            numStuds++;
        }
    }
    
    return numStuds;
}

int Solution::books(vector<int> &A, int B) 
{
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details

    if(A.size() < B) return -1;
    
    int l = getMax(A); // O(n)
    int h = getSum(A); // O(n)
    
    while(l < h) // O(logn)
    {
        int mid = l + (h - l)/2;
        int reqStuds = getReqStuds(A, mid);
        if(reqStuds <= B)
            h = mid;
        else
            l = mid + 1;
    }
    
    return l; // O(n + logn), O(1)
}




