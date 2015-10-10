#include<bits/stdc++.h>
using namespace std;

stack<int> st ;
main()
{
    int n ; scanf("%d",&n) ;
    int ans=0 ;
    for(int i=1;i<=n;i++)
    {
        int x,y ; scanf("%d%d",&x,&y) ;
        while(!st.empty() && st.top()>y) ans++ , st.pop() ;
        if(st.empty() || st.top()!=y) st.push(y) ;
    }
    printf("%d\n",ans+st.size()) ;
}
