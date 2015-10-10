#include<bits/stdc++.h>
#define LL long long
#define INF 2000000000
using namespace std;
const int maxn=100000+10 ;

int a[maxn] ;
LL s[maxn],t[maxn],ans1 ;

void mer(int l,int r)
{
    if(l==r) return ;
    int mid=(l+r)/2 ;
    mer(l,mid) ;
    mer(mid+1,r) ;
    for(int i=l,j=mid+1,cnt=l;i<=mid||j<=r;)
    {
        if(j==r+1||(i!=mid+1 && s[i]<=s[j]))
            t[cnt++]=s[i++] ;
        else t[cnt++]=s[j++] , ans1+=mid-i+1 ;
    }
    for(int i=l;i<=r;i++) s[i]=t[i] ;
}

main()
{
    int n ;
    while(scanf("%d",&n)==1 && n)
    {
        LL mi=0LL,ans2=0LL ;
        s[0]=0LL ;
        for(int i=1;i<=n;i++)
        {
            char c[5] ; scanf("%s%d",c,&a[i]) ;
            if(c[0]=='w') a[i]=-a[i] ;
            s[i]=s[i-1]+a[i] ;
            ans2=max(ans2,s[i]-mi) ;
            mi=min(mi,s[i]) ;
        }
        for(int i=0;i<n-i;i++) swap(s[i],s[n-i]) ;
        ans1=0LL ;
        mer(0,n) ;
        printf("%lld %lld\n",ans1,ans2) ;
    }
}
