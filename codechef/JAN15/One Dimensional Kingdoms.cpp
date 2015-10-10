#include<bits/stdc++.h>
#define pii pair<int,int>
#define F first
#define S second
#define MKP(x,y) make_pair(x,y)
using namespace std;

bool cmp(const pii &a,const pii &b)
{
    if(a.F!=b.F) return a.F<b.F ;
    else return a.S>b.S ;
}

pii a[100010],b[100010] ;
main()
{
    int T ; scanf("%d",&T) ;
    while(T--)
    {
        int n ; scanf("%d",&n) ;
        for(int i=0;i<n;i++) scanf("%d%d",&a[i].F,&a[i].S) ;
        sort(a,a+n,cmp) ;
        int num=0 ;
        for(int i=0;i<n;i++)
        {
            while(num && b[num-1].S >= a[i].S) num-- ;
            b[num++]=a[i] ;
        }
        n=num ;
        int now=-1,ans=0 ;
        for(int i=0;i<n;i++)
        {
            if(now>=b[i].F) continue ;
            now=b[i].S ; ans++ ;
        }
        printf("%d\n",ans) ;
    }
}
