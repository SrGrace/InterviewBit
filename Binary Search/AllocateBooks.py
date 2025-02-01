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
        mid = (low + high) // 2
        if is_feasible(mid):
            result = mid  # Update result to the feasible maximum
            high = mid - 1  # Try to minimize further
        else:
            low = mid + 1  # Increase the maximum
    
    return result

