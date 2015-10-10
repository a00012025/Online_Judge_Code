#include<bits/stdc++.h>
#include"lib1542.h"
#define INF 2000000000
using namespace std;

int dfs(int dep,int type)
{
    int op,ret= type==0 ? INF : -INF ;
    while(1)
    {
        int x=Ask(op) ;
        if(op==0) return x ;
        if(op==1)
        {
            int tmp=dfs(dep+1,type^1) ;
            if(type==0) ret=min(ret,tmp) ;
            else ret=max(ret,tmp) ;
        }
        else break ;
    }
    if(dep) GoBackward() ;
    return ret ;
}

main()
{
    char s=Initialize() ;
//    assert(s==0 || s==1) ;
    Report(dfs( 0 , (s==0) ? 0 : 1 )) ;
}
