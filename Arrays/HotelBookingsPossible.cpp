/*

https://www.interviewbit.com/problems/hotel-bookings-possible/


A hotel manager has to process N advance bookings of rooms for the next season. His hotel has K rooms. 
Bookings contain an arrival date and a departure date. He wants to find out whether there are enough rooms in the hotel to 
satisfy the demand. Write a program that solves this problem in time O(N log N) .

Input:

First list for arrival time of booking.
Second list for departure time of booking.
Third is K which denotes count of rooms.

Output:

A boolean which tells whether its possible to make a booking. 
Return 0/1 for C programs.
O -> No there are not enough rooms for N booking.
1 -> Yes there are enough rooms for N booking.

Example :

Input : 
        Arrivals :   [1 3 5]
        Departures : [2 6 8]
        K : 1

Return : False / 0 

At day = 5, there are 2 guests in the hotel. But I have only one room. 

*/


# 1st method


class Solution {
    public:
    
    bool hotel(vector<int> &arrive, vector<int> &depart, int K) {
        
        if(K == 0)
                return false;

        int N = arrive.size();
        
        vector<pair<int, int> > vec;
        for(int i = 0; i < N; ++i) 
        {
            vec.push_back(make_pair(arrive[i], 1));
            vec.push_back(make_pair(depart[i], 0));
        }
         
        sort(vec.begin(), vec.end());
        
        int curActive = 0;
        int maxAns = 0;
        for (int i = 0; i < vec.size(); i++)
        {
            if (vec[i].second == 1) 
            { // arrival
               curActive++;
               maxAns = max(maxAns, curActive);
            } 
            else 
            {
                curActive--;
            }
        }

        return (K >= maxAns);
    }
};



# 2nd method


bool Solution::hotel(vector<int> &arrive, vector<int> &depart, int K) 
{
    std::sort(arrive.begin(), arrive.end());
    std::sort(depart.begin(), depart.end());
    
    int room = 1, i = 1, j = 0, tmp = 1;
    
    while(i<arrive.size() && j<arrive.size())
    {
        if(arrive[i] < depart[j]) 
        {
            tmp++; 
            i++;
            room = max(room, tmp);
        }
        else
        {
            tmp--;
            j++;
        }
    }
    
    return (K >= room);
    
}


