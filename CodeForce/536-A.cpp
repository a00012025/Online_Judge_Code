#include<bits/stdc++.h>
#define LL long long
using namespace std;
const int maxn=1000000+10 ;

int A,B ;
LL sum(int x)
{
    return (LL)A*x + (LL)B*((LL)x*(x-1)/2) ;
}
LL sum(int x,int y)
{
    return sum(y)-sum(x-1) ;
}
bool check(int l,int r,int m,int t)
{
    LL s=sum(l,r) ;
    if(s>(LL)m*t) return 0 ;
    if(A+(LL)(r-1)*B > t) return 0 ;
    return 1 ;
}

main()
{
    int Q ;
    scanf("%d%d%d",&A,&B,&Q) ;
    while(Q--)
    {
        int x,t,m ; scanf("%d%d%d",&x,&t,&m) ;
        if(t<A+(LL)(x-1)*B) { printf("-1\n") ; continue ; }
        int l=x , r=(t-A)/B+3 ;
        while(r-l>1)
        {
            int mid=(r+l)/2 ;
            if(check(x,mid,m,t)) l=mid ;
            else r=mid ;
        }
        printf("%d\n",l) ;
    }
}
