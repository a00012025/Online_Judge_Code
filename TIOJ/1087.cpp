#include<bits/stdc++.h>
#include"lib1087.h"
using namespace std;

int win[11][16][21] ;

bool dfs(int x,int y,int z)
{
    if(win[x][y][z]!=-1) return win[x][y][z] ;
    if(!x && !y && !z) return 1 ;
    int &ans=win[x][y][z] ; ans=0 ;
    for(int i=0;i<x;i++) if(!dfs(i,y,z)) return ans=1 ;
    for(int i=0;i<y;i++) if(!dfs(x,i,z)) return ans=1 ;
    for(int i=0;i<z;i++) if(!dfs(x,y,i)) return ans=1 ;
    return ans=0 ;
}

main()
{
    Initialize() ;
    memset(win,-1,sizeof(win)) ;
    int a[4] ;
    dfs(a[1]=10,a[2]=15,a[3]=20) ;
    while(1)
    {
        bool ok=0 ;
        int t[4] ; for(int i=1;i<=3;i++) t[i]=a[i] ;
        int p,num ;
        for(int i=1;!ok && i<=3;i++)
            for(int j=0;!ok && j<a[i];j++)
        {
            t[i]=j ;
            if(win[t[1]][t[2]][t[3]]) { t[i]=a[i] ; continue ; }
            Take_Stone(i,a[i]-j,&p,&num) ;
            a[i]=j ;
            a[p]-=num ;
            ok=1 ;
        }
    }
}
