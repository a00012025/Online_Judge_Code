#include<bits/stdc++.h>
#define LL long long
using namespace std;
const int maxn=200000+10 ;
vector<int> v[maxn] ;
set<int> st ;
main()
{
    int n,k,p ; scanf("%d%d%d",&n,&k,&p) ;
    for(int i=1;i<=n;i++)
    {
        int x,y ; scanf("%d%d",&x,&y) ;
        v[x].push_back(i) ;
        if(y<=p) st.insert(i) ;
    }
    LL ans=0LL ;
    for(int i=0;i<k;i++) if(!v[i].empty())
    {
        for(int j=0;j<v[i].size();j++)
        {
            set<int>::iterator it=st.lower_bound(v[i][j]) ;
            if(it==st.end()) continue ;
            int id=lower_bound(v[i].begin(),v[i].end(),*it)-v[i].begin() ;
            if(id!=v[i].size() && v[i][id]==v[i][j]) id++ ;
            ans+= v[i].size()-id ;
        }
    }
    printf("%lld\n",ans) ;
}
