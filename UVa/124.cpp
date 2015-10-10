#include<stdio.h>
#include<map>
#include<vector>
#include<string.h>
#include<algorithm>
using namespace std;
map<char,int> mp ;
vector<int> v[50] ;
int in[50000],n,ans[50000],fir=1 ;
bool vis[50000],alpha[27] ;
char s[10000],id[10000] ;

bool no(char c)
{
    if(c>='a' && c<='z') return 0 ;
    else return 1 ;
}

void dfs(int num)
{
    if(num==n)
    {
        for(int i=1;i<=n;i++) printf("%c",id[ans[i]]) ;
        printf("\n") ;
        return ;
    }
    for(int i=0;i<n;i++) if(!vis[i] && !in[i])
    {
        ans[num+1]=i ; vis[i]=1 ;
        for(int j=0;j<v[i].size();j++) in[v[i][j]]-- ;
        dfs(num+1) ;
        vis[i]=0 ;
        for(int j=0;j<v[i].size();j++) in[v[i][j]]++ ;
    }
}

main()
{
    char t[10000] ;
    while(gets(s))
    {
        mp.clear() ;
        memset(in,0,sizeof(in)) ;
        memset(alpha,0,sizeof(alpha)) ;
        n=0 ;
        for(int i=0;i<strlen(s);i++) if(!no(s[i])) alpha[s[i]-'a']=1 ;
        for(int i=0;i<26;i++) if(alpha[i]) {mp[i+'a']=n ; id[n]=i+'a' ; n++ ;} ;
        for(int i=0;i<=n;i++) v[i].clear() ;
        gets(t) ;
        for(int i=0;i<strlen(t);)
        {
            for(;i<strlen(t) && no(t[i]);i++) ;
            if(i==strlen(t)) break ;
            int id1=mp[t[i]] ;

            for(i=i+1;i<strlen(t) && no(t[i]);i++) ;
            if(i==strlen(t)) break ;
            int id2=mp[t[i]] ;

            v[id1].push_back(id2) ;
            in[id2]++ ; i++ ;
        }
        for(int i=0;i<n;i++)
        {
            int tmp[100] ;
            for(int j=0;j<v[i].size();j++) tmp[j]=v[i][j] ;
            sort(tmp,tmp+v[i].size()) ;
            for(int j=0;j<v[i].size();j++) v[i][j]=tmp[j] ;
        }
        memset(vis,0,sizeof(vis)) ;
        if(fir==1) fir=0 ;
        else printf("\n") ;
        dfs(0) ;
    }
}
