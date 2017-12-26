

/*

Write a function to determine if it is possible to choose a subset of elements from a given array such that the sum of all 
numbers in the subset is equal to a given target.

Assume target is always a positive number.

Examples: 

group_sum({1,2,3,6,5}, 5, 2, 10) ==> true
group_sum({1,2,3,6,5}, 5, 3, 18) ==> false


Array: [Empty], Size: 0
must_have number: 3
Target Sum: 7                                                  false

Array: {1,2,3,6,5}, Size: 5
must_have number: 3
Target Sum: 7                                                   false

Array: {4,6,7,9,10,-11}, Size: 6
must_have number: 6
Target Sum: 12                                                   true

*/



bool Subset_Sum_With_Must_Hv_Number(int arr[], int sz, int must_have, int target_sum)
{
    if(target_sum == 0)
        return true;
  
    else if(sz == 0)
        return false;
  
    else 
    {
        // calculating sum by including must_have number
        if(arr[sz-1] == must_have)
            return Subset_Sum_With_Must_Hv_Numbe(arr, sz-1, must_have, target_sum - must_have);
        
        else    // calculating sum by including element at last idx
        {
            if(Subset_Sum_With_Must_Hv_Numbe(arr, sz-1, must_have, target_sum - arr[sz-1]))
                return true;
             
            else   // calculating sum by without element at last idx
                return Subset_Sum_With_Must_Hv_Numbe(arr, sz-1, must_have, target_sum)
        }
        
    }  
}



