#include<bits/stdc++.h>
using namespace std;
const int maxn=50000 ;

int p[maxn],pcnt=0 ;
bool vis[maxn] ;

main()
{
    for(int i=2;i*i<maxn;i++) if(!vis[i])
        for(int j=i*i;j<maxn;j+=i) vis[j]=1 ;
    for(int i=2;i<maxn;i++) if(!vis[i])
        p[++pcnt]=i ;
    int ma=0 ;
//    for(int i=1;i<=2147483646;i++)
    for(int i=61261200;i<=2147483646;i++) if(i%1001==0)
    {
        int x=i , num=1 ;
        for(int j=1;j<=pcnt && x!=1 && p[j]*p[j]<=x && (x>maxn||vis[x]);j++)
            if(x%p[j]==0)
        {
            int d=1 ;
            while(x%p[j]==0) d++ , x/=p[j] ;
            num*=d ;
        }
        if(x!=1) num*=2 ;
        if(num>ma) ma=num , printf("%d\n",i) ;
    }
}
