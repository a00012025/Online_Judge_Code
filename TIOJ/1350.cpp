#include<bits/stdc++.h>
using namespace std;
const int maxn=10000+10 ;

bool vis[maxn] ;
int p[maxn],pcnt=0 ;
void prime()
{
    for(int i=2;i*i<maxn;i++) if(!vis[i])
        for(int j=i*i;j<maxn;j+=i) vis[j]=1 ;
    for(int i=2;i<maxn;i++) if(!vis[i])
        p[++pcnt]=i ;
}

int num[maxn] ;
main()
{
    prime() ;
    int T ; scanf("%d",&T) ;
    while(T--)
    {
        memset(num,0,sizeof(num)) ;
        int n ; scanf("%d",&n) ;
        if(n==1) { printf("(1)\n") ; continue ; }
        for(int i=1;p[i]<=n;i++)
        {
            int t=n ;
            while(t) num[i]+=t/p[i] , t/=p[i] ;
        }

        for(int i=1;p[i]<=n;i++)
        {
            if(i!=1) printf("*") ;
            printf("(%d",p[i]) ;
            if(num[i]>1) printf("^%d",num[i]) ;
            printf(")") ;
        }
        printf("\n") ;
    }
}
