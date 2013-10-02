/* Enter your code here. Read input from STDIN. Print output to STDOUT */

#include<iostream>
#include<vector>
#include<cstdlib>
using namespace std;

void dfs( vector<int> queen, int n, int step, int& result )
{
    if(step==n)
    {
        result = (result+1)%1000000007;
        return;
    }
    for( int i = 0; i != n; ++i )
    {
        bool valid = true;
        for( int j = 0; j != step; ++j )
        {
            if( i == queen[j] )
            {
                valid = false;
                break;
            }
        }
        if( abs(queen[step-1]-i)<=1 )
        {
            valid = false;
        }
        if(valid)
        {
            queen[step] = i;
            dfs(queen, n, step+1, result);
        }
    }
}

int main()
{
    vector<int> queen(20);
    int testCaseNum;
    cin>>testCaseNum;
    for( int i = 0; i != testCaseNum; ++i )
    {
        int N,k;
        cin>>N>>k;
        for( int i = 0; i != k; ++i )
        {
            int data;
            cin>>data;
            queen[i] = data;
        }
        int result = 0;
        dfs( queen, N, k, result );
        cout<<result<<endl;
    }
    return 0;
}
