#include<stdio.h>
#include<map>
#include<vector>
#include<string.h>
#include<string>
#include<algorithm>
using namespace std;
vector<int> v[2000] ;
map<string,int> mp ;
int lev[2000],root ;
bool vis[2000],ans[2000],cut[2000] ;
string name[2000] ;

int dfs(int n,int l)
{
    lev[n]=l ; vis[n]=1 ;
    int low=l ;
    for(int i=0;i<v[n].size();i++)
    {
        if(vis[v[n][i]]) low=min(low,lev[v[n][i]]) ;
        else
        {
            int newlow=dfs(v[n][i],l+1) ;
            low=min(low,newlow) ;
            if(newlow>=l && n!=root) cut[n]=1 ;
            if(n==root && i>0) cut[root]=1 ;
        }
    }
    return low ;
}

main()
{
    int n,m,tc=0,fir=1;
    while(scanf("%d",&n)==1 && n)
    {
        for(int i=0;i<=n;i++) v[i].clear() ;
        mp.clear() ;
        char s[500],t[500] ;
        string ANS[500] ;
        for(int i=1;i<=n;i++)
        {
            scanf("%s",s) ;
            mp[s]=i ;
            name[i]=s ;
        }
        int m;
        scanf("%d",&m);
        while(m--)
        {
            scanf("%s %s",s,t) ;
            v[mp[s]].push_back(mp[t]) ;
            v[mp[t]].push_back(mp[s]) ;
        }
        memset(vis,0,sizeof(vis)) ;
        memset(cut,0,sizeof(cut)) ;
        for(int i=1;i<=n;i++)
        {
            if(vis[i]) continue ;
            root=i ;
            dfs(i,0) ;
        }
        int cnt=0 ;
        for(int i=1;i<=n;i++)
        {
            if(!cut[i]) continue ;
            cnt++;
            ANS[cnt]=name[i] ;
        }
        sort(ANS+1,ANS+cnt+1) ;
        if(fir) fir=0 ;
        else printf("\n") ;
        printf("City map #%d: %d camera(s) found\n",++tc,cnt) ;
        for(int i=1;i<=cnt;i++)
        {
            for(int j=0;j<ANS[i].size();j++) printf("%c",ANS[i][j]);
            printf("\n");
        }
    }
}
