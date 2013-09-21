#include <iostream>
using namespace std;

class Solution {
public:
    static int jump(int A[], int n) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if(n==0 || n==1 )return 0;
        int step = 1;
        int maxDist = A[0];
        int i = 1;
        while( i < n )
        {
            if( maxDist >= n-1 )
            {
                break;
            }
            int maxIdx = i;
            for( int j = i; j < maxDist; ++j )
            {
                if( j+A[j] > maxIdx+A[maxIdx])
                {
                    maxIdx = j;
                }
            }
            i = maxDist + 1;
            ++step;
            if( maxIdx+A[maxIdx]>maxDist+A[maxDist])
            {
                maxDist = maxIdx + A[maxIdx];
            }else{
                maxDist = maxDist+A[maxDist];
            }
        }
        
        return step;
    }
};

int main()
{
    int N;
    int data[128];
    cin>>N;
    for( int i = 0; i != N; ++i)
        cin>>data[i];
    int result = Solution::jump( data, N );
    cout<<result<<endl;
    return 0;
}
