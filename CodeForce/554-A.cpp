#include<bits/stdc++.h>
using namespace std;

set<string> st ;
main()
{
    string s ; cin >> s ;
    int n=s.size() ;
    for(int i=0;i<=n;i++) for(int j=0;j<26;j++)
        st.insert(s.substr(0,i)+char('a'+j)+s.substr(i,n)) ;
    printf("%d\n",st.size()) ;
}
