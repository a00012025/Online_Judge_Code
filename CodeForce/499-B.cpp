#include<bits/stdc++.h>
using namespace std;

map<string,string> mp ;
main()
{
    int n,m ; scanf("%d%d",&n,&m) ;
    while(m--)
    {
        string s,t ; cin >> s >> t ;
        if(t.size()<s.size()) mp[s]=t , mp[t]=t ;
        else mp[s]=s , mp[t]=s ;
    }
    while(n--)
    {
        string s ; cin >> s ;
        cout << mp[s] ;
        printf("%c",n ? ' ' : '\n') ;
    }
}
