#include<bits/stdc++.h>
#define LL long long
#define F first
#define S second
#define pii pair<int,int>
#define mkp(x,y) make_pair(x,y)
using namespace std;

vector<pii> tmp ;
void get_dif(const vector<LL> &v,map<LL,vector<int> > &mp)
{
    int n=v.size() ; tmp.clear() ;
    for(int i=0;i<(1<<n);i++) for(int j=i;;j=((j-1)&i))
    {
        LL sum=0LL ;
        for(int k=0;k<n;k++)
        {
            if(j&(1<<k)) sum+=v[k] ;
            else if(i&(1<<k)) sum-=v[k] ;
        }

        if(sum>=0) tmp.push_back(mkp(i,sum)) ;
        if(j==0) break ;
    }
    sort(tmp.begin(),tmp.end()) ;
    tmp.resize(unique(tmp.begin(),tmp.end())-tmp.begin()) ;
    for(auto i : tmp) mp[i.S].push_back(i.F) ;
}

vector<LL> L,R ;
map<LL,vector<int> > mp[2] ;
bool ok[1050000] ;
main()
{
    int n ; scanf("%d",&n) ;
    for(int i=0;i<n;i++)
    {
        LL x ; scanf("%I64d",&x) ;
        if(i%2) L.push_back(x) ;
        else R.push_back(x) ;
    }

    get_dif(L,mp[0]) ;
    get_dif(R,mp[1]) ;

    for(auto i : mp[0])
    {
        auto it=mp[1].find(i.F) ;
        if(it!=mp[1].end())
        {
            for(auto j : i.S) for(auto k : it->S)
                ok[j|(k<<L.size())]=1 ;
        }
    }
    printf("%d\n",count(ok+1,ok+(1<<n),1)) ;
}
