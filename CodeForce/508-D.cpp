#include<bits/stdc++.h>
using namespace std;
const int maxn=4000,maxm=200000+100 ;

int id(char c)
{
    if(c>='0' && c<='9') return 52+c-'0' ;
    if(c>='A' && c<='Z') return 26+c-'A' ;
    return c-'a' ;
}

int id(char *s)
{
    return 62*id(s[0])+id(s[1]) ;
}

char inv(int x)
{
    if(x>=52) return x-52+'0' ;
    if(x>=26) return x-26+'A' ;
    return x+'a' ;
}

struct P{int from,to;};
vector<P> edge ;
vector<int> v[maxn] ;

int in[maxn],out[maxn] ;
bool check()
{
    int cnt=0 ;
    for(int i=0;i<maxn;i++)
    {
        if(in[i]>out[i]+1 || out[i]>in[i]+1) return 0 ;
        if(in[i]!=out[i]) cnt++ ;
    }
    return (cnt<=2) ;
}

vector<int> ans ;
bool vis[maxm] ;
int now[maxn] ;
void dfs(int x)
{
    for(int i=now[x];i<v[x].size();i=now[x]+1)
    {
        now[x]++ ;
        if(!vis[v[x][i]]) vis[v[x][i]]=1 , dfs(edge[v[x][i]].to) ;
    }
    ans.push_back(x) ;
}

main()
{
    int n ; scanf("%d",&n) ;
    for(int i=0;i<n;i++)
    {
        char t[5] ; scanf("%s",t) ;
        int x=id(t) , y=id(t+1) ;
        edge.push_back((P){x,y}) ;
        in[y]++ ; out[x]++ ;
        v[x].push_back(i) ;
    }

    if(!check()) { printf("NO\n") ; return 0 ; }
    int st,odd=0 ;
    for(int i=0;i<maxn;i++) if(in[i]!=out[i]) odd=1 ;
    if(!odd) for(st=0;in[st]==0 && out[st]==0;st++) ;
    else for(st=0;out[st]!=in[st]+1;st++) ;

    dfs(st) ;
    if(ans.size()!=n+1) { printf("NO\n") ; return 0 ; }
    printf("YES\n") ;
    printf("%c",inv(ans[n]/62)) ;
    for(int i=n;i>=0;i--) printf("%c",inv(ans[i]%62)) ;
    printf("\n") ;
}
