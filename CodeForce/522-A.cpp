#include<bits/stdc++.h>
using namespace std;
const int maxn=200+10 ;

map<string,int> mp ;
int cnt=0 ;
int id(string &s)
{
    for(auto &i : s) if(i>='A' && i<='Z')
        i=i-'A'+'a' ;
    auto it=mp.find(s) ;
    if(it==mp.end()) return mp[s]=++cnt ;
    else return it->second ;
}

vector<int> v[maxn] ;
int d[maxn] ;
int dp(int x)
{
    if(d[x]!=-1) return d[x] ;
    d[x]=1 ;
    for(auto i : v[x]) d[x]=max(d[x],dp(i)+1) ;
    return d[x] ;
}

main()
{
    string s,t,u ;
    s="polycarp" ; id(s) ;
    int n ; scanf("%d",&n) ;
    while(n--)
    {
        cin >> s >> t >> u ;
        v[id(u)].push_back(id(s)) ;
    }
    memset(d,-1,sizeof(d)) ;
    printf("%d\n",dp(1)) ;
}
