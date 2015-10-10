#include<bits/stdc++.h>
#define LL long long
using namespace std;

vector<int> v[200001],two ;
int id[200001] ;
LL num[200001] ;

int getid(int x)
{
    return id[x]==x ? x : id[x]=getid(id[x]) ;
}

void dfs(int x,int cnt)
{
    id[x]=cnt ;
    for(int i=0;i<v[x].size();i++) if(getid(v[x][i])!=cnt)
        dfs(getid(v[x][i]),cnt) ;
}

main()
{
    int n,m ; scanf("%d%d",&n,&m) ;
    for(int i=1;i<=m;i++)
    {
        int x,y ; scanf("%d%d",&x,&y) ;
        v[x].push_back(y) ;
    }
    int cnt=n ;
    for(int i=1;i<=n;i++) id[i]=i ;
    for(int i=1;i<=n;i++) if(v[i].size()>=2) two.push_back(i) ;
    for(int i=0;i<two.size();i++)
    {
        int x=id[two[i]] ;
        if(x>n) continue ;
        cnt++ ; id[cnt]=cnt ;
        for(int j=0;j<v[x].size();j++) if(getid(v[x][j])!=cnt)
            dfs(getid(v[x][j]),cnt) ;
    }
    for(int i=1;i<=n;i++) getid(i) , num[id[i]]++ ;
    for(int i=1;i<=n;i++) for(int j=0;j<v[i].size();j++)
        if(id[i]==id[v[i][j]]) m-- ;
    LL ans=(LL)m ;
    for(int i=1;i<=cnt;i++) ans+= num[i]*(num[i]-1) ;
    printf("%lld\n",ans) ;
}
