#include<bits/stdc++.h>
using namespace std;
const int maxn=200000+10 ;

int w[maxn],h[maxn] ;
main()
{
    int n ; scanf("%d",&n) ;
    int sum=0 ;
    for(int i=1;i<=n;i++)
        scanf("%d%d",&w[i],&h[i]) ,
        sum+=w[i] ;

    int m1=-1 , m2=-1 , id ;
    for(int i=1;i<=n;i++)
    {
        if(h[i]>=m1) id=i , m2=m1 , m1=h[i] ;
        else if(h[i]>=m2) m2=h[i] ;
    }
    for(int i=1;i<=n;i++)
    {
        int ans= i==id ? m2*(sum-w[i]) : m1*(sum-w[i]) ;
        printf("%d%c",ans,i==n?'\n':' ') ;
    }
}
