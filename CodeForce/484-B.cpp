#include<bits/stdc++.h>
using namespace std;
const int maxn=1000005 ;
int a[200001],n ;
bool cnt[maxn] ;

void delete_divisor()
{/*
    int newn=0 ;
    for(int i=0;i<n;i++)
    {
        bool ok=1 ;
        for(int k=2;k*a[i]<=maxn;k++) if(cnt[k*a[i]]) {ok=0 ; break ;}
        if(ok) a[newn++]=a[i] ;
    }
    n=newn ;*/
}

main()
{
    memset(cnt,0,sizeof(cnt)) ;
    scanf("%d",&n) ;
    for(int i=0;i<n;i++) scanf("%d",&a[i]) ;
    sort(a,a+n) ;
    n=unique(a,a+n)-a ;
    delete_divisor() ;
    int ans=0 ;
    for(int i=n-1;i>=0;i--)
    {
        if(a[i]<=ans) break ;
        int j=upper_bound(a,a+n,a[i]-ans)-a ; j-- ;
        for(;j>=0;j--)
        {
            if(a[j]<=ans) break ;
            ans=max(ans,a[i]%a[j]) ;
        }
    }
    printf("%d\n",ans) ;
}
