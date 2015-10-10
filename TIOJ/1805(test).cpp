#include<bits/stdc++.h>
using namespace std;

main()
{
    int T=100 ; printf("%d\n",T) ;
    while(T--)
    {
        int n=30 ;
        printf("%d\n",n) ;
        set<int> st ;
        for(int i=1;i<=n;i++)
        {
            int x=rand() ; if(st.count(x)) continue ;
            st.insert(x) ;
            printf("%d%c",x,i==n?'\n':' ') ;
        }
    }
}
