#include<bits/stdc++.h>
#define MKP(x,y) make_pair(x,y)
using namespace std;

map<pair<int,int>,int> mp ;
int cnt=0 ;
int ID(const pair<int,int>&p)
{
    if(!mp.count(p)) mp[p]=++cnt ;
    return mp[p] ;
}

char s[1000000] ;
vector<int> v[400000] ;
main()
{
    int n ; scanf("%d%s",&n,s) ;
    int a,b,c ; a=b=c=0 ;
    v[ID(MKP(0,0))].push_back(-1) ;
    for(int i=0;i<n;i++)
    {
        if(s[i]=='1') a++ ;
        if(s[i]=='2') b++ ;
        if(s[i]=='3') c++ ;
        v[ID(MKP(c-b,b-a))].push_back(i) ;
    }
    int ans=0 ;
    for(int i=1;i<=cnt;i++) if(v[i].size()>=2)
        ans=max(ans,v[i][v[i].size()-1]-v[i][0]) ;
    printf("%d\n",ans) ;
}
