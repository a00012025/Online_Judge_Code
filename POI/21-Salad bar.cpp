#include<bits/stdc++.h>
using namespace std;
const int maxn=1000000+10 ;

int a[maxn] ;
char c[maxn] ;
int dn[maxn],up[maxn] ;
stack<int> st1,st2 ;
main()
{
    int n ; scanf("%d%s",&n,c+1) ;
    for(int i=1;i<=n;i++) a[i]=a[i-1]+ (c[i]=='p'?1:-1) ;
    for(int i=n;i>=0;i--)
    {
        dn[i]=up[i]=n+1 ;
        while(!st1.empty() && a[st1.top()]<a[i]) st1.pop() ;
        if(!st1.empty()) up[i]=st1.top() ;
        while(!st2.empty() && a[st2.top()]>=a[i]) st2.pop() ;
        if(!st2.empty()) dn[i]=st2.top() ;
        st1.push(i) ;
        st2.push(i) ;
    }

    int ans=0 ;
    for(int i=0;i<=n;)
    {
        int j=i ;
        while(up[j]!=n+1 && up[j]<=dn[i]) j=up[j] ;
        ans=max(ans,j-i) ;
        i=j+1 ;
    }
    printf("%d\n",ans) ;
}
