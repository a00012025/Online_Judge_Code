#include<bits/stdc++.h>
using namespace std;
const int maxn=20+10 ;

struct P
{
    int id,pos,dir;
    bool operator < (const P &rhs) const
    {
        return pos<rhs.pos ;
    }
};

int n,L ;
vector<P> v ;
void solve()
{
    v.clear() ;
    for(int i=1;i<=n;i++)
    {
        char s[3] ; int pos ; scanf("%s%d",s,&pos) ;
        v.push_back((P){i,pos,s[0]=='L' ? 0 : 1}) ;
    }
    for(int t=1;!v.empty();t++)
    {
        for(auto &i : v) i.pos+=(i.dir==0 ? -1 : 1) ;
        sort(v.begin(),v.end()) ;
        for(int i=0;i+1<v.size();i++) if(v[i].pos==v[i+1].pos)
            v[i].dir^=1 , v[i+1].dir^=1 ;

        int last=-1 ;
        while(!v.empty() && v.back().pos==L)
            last=v.back().id , v.pop_back() ;
        while(!v.empty() && v[0].pos==0)
            last=v[0].id , swap(v[0],v.back()) , v.pop_back() ;
        if(v.empty()) printf("%d %d\n",t,last) ;
    }
}

main()
{
    while(scanf("%d%d",&n,&L)==2 && n+L) solve() ;
}
