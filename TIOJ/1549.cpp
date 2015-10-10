#include<bits/stdc++.h>
#define LL long long
using namespace std;
const int maxn=2000000+10 ;

int a[maxn],inv[maxn] ;
int fa[maxn],ans[maxn] ;
stack<int> st ;
vector<int> v ;

main()
{
    int n ; scanf("%d",&n) ;
    for(int i=1;i<=n;i++) scanf("%d",&a[i]) , v.push_back(a[i]) ;
    sort(v.begin(),v.end()) ;
    for(int i=1;i<=n;i++)
        a[i]=upper_bound(v.begin(),v.end(),a[i])-v.begin() ;

    fa[a[1]]=0 ; st.push(a[1]) ;
    for(int i=2;i<=n;i++)
    {
        if(a[i]>st.top())
        {
            fa[a[i]]=st.top() ;
            st.push(a[i]) ;
            continue ;
        }
        int x ;
        while(!st.empty() && st.top()>a[i])
            x=st.top() , st.pop() ;
        fa[a[i]]= st.empty() ? 0 : st.top() ;
        fa[x]=a[i] ;
        st.push(a[i]) ;
    }

    LL ans=0LL ;
    for(int i=1;i<=n;i++) if(fa[i]!=0)
        ans+= ((LL)v[i-1]-v[fa[i]-1])*((LL)v[i-1]-v[fa[i]-1]) ;
    printf("%lld\n",ans) ;
}

