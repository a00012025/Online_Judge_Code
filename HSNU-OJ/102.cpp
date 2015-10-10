#include<bits/stdc++.h>
using namespace std;

int n ;
bool G[201][201],now[201] ;
int gp[201] ;

void solve()
{
    vector<int> tmp ;
    int deg[201]={0} ;
    for(int i=1;i<=n;i++) if(now[i]) tmp.push_back(i) ;
    for(int i=1;i<=n;i++) if(now[i])
        for(int j=1;j<=n;j++) if(j!=i && now[j] && G[i][j])
        deg[i]++ ;

    bool ok=1 ;
    int st ;
    for(st=0;st<tmp.size();st++)
        if(deg[tmp[st]]%2) { ok=0 ; break ; }
    if(ok)
    {
        for(int i=0;i<tmp.size();i++) gp[tmp[i]]=1 ;
        return ;
    }

    for(int i=0;i<tmp.size();i++) if(i!=st && G[tmp[i]][tmp[st]])
        for(int j=0;j<tmp.size();j++) if(j!=i && j!=st && G[tmp[j]][tmp[st]])
        G[tmp[i]][tmp[j]]=(!G[tmp[i]][tmp[j]]) ;
    now[tmp[st]]=0 ;
    solve() ;

    int num1=0 ;
    for(int i=0;i<tmp.size();i++)
        if(i!=st && G[tmp[i]][tmp[st]] && gp[tmp[i]]==1)
        num1++ ;
    if(num1%2) gp[tmp[st]]=2 ;
    else gp[tmp[st]]=1 ;
}

main()
{
    scanf("%d",&n) ;
    for(int i=1;i<=n;i++)
    {
        int m ; scanf("%d",&m) ;
        while(m--)
        {
            int x ; scanf("%d",&x) ;
            G[i][x]=1 ;
        }
    }
    for(int i=1;i<=n;i++) now[i]=1 ;
    solve() ;
    int num=0,cnt=0 ;
    for(int i=1;i<=n;i++) if(gp[i]==1) num++ ;
    printf("%d\n",num) ;
    for(int i=1;i<=n;i++) if(gp[i]==1) printf("%d%c",i,++cnt==num?'\n':' ') ;
}
