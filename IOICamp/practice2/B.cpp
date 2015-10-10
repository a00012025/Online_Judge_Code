#include<bits/stdc++.h>
using namespace std;
const int maxn=100000+10 ;

char s[maxn] ;
stack<char> st ;
main()
{
    int T ; scanf("%d",&T) ;
    while(T--)
    {
        while(!st.empty()) st.pop() ;
        scanf("%s",s) ;
        int n=strlen(s) ;
        for(int i=0;i<n;i++)
        {
            if(!st.empty() && st.top()==s[i]) st.pop() ;
            else st.push(s[i]) ;
        }
        if(st.empty()) printf("Yes\n") ;
        else printf("No\n") ;
    }
}
