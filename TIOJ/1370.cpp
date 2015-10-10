#include<bits/stdc++.h>
#define LL long long
using namespace std;
const int maxn=100000+10 ;

LL a[maxn],sum[maxn] ;
int l[maxn],r[maxn] ;
stack<int> st ;

main()
{
    int n ; scanf("%d",&n) ;
    LL nowh=0LL ;
    for(int i=1;i<=n;i++)
    {
        LL x,y ; scanf("%lld%lld",&x,&y) ;
        nowh+=x ;
        a[i]=nowh ; sum[i]=sum[i-1]+y ;
        l[i]=1 , r[i]=n ;
    }

    while(!st.empty()) st.pop() ;
    for(int i=1;i<=n;i++)
    {
        while(!st.empty() && a[st.top()]>=a[i])
            st.pop() ;
        if(!st.empty()) l[i]=st.top()+1 ;
        st.push(i) ;
    }

    while(!st.empty()) st.pop() ;
    for(int i=n;i>=1;i--)
    {
        while(!st.empty() && a[st.top()]>=a[i])
            st.pop() ;
        if(!st.empty()) r[i]=st.top()-1 ;
        st.push(i) ;
    }

    LL ans=-1 ;
    for(int i=1;i<=n;i++)
        ans=max(ans,a[i]*(sum[r[i]]-sum[l[i]-1])) ;
    printf("%lld\n",ans);
}
