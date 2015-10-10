#include<bits/stdc++.h>
#define LL long long
using namespace std;
const int maxn=100000+10 ;

int a[maxn],l[maxn],r[maxn] ;
LL sum[maxn] ;
stack<int> st ;

LL ans ;
int ansl,ansr ;

bool better(LL val,int L,int R)
{
    if(ans!=val) return val>ans ;
    if(L!=ansl) return L<ansl ;
    return R<ansr ;
}

main()
{
    int n ;
    while(scanf("%d",&n)!=EOF)
    {
        for(int i=1;i<=n;i++)
            scanf("%d",&a[i]) , sum[i]=sum[i-1]+a[i] ,
            l[i]=1 , r[i]=n ;

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

        ans=-1 ;
        for(int i=1;i<=n;i++)
        {
            if(better( a[i]*(sum[r[i]]-sum[l[i]-1]) , l[i],r[i] ))
                ans=a[i]*(sum[r[i]]-sum[l[i]-1]) ,
                ansl=l[i] , ansr=r[i] ;
        }
        printf("%lld\n%d %d\n",ans,ansl,ansr) ;
    }
}
