#include<bits/stdc++.h>
#define INF 10000000
#define ABS(x) ( (x)>0 ? (x) : (-(x)) )
using namespace std;
const int maxn=1000000+10 ;

struct P{int x,y;};
P cal(const P &p,int t)
{
    return t==0 ? (P){p.x,p.y+1} : (P){p.x+1,p.y} ;
}

vector<int> v[26] ;
int tmp[maxn] ;
int solve(const vector<int> &v1,const vector<int> &v2)
{
    int cnt=0 , j=0 ;
    for(int i=0;i<v1.size();i++)
    {
        while(j<v2.size() && v2[j]<v1[i])
            j++ , tmp[cnt++]=1 ;
        tmp[cnt++]=0 ;
    }
    while(j<v2.size()) tmp[cnt++]=1 , j++ ;

    int ret=0 ;
    P p={0,0},p2={0,0} ;
    for(int i=0,j=0 , mi=0,ma=0;i<cnt;i++)
    {
        p=cal(p,tmp[i]) ;
        if(!p.x || !p.y) continue ;
        while(j<i)
        {
            P np2=cal(p2,tmp[j]) ;
            if(np2.x==p.x || np2.y==p.y) break ;
            p2=np2 ;
            mi=min(mi,p2.x-p2.y) ;
            ma=max(ma,p2.x-p2.y) ;
            j++ ;
        }
        ret=max(ret,ABS(p.x-p.y-mi)) ;
        ret=max(ret,ABS(p.x-p.y-ma)) ;
    }
    return ret ;
}

char s[maxn] ;
main()
{
    int n ; scanf("%d%s",&n,s+1) ;
    for(int i=1;i<=n;i++) v[s[i]-'a'].push_back(i) ;
    int ans=0 ;
    for(int i=0;i<26;i++) if(!v[i].empty())
        for(int j=i+1;j<26;j++) if(!v[j].empty())
        ans=max(ans,solve(v[i],v[j])) ;
    printf("%d\n",ans) ;
}
