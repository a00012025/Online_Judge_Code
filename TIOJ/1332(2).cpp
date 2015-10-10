#include<bits/stdc++.h>
using namespace std;
const int maxn=1000000+10 ;

int a[maxn],inv[maxn] ;
int fa[maxn],ans[maxn] ;
stack<int> st ;

main()
{
    int n ; scanf("%d",&n) ;
    for(int i=1;i<=n;i++) scanf("%d",&a[i]) , inv[a[i]]=i ;

    fa[inv[1]]=0 ; st.push(inv[1]) ;
    for(int i=2;i<=n;i++)
    {
        if(inv[i]>st.top())
        {
            fa[inv[i]]=st.top() ;
            st.push(inv[i]) ;
            continue ;
        }
        int x ;
        while(!st.empty() && st.top()>inv[i])
            x=st.top() , st.pop() ;
        fa[inv[i]]= st.empty() ? 0 : st.top() ;
        fa[x]=inv[i] ;
        st.push(inv[i]) ;
    }
    for(int i=1;i<=n;i++) ans[a[i]]=a[fa[i]] ;
    for(int i=1;i<=n;i++) printf("%d\n",ans[i]) ;
}
