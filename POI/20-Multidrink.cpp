#include<bits/stdc++.h>
using namespace std;
const int maxn=500000+10 ;

vector<int> v[maxn] ;
int fa[maxn],nex[maxn] ;

void del(int x,int y)
{
    for(int i=0;i<v[x].size();i++) if(v[x][i]==y)
    {
        for(int j=i;j+1<v[x].size();j++) v[x][j]=v[x][j+1] ;
        v[x].resize((int)v[x].size()-1) ;
        break ;
    }
}

void dfs0(int x)
{
    for(int i=0;i<v[x].size();i++) if(v[x][i]!=fa[x])
        fa[v[x][i]]=x , dfs0(v[x][i]) ;
}

bool cmp(int a,int b){ return v[a].size()>v[b].size() ; }

int cnt=0 , ans[maxn] ;

int solve1(int x) ;
int solve2(int x,int type)
{
    if(v[v[x][0]].empty())
    {
        for(int i=0;i<v[x].size();i++) ans[cnt++]=v[x][i] ;
        ans[cnt++]=x ;
        return 1 ;
    }

    int num=0 ;
    while(num<v[x].size() && !v[v[x][num]].empty()) num++ ;
    if(num>2) return 0 ;
    if(type==0)
    {
        if(num>1) return 0 ;
        for(int i=1;i<v[x].size();i++) ans[cnt++]=v[x][i] ;
        if(!solve1(v[x][0])) return 0 ;
        ans[cnt++]=x ;
        return 1 ;
    }

    if(num==1)
    {
        int tmp=cnt ;
        for(int i=1;i<v[x].size();i++) ans[cnt++]=v[x][i] ; if(!solve1(v[x][0]))
        {
            cnt=tmp ;
            ans[cnt++]=x ;
            if(!solve2(v[x][0],0)) return 0 ;
            for(int i=1;i<v[x].size();i++) ans[cnt++]=v[x][i] ;
            return 2 ;
        }
        else
        {
            ans[cnt++]=x ;
            return 1 ;
        }
    }
    else for(int i=0;i<2;i++)
    {
        int s1=v[x][i] , s2=v[x][(i+1)%2] ;
        int tmp=cnt ;
        for(int j=2;j<v[x].size();j++) ans[cnt++]=v[x][j] ;
        if(solve1(s1))
        {
            ans[cnt++]=x ;
            if(solve2(s2,0)) return 2 ;
        }
        cnt=tmp ;
    }
    return 0 ;
}
int solve1(int x)
{
    if(v[x].size()>=2 && !v[v[x][0]].empty()
        && !v[v[x][1]].empty()) return 0 ;

    ans[cnt++]=x ;
    if(v[x].empty()) return 1 ;
    if(!v[v[x][0]].empty())
    {
        if(!solve2(v[x][0],0)) return 0 ;
        for(int i=1;i<v[x].size();i++) ans[cnt++]=v[x][i] ;
    }
    else for(int i=0;i<v[x].size();i++) ans[cnt++]=v[x][i] ;
    return 2 ;
}

main()
{
    int n ; scanf("%d",&n) ;
    for(int i=1;i<n;i++)
    {
        int x,y ; scanf("%d%d",&x,&y) ;
        v[x].push_back(y) ;
        v[y].push_back(x) ;
    }

    fa[1]=1 ; dfs0(1) ;
    for(int x=n;x!=1;x=fa[x]) nex[fa[x]]=x , del(fa[x],x) ;
    for(int x=2;x<=n;x++) del(x,fa[x]) ;

    for(int i=1;i<=n;i++) sort(v[i].begin(),v[i].end(),cmp) ;

    int last=2 ;
    for(int i=1;i!=n;i=nex[i])
    {
        if(last==1 && !v[i].empty()) last=solve2(i,1) ;
        else last=solve1(i) ;
        if(!last) { printf("BRAK\n") ; return 0 ; }
    }
    if(!v[n].empty() && last==2) { printf("BRAK\n") ; return 0 ; }
    if(v[n].empty()) ans[cnt++]=n ;
    else if(!solve2(n,0)) { printf("BRAK\n") ; return 0 ; }
    for(int i=0;i<n;i++) printf("%d\n",ans[i]) ;
}
