#include<bits/stdc++.h>
using namespace std;
const int maxn=100000+10,MAX=2000000+10 ;

bool vis[MAX] ;
int pr[MAX] ;
void prime()
{
    for(int i=2;i*i<MAX;i++) if(!vis[i])
        for(int j=i*i;j<MAX;j+=i) vis[j]=1 , pr[j]=i ;
    for(int i=2;i<MAX;i++) if(!vis[i])
        pr[i]=i ;
}

vector<int> v[maxn] ;
int a[maxn] ;
int ans[maxn],now[MAX],dep[maxn] ;
void dfs(int x,int f,int de=1)
{
    dep[x]=de ;
    int di[7],tmp[7],dcnt=0 ;
    for(int i=a[x];i!=1;)
    {
        di[dcnt++]=pr[i] ;
        int j=i ;
        while(j%pr[i]==0) j/=pr[i] ;
        i=j ;
    }

    for(int i=0;i<dcnt;i++)
    {
        if(dep[now[di[i]]]>dep[ans[x]]) ans[x]=now[di[i]] ;
        tmp[i]=now[di[i]] , now[di[i]]=x ;
    }
    for(auto i : v[x]) if(i!=f) dfs(i,x,de+1) ;
    for(int i=0;i<dcnt;i++) now[di[i]]=tmp[i] ;
}

main()
{
    prime() ;
    int n,Q ; scanf("%d%d",&n,&Q) ;
    for(int i=1;i<=n;i++) scanf("%d",&a[i]) ;
    for(int i=1;i<n;i++)
    {
        int x,y ; scanf("%d%d",&x,&y) ;
        v[x].push_back(y) ;
        v[y].push_back(x) ;
    }
    dfs(1,1) ;
    while(Q--)
    {
        int t ; scanf("%d",&t) ;
        if(t==2)
        {
            int x,y ; scanf("%d%d",&x,&y) ;
            a[x]=y ; memset(ans,0,sizeof(ans)) ;
            dfs(1,1) ;
        }
        else
        {
            int x ; scanf("%d",&x) ;
            printf("%d\n",ans[x]==0?-1:ans[x]) ;
        }
    }
}
