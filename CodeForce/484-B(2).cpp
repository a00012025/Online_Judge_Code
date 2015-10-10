#include<bits/stdc++.h>
using namespace std;
const int maxn=1000001 ;
int a[200001],n ;
bool cnt[maxn] ;

bool check(int x)
{
    int j=upper_bound(a,a+n,x)-a ;
    for(;j<n;j++)
    {
        if(x+a[j]>maxn) break ;
        for(int k=1;x+k*a[j]<=maxn;k++) if(cnt[x+k*a[j]]) return 1;
    }
    return 0 ;
}

main()
{
    memset(cnt,0,sizeof(cnt)) ;
    scanf("%d",&n) ;
    for(int i=0;i<n;i++) {scanf("%d",&a[i]) ; cnt[a[i]]=1 ;}
    sort(a,a+n) ;
    n=unique(a,a+n)-a ; if(n==1) {printf("0\n") ; return 0 ;}
    int i ;
    for(i=a[n-2];i>=0;i--)
    {
        if(check(i)) {printf("%d\n",i) ; break ; }
    }
}
