#include<bits/stdc++.h>
#define DB double
using namespace std;

DB cal(DB x,DB y,int t)
{
    if(t==1) return x+y ;
    if(t==2) return x-y ;
    if(t==3) return x*y ;
    return fabs(y)<1e-7 ? 1e7 : x/y ;
}

bool solve(const vector<DB> &v)
{
    if(v.size()==1)
    {
        return fabs(v[0]-24)<1e-7 ;
    }
    int sz=v.size() ;
    vector<DB> v2 ;
    for(int i=0;i<sz;i++) for(int j=0;j<sz;j++) if(i!=j)
    {
        v2.clear() ;
        for(int k=0;k<sz;k++) if(k!=i && k!=j)
            v2.push_back(v[k]) ;
        for(int k=1;k<=4;k++)
        {
            v2.push_back(cal(v[i],v[j],k)) ;
            if(solve(v2)) return 1 ;
            v2.pop_back() ;
        }
    }
    return 0 ;
}

main()
{
    vector<DB> v ;
    int x ;
    for(int i=0;i<4;i++) scanf("%d",&x) , v.push_back(x) ;
    printf("%s\n",solve(v)?"YES":"NO") ;
}
