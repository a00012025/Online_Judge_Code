#include<bits/stdc++.h>
using namespace std;
const int maxn=100000+10 ;

bool vis[maxn] ;
int di[maxn],p[maxn],pcnt ;
void prime()
{
    for(int i=2;i*i<maxn;i++) if(!vis[i])
        for(int j=i*i;j<maxn;j+=i) vis[j]=1 , di[j]=i ;
    for(int i=3;i<maxn;i++) if(!vis[i])
        p[++pcnt]=i ;
    p[++pcnt]=2 ;
}

struct P{int x,y;};
vector<P> ans ;
bool used[maxn] ;
main()
{
    prime() ;
    int n ; scanf("%d",&n) ;
    for(int i=1;i<=pcnt;i++) if(2*p[i]<=n)
    {
        int cnt=0 ;
        for(int j=p[i];j<=n;j+=p[i]) if(!used[j]) cnt++ ;
        if(cnt%2) used[2*p[i]]=1 ;
        for(int j=p[i],last=-1;j<=n;j+=p[i]) if(!used[j])
        {
            used[j]=1 ;
            if(last==-1) last=j ;
            else ans.push_back((P){last,j}) , last=-1 ;
        }
        if(cnt%2) used[2*p[i]]=0 ;
    }
    printf("%d\n",ans.size()) ;
    for(auto i : ans) printf("%d %d\n",i.x,i.y) ;
}
