#include<bits/stdc++.h>
#define F first
#define S second
using namespace std;
const int maxn=500000+10 ;

int a[maxn],st[maxn],sz ;
set<int> ins ;
map<int,int> mp,mp0 ;
vector<int> ans ;
inline void init()
{
    sz=0 ; ins.clear() ;
    mp.clear() ; mp0.clear() ;
}

main()
{
    int n ; scanf("%d",&n) ;
    for(int i=1;i<=n;i++) scanf("%d",&a[i]) ;
    for(int i=1;i<=n;i++)
    {
        if(++mp0[a[i]]==4)
        {
            for(int j=0;j<4;j++) ans.push_back(a[i]) ;
            init() ; continue ;
        }
        auto it=mp.find(a[i]) ;
        if(it!=mp.end())
        {
            for(int j=0;j<2;j++)
                ans.push_back(it->S) ,
                ans.push_back(it->F) ;
            init() ; continue ;
        }
        if(!ins.count(a[i]))
            st[sz++]=a[i] , ins.insert(a[i]) ;
        else
        {
            while(st[sz-1]!=a[i])
                ins.erase(st[sz-1]) ,
                mp[st[sz-1]]=a[i] ,
                sz-- ;
        }
    }
    printf("%d\n",ans.size()) ;
    for(int i=0;i<ans.size();i++) printf("%d%c",ans[i],i+1==ans.size()?'\n':' ');
}
