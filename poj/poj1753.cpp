#include <iostream>
#include <queue>
#include <cstring>
using namespace std;

int flip( int cur, int i, int j ){
    cur = cur^( 1<<(i*4+j) );
    if( i-1 >= 0 ) cur = cur^(1<<(4*(i-1)+j));
    if( i+1 < 4 ) cur = cur^(1<<(4*(i+1)+j));
    if( j-1 >= 0 ) cur = cur^(1<<(4*i+j-1));
    if( j+1 <4 ) cur = cur = cur^(1<<(4*i+j+1));
    return cur;
}

int bfs( int from ){
    int result[65536];
    int vis[65536];
    queue<int> Q;
    memset( result, 0x0, sizeof(int)*65536 );
    memset( vis, 0x0, sizeof(int)*65536 );
    Q.push( from );
    vis[from] = 1;
    while( !Q.empty() ){
        int cur = Q.front();
        Q.pop();
        if( cur==0 || cur==65535 ){
            return result[cur];
        }
        for( int i = 0; i != 4; ++i ){
            for( int j = 0; j != 4; ++j ){
                int state = flip( cur, i, j );
                if( vis[state]==0 ){
                    Q.push( state );
                    vis[state] = 1;
                    result[state] = result[cur] + 1;
                }
            }
        }
    }
    return -1;
}

int main()
{
    int from = 0;
    for( int i = 0; i != 4; ++i ){
        for( int j = 0; j != 4; ++j ){
            char c;
            cin>>c;
            from =  from + ((c=='w')?0:1)*( 1<<(i*4+j) );
        }
    }
    int result = bfs( from );
    if( result==-1 ){
        cout<<"Impossible"<<endl;
    }else{
        cout<<result<<endl;
    }
    return 0;
}
