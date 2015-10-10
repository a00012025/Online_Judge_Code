#include<bits/stdc++.h>
using namespace std;
const int maxn=10000+10 ;
int n ;
vector<int> v[maxn] ;

int dfs(int x,int fa,int num)
{
    if(x!=1 && v[x].size()==1) return 0 ;
    vector<int> tmp ;
    for(auto i : v[x]) if(i!=fa)
    {
        int val=dfs(i,x,num) ;
        if(val==-1) return -1 ;
        tmp.push_back(val+1) ;
    }
    sort(tmp.begin(),tmp.end()) ;
    int sz=tmp.size() ;

    if(tmp[sz-1]>num) return -1 ;
    if((sz%2)==0)
    {
        bool ok=1 ;
        for(int i=0;sz-1-i>i;i++) if(tmp[i]+tmp[sz-1-i]>num)
            {ok=0 ; break ;}
        if(ok) return 0 ;
        if(x==1) return -1 ;
        tmp.resize(sz-1) ; sz-- ;
    }

    for(int i=0;i<sz;i++)
    {
        int l=0 , r=sz-1 , ok=1 ;
        while(r>l)
        {
            if(l==i) l++ ;
            if(r==i) r-- ;
            if(r<=l) break ;
            if(tmp[l]+tmp[r]>num) { ok=0 ; break ; }
            l++ ; r-- ;
        }
        if(ok) return tmp[i] ;
    }
    return -1 ;
}

bool check(int num)
{
    return (dfs(1,1,num)!=-1) ;
}

main()
{
    scanf("%d",&n) ;
    for(int i=1;i<n;i++)
    {
        int x,y ; scanf("%d%d",&x,&y) ;
        v[x].push_back(y) ;
        v[y].push_back(x) ;
    }

    int num=0 ;
    for(int i=1;i<=n;i++) if(v[i].size()%2) num++ ;
    printf("%d ",num/2) ;

    int l=0 , r=n-1 ;
    while(r-l>1)
    {
        int mid=(r+l)/2 ;
        if(check(mid)) r=mid ;
        else l=mid ;
    }
    printf("%d\n",r) ;
}
