#include<bits/stdc++.h>
#define pii pair<int,int>
#define F first
#define S second
#define LL long long
using namespace std;
const int maxn=200000+10 ;

pii p[maxn] ;
int a[maxn],idx[maxn],mp[maxn] ;
main()
{
    int n,Q ; scanf("%d%d",&n,&Q) ;
    for(int i=1;i<=n;i++) scanf("%d",&p[i].F) , p[i].S=i ;
    sort(p+1,p+n+1) ;
    for(int i=1;i<=n;i++) a[i]=p[i].F , idx[i]=p[i].S , mp[p[i].S]=i ;
    while(Q--)
    {
        int x,l,type=1 ; scanf("%d%d",&x,&l) ;
        if(n==1){printf("1\n") ; continue ;}
        x=mp[x] ;

        int id=upper_bound(a+1,a+n+1,a[x]+l)-a-1 ;
        l-=a[id]-a[x] ;
        x=id ; type=2 ;

        if(l>=a[n]-a[1])
        {
            int q=l/(a[n]-a[1]) ;
            if(q%2) x=1 , type=1 ;
            else x=n , type=2 ;
            l-=q*(a[n]-a[1]) ;
        }
        while(l)
        {
            if(type==1)
            {
                id=upper_bound(a+1,a+n+1,a[x]+l)-a-1 ;
                if(id==x || a[id]==a[x]+l){x=id ; break ;}
                if(a[id]-a[x]>=l/2)
                {
                    l-=(a[id]-a[x]) ;
                    x=id ; type=2 ;
                    continue ;
                }
                int tmp=a[id]-a[x] , q=l/tmp ;
                if(q%2) x=id , type=2 , l-=q*tmp ;
                else l-=q*tmp ;
            }
            else
            {
                id=lower_bound(a+1,a+n+1,a[x]-l)-a ;
                if(id==x || a[id]==a[x]-l){x=id ; break ;}
                if(a[x]-a[id]>=l/2)
                {
                    l-=(a[x]-a[id]) ;
                    x=id ; type=1 ;
                    continue ;
                }
                int tmp=(a[x]-a[id]) , q=l/tmp ;
                if(q%2) x=id , type=1 , l-=q*tmp ;
                else l-=q*tmp ;
            }
        }
        printf("%d\n",idx[x]) ;
    }
}
