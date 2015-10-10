#include<bits/stdc++.h>
#define lowbit(x) ((x)&(-(x)))
using namespace std;

int a ;
vector<int> v[40] ;

int high(int x)
{
    for(int i=30;i>=0;i--) if(x&(1<<i)) return i ;
}

main()
{
    int n ; scanf("%d",&n) ;
    for(int i=1;i<=n;i++)
    {
        scanf("%d",&a) ;
        for(int j=30;j>=0;j--) if(a&(1<<j)) v[j].push_back(a) ;
    }

    int ans=0,ansid,anssz=0 ;
    for(int i=30;i>=0;i--) if(v[i].size())
    {
        int now=INT_MAX ;
        for(int j=0;j<v[i].size();j++) now&=v[i][j] ;
        if(lowbit(now)>ans || (lowbit(now)==ans && v[i].size()>anssz)) ans=lowbit(now) , ansid=i ;
    }

    printf("%d\n",v[ansid].size()) ;
    sort(v[ansid].begin(),v[ansid].end()) ;
    for(int i=0;i<v[ansid].size();i++) printf("%d%c",v[ansid][i],i+1==v[ansid].size()?'\n':' ') ;
}
