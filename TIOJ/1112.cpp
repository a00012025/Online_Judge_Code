#include<bits/stdc++.h>
using namespace std;
const int maxn=100+10 ;
char G[maxn][maxn] ;
int n ;

bool check(int x,int y,int l)
{
    for(int i=0;i<l;i++)
    {
        if(G[x][y]!='N') return 0 ;
        if(i<l-1) x-- ;
    }
    for(int i=0;i<l;i++)
    {
        if(G[x][y]!='N') return 0 ;
        if(i<l-1) x++ , y++ ;
    }
    for(int i=0;i<l;i++)
    {
        if(G[x][y]!='N') return 0 ;
        if(i<l-1) x-- ;
    }
    return 1 ;
}

main()
{
    int T ; scanf("%d",&T) ;
    while(T--)
    {
        scanf("%d",&n) ;
        for(int i=0;i<n;i++) scanf("%s",G[i]) ;
        bool ok=0 ;
        for(int i=n;!ok && i>=4;i--)
        {
            for(int j=n-1;!ok && j-i+1>=0;j--)
                for(int k=0;!ok && k+i-1<n;k++)
                ok=check(j,k,i) ;
            if(ok) printf("%d\n",i-3) ;
        }
        if(!ok) printf("0\n") ;
    }
}
