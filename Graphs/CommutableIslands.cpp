/*

https://www.interviewbit.com/problems/commutable-islands/


There are n islands and there are many bridges connecting them. Each bridge has some cost attached to it.

We need to find bridges with minimal cost such that all islands are connected.

It is guaranteed that input data will contain at least one possible scenario in which all islands are connected with each 
other.

Example :
Input

         Number of islands ( n ) = 4
         1 2 1 
         2 3 4
         1 4 3
         4 3 2
         1 3 10
         
In this example, we have number of islands(n) = 4 . Each row then represents a bridge configuration. In each row first two 
numbers represent the islands number which are connected by this bridge and the third integer is the cost associated with 
this bridge.

In the above example, we can select bridges 1(connecting islands 1 and 2 with cost 1), 3(connecting islands 1 and 4 with 
cost 3), 4(connecting islands 4 and 3 with cost 2). Thus we will have all islands connected with the minimum possible 
cost(1+3+2 = 6). In any other case, cost incurred will be more.

*/



#define N 100005

int n, m, p[N], rank11[N];
vector<pair<int, pair<int, int> > > v;

void create_set() 
{
    for(int i = 1; i <= n; i++) 
    {
        p[i] = i;
        rank11[i] = 0;
    }
}

int find_set(int u) 
{
    int x = p[u];
    if(x != u)
        x = find_set(x);
        
    return x;
}

void merge_set(int u, int v)
{
    int s1 = find_set(u);
    int s2 = find_set(v);
    
    if(rank11[s1] > rank11[s2])
        p[s2] = s1;
    else 
        p[s1] = s2;
        
    if(rank11[s1] == rank11[s2])
        rank11[s2] += 1;
}
int kruskal() 
{
    create_set();
    int res = 0;
    for(int  i = 0; i < v.size(); i++) 
    {
        int v1 = v[i].second.first;
        int v2 = v[i].second.second;
        
        if(find_set(v1) != find_set(v2)) 
        {
            res += v[i].first;
            merge_set(v1,v2);
        }
    }
    return res;
}

int Solution::solve(int A, vector<vector<int> > &B) 
{
    n = A;
    m = (int)B.size();
    v.clear();
    for (int i = 0; i < m; i++) 
    {
      int x,y, cost;
      x = B[i][0];
      y = B[i][1];
      cost = B[i][2];
      v.push_back(make_pair(cost,make_pair(x,y)));
    }

    sort(v.begin(),v.end());
    return kruskal();
	
}






