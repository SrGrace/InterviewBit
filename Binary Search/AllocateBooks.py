"""
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

"""


def allocate_books(P, M):
    # If there are more students than books, allocation is not possible
    if len(P) < M:
        return -1
    
    def is_feasible(maxPages):
        students = 1
        current_pages = 0
        
        for pages in P:
            if current_pages + pages > maxPages:
                students += 1
                current_pages = pages
                if students > M:
                    return False
            else:
                current_pages += pages
        
        return True
    
    # Binary search space: max(P) to sum(P)
    low, high = max(P), sum(P)
    result = -1
    
    while low <= high:
        mid = low + (high - low) // 2
        if is_feasible(mid):
            result = mid  # Update result to the feasible maximum
            high = mid - 1  # Try to minimize further
        else:
            low = mid + 1  # Increase the maximum
    
    return result # O(logn)

