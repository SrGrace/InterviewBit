#include<iostream>
#include<vector>

using namespace std;

vector<bool> ROWS;
vector<bool> COLS;
vector<bool> DIAG;
vector<bool> ADIAG;
int N_Queen_Problem_Combination_06(int n, int m, int idx, int tnq, string ans)
{
    if(tnq==0)
    {
        cout << ans << endl;
        return 1;
    }

    int count=0;
    for(int r=idx; r<n*m; r++)
    {
        int x = r / m;
        int y = r % m;

        if(!ROWS[x] && !COLS[y] && !DIAG[x+y] && !ADIAG[x-y+(m-1)])
        {
            ROWS[x]=true; COLS[y]=true; DIAG[x+y]=true; ADIAG[x-y+(m-1)]=true;

            count += N_Queen_Problem_Combination_06(n, m, r+1, tnq-1, ans+"("+to_string(x)+","+to_string(y)+") ");
            
            ROWS[x]=false; COLS[y]=false; DIAG[x+y]=false; ADIAG[x-y+(m-1)]=false;
            
        }
    }

    return count;
}

void Questions_Set_01()
{
    int n=10;
    int m=10;
    int tnq=10;

    ROWS.resize(n, false);
    COLS.resize(m, false);
    DIAG.resize(n+m-1, false);
    ADIAG.resize(n+m-1, false);

    cout << N_Queen_Problem_Combination_06(n, m, 0, tnq, "") << endl;
}

void solve()
{
    Questions_Set_01();
}

int main()
{
    solve();
    return 0;
}
