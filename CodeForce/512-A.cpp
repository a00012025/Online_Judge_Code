#include<bits/stdc++.h>
using namespace std;
vector<int> v[30] ;

char s[101][101] ;
int len[101] ;

int topo[30],t ;
int vis[30] ;

bool dfs(int x)
{
    vis[x]=-1 ;
    for(auto i : v[x])
    {
        if(vis[i]==-1) return 0 ;
        if(vis[i]==1) continue ;
        if(!dfs(i)) return 0 ;
    }
    vis[x]=1 ; topo[--t]=x ;
    return 1 ;
}

main()
{
    int n ; scanf("%d",&n) ;
    for(int i=1;i<=n;i++) scanf("%s",s[i]) , len[i]=strlen(s[i]) ;
    for(int i=1;i<=n;i++) for(int j=i+1;j<=n;j++)
    {
        int k=0 ;
        for(;k<len[i]&&k<len[j]&&s[i][k]==s[j][k];k++) ;
        if(k!=len[i] && k==len[j])
            { printf("Impossible\n") ; return 0 ; }
        if(k==len[i]) continue ;
        v[s[i][k]-'a'].push_back(s[j][k]-'a') ;
    }

    for(int i=0;i<26;i++)
        sort(v[i].begin(),v[i].end()) ,
        v[i].resize(unique(v[i].begin(),v[i].end())-v[i].begin()) ;

    t=26 ;
    for(int i=0;i<26;i++) if(!vis[i])
    {
        if(!dfs(i)) { printf("Impossible\n") ; return 0 ; }
    }

    for(int i=0;i<26;i++) printf("%c",topo[i]+'a') ;
    printf("\n") ;
}
