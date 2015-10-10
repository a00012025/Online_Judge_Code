#include<bits/stdc++.h>
using namespace std;

set<string> st,st2 ;
string s ;
int n,m,tot ;
bool dfs(int x)
{
    if(x==tot)
    {
        st2.clear() ;
        for(int i=1;i<m;i++)
        {
            string t=s.substr(tot-m+i,m-i)+s.substr(0,i) ;
            if(st2.count(t) || st.count(t)) return 0 ;
            st2.insert(t) ;
        }
        cout << s << endl ;
        return 1 ;
    }
    for(int i=1;i<=n;i++)
    {
        s.push_back((char)i+'0') ;
        string t ;
        if(x>=m-1)
        {
            t=s.substr(x-m+1,m) ;
            if(st.count(t)){s.pop_back() ; continue ;}
            st.insert(t) ;
        }
        if(dfs(x+1)) return 1 ;
        if(x>=m-1) st.erase(t) ;
        s.pop_back() ;
    }
    return 0 ;
}

main()
{
    while(scanf("%d%d",&n,&m)!=EOF)
    {
        s.clear() ; st.clear() ;
        tot=1 ;
        for(int i=1;i<=m;i++) tot*=n ;
        dfs(0) ;
    }
}
