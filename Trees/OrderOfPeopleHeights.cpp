/*

https://www.interviewbit.com/problems/order-of-people-heights/


You are given the following :

    A positive number N
    Heights : A list of heights of N persons standing in a queue
    Infronts : A list of numbers corresponding to each person (P) that gives the number of persons who are taller than P and 
    standing in front of P

You need to return list of actual order of persons’s height

Consider that heights will be unique

Example

Input : 
Heights: 5 3 2 6 1 4
InFronts: 0 1 2 0 3 2

Output : 
actual order is: 5 3 2 1 6 4 

So, you can see that for the person with height 5, there is no one taller than him who is in front of him, and hence Infronts 
has 0 for him.

For person with height 3, there is 1 person ( Height : 5 ) in front of him who is taller than him.

You can do similar inference for other people in the list.

*/


# Solution Approach

/*

O(N^2) approach

Sort people by heights. Then iterate from shortest to tallest. In each step you need an efficient way to put the next person 
to the correct position. Notice that people we’ve already placed are not taller that the current person. And the people we 
place after are taller than the current. So we have to find a place such that the number of empty positions in the front is 
equal to the inFronts value of this person.

Lets take an example :

For example after sorting,

Height - 1, 2, 3, 4, 5, 6
Infront - 3, 2, 1, 2, 0, 0.

1st element should go in position 3. Hence final array becomes:

---1--

2nd element shall go in position 2. Hence final array becomes:

--21--

3rd element should go in position 1. Hence final array becomes:

-321--

4th element shall go in position 2. This is the position among the empty ones. Hence final array becomes:

-321-4

5th element shall go in position 0. Hence final array becomes:

5321-4

6th element should go in position 0. Hence final array becomes:

532164

*/



vector<int> Solution::order(vector<int> &heights, vector<int> &infronts) 
{
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details

    vector<int> v(heights.size(), -1);
    map<int, int> mp;
    
    for(auto i=0; i<heights.size(); i++)
    {
        mp[heights[i]] = infronts[i];
    }
    
    for(auto it : mp)
    {
        int i = 0, j = 0;
        
        while(i != it.second)
        {
            if(v[j] == -1)
                i++;
            j++;
        }
        while(v[j] != -1)
        {
            j++;
        }
        v[j] = it.first;
    }
    
    return v;
}


