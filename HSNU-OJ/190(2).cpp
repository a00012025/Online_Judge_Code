#include<bits/stdc++.h>
using namespace std;
const int maxn=100000+100 ;
struct P{int ed,dis;};
bool cmp(const P &x,const P &y){ return x.dis<y.dis ; }
vector<P> v[maxn] ;
int n,k,cnt ;

bool dfs(int x,int val,int d)
{
    cnt++ ; if(cnt>=k) return 1 ;
    for(int i=0;i<v[x].size();i++)
    {
        if(d+v[x][i].dis <= val)
        {
            if(dfs(v[x][i].ed,val,d+v[x][i].dis)) return 1 ;
        }
        else break ;
    }
    return 0 ;
}

main()
{
    int m,st ;
    while(scanf("%d%d%d%d",&n,&m,&k,&st)!=EOF)
    {
        for(int i=1;i<=n;i++) v[i].clear() ;
        while(m--)
        {
            int x,y,dis ; scanf("%d%d%d",&x,&y,&dis) ;
            v[x].push_back((P){y,dis}) ;
        }
        for(int i=1;i<=n;i++) sort(v[i].begin(),v[i].end(),cmp) ;

        int l=-1 , r=1000000000 ;
        while(r-l>1)
        {
            int mid=(r+l)/2 ;
            cnt=0 ;
            dfs(st,mid,0) ;
            if(cnt>=k) r=mid ;
            else l=mid ;
        }
        printf("%d\n",r) ;
    }
}
