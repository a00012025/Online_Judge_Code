#include<bits/stdc++.h>
#define LL long long
#define pii pair<int,int>
#define F first
#define S second
using namespace std;
const int maxn=300000+10 ;

pii a[maxn] ;
main()
{
    int n ; scanf("%d",&n) ;
    LL t1=0 , t2=0 ;
    for(int i=0;i<n;i++)
    {
        scanf("%d%d",&a[i].F,&a[i].S) ;
        if(a[i].S%2) a[i].S=-1 , t2++ ;
        else a[i].S=1 , t1++ ;
    }
    sort(a,a+n) ;
    LL ans=0LL ;
    for(int i=0,n1=0,n2=0;i<n;)
    {
        int j=i , nn1=n1 , nn2=n2 ;
        for(;j<n && a[j].F==a[i].F;j++)
        {
            if(a[j].S==1) nn1++ ;
            else nn2++ ;
        }
        for(int k=i;k<j;k++)
        {
            if(a[k].S==1) ans+=n1+(t2-nn2) ;
            else ans+=n2+(t1-nn1) ;
        }
        n1=nn1 ; n2=nn2 ; i=j ;
    }
    printf("%lld\n",ans) ;
}
