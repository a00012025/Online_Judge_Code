#include<stdio.h>
#include<string.h>
#include<vector>
#include<algorithm>
using namespace std;
char s[1001001] ;
int n,fail[1001001],fa[1001001] ;
bool u[1001001] ;
vector<int> v[1001001] ;

int getfa(int x)
{
    return fa[x]==x ? x : fa[x]=getfa(fa[x]) ;
}

void init()
{
    scanf("%s",s+1) ; n=strlen(s+1) ;
    for(int i=0;i<=n;i++) {u[i]=0 ; v[i].clear() ;}
    fail[1]=0 ; int j=0 ;
    for(int i=2;i<=n;i++)
    {
        while(j && s[j+1]!=s[i]) j=fail[j] ;
        if(s[j+1]==s[i]) j++ ;
        fail[i]=j ;
    }
    for(int i=n;i;i=fail[i]) u[i]=1 ;
    for(int i=1;i<=n;i++) fa[i]= u[i] ? i : fail[i] ;
    for(int i=1;i<=n;i++) v[getfa(i)].push_back(i) ;
    for(int i=1;i<=n;i++) fa[i]=i-1 ;
    for(int i=1;i<=n;i++) if(u[i])
        for(int j=0;j<v[i].size();j++)
        fa[v[i][j]]=v[i][j] ;
}

main()
{
    //freopen("pf.in","r",stdin);
    //freopen("pf.txt","w",stdout);
    int T ; scanf("%d",&T) ;
    while(T--)
    {
        init() ;
        int ans=n ;
        for(int i=1;i<=n;i++) if(u[i])
        {
            int right=i , t=1 ;
            while(right<n)
            {
                int right2=getfa(min(right+i,n)) ;
                if(right2 <= right) break ;
                right=right2 ; t++ ;
            }
            if(right==n) ans=max(ans,i*t) ;
            for(int j=0;j<v[i].size();j++)
                fa[v[i][j]]=getfa(v[i][j]-1) ;
        }
        printf("%d\n",ans);
    }
}
