#include<bits/stdc++.h>
using namespace std;
const int maxn=1000005 ;
int a[200001],n,last[2*maxn+1] ;
bool cnt[2*maxn+1] ;

main()
{
    memset(cnt,0,sizeof(cnt)) ;
    memset(last,-1,sizeof(last)) ;
    scanf("%d",&n) ;
    for(int i=0;i<n;i++) {scanf("%d",&a[i]) ; cnt[a[i]]=1 ;}
    sort(a,a+n) ;
    n=unique(a,a+n)-a ;
    for(int i=a[0];i<=2*maxn;i++)
    {
        if(cnt[i]) last[i+1]=i ;
        else last[i+1]=last[i] ;
    }
    int ans=0 ;
    for(int i=0;i<n;i++)
    {
        for(int k=2;k*a[i]<=2*maxn;k++) if(last[k*a[i]]!=-1)
        {
            ans=max(ans,last[k*a[i]]%a[i]) ;
        }
    }
    printf("%d\n",ans) ;
}

