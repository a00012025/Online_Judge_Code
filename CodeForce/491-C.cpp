#include<bits/stdc++.h>
using namespace std;
const int maxn=100 , maxm=2000000+10 , INF=1000000000 ;

int adj[maxn][maxn] ;
bool visx[maxn] , visy[maxn] ;
int n , mx[maxn] , my[maxn] , labx[maxn] , laby[maxn] ;
bool dfs(int x)
{
    visx[x]=1 ;
    for(int i=0;i<n;i++) if(!visy[i] && labx[x]+laby[i]==adj[x][i])
    {
        visy[i]=1 ;
        if(my[i]==-1 || dfs(my[i]))
        {
            mx[x]=i ; my[i]=x ;
            return 1 ;
        }
    }
    return 0 ;
}

bool update_label()
{
    int a=INF ;
    for(int i=0;i<n;i++) if(visx[i])
        for(int j=0;j<n;j++) if(adj[i][j]!=INF && !visy[j])
            a=min(a,labx[i]+laby[j]-adj[i][j]) ;
    if(a==INF) return 0 ;
    for(int i=0;i<n;i++) if(visx[i]) labx[i] -= a ;
    for(int i=0;i<n;i++) if(visy[i]) laby[i] += a ;
    return 1 ;
}

int Hungarian()
{
    memset(labx,0,sizeof(labx)) ;
    memset(laby,0,sizeof(laby)) ;
    for(int i=0;i<n;i++) for(int j=0;j<n;j++) if(adj[i][j]!=INF)
        laby[j]=max(laby[j],adj[i][j]) ;
    memset(mx,-1,sizeof(mx)) ;
    memset(my,-1,sizeof(my)) ;
    for(int i=0;i<n;i++)
    {
        while(1)
        {
            memset(visx,0,sizeof(visx)) ; memset(visy,0,sizeof(visy)) ;
            if(dfs(i)) break ;
            if(!update_label()) return -INF ;
        }
    }
    int ret=0 ;
    for(int i=0;i<n;i++) ret+=adj[i][mx[i]] ;
    return ret ;
}

inline int id(char c)
{
    return c>='a' ? c-'a' : c-'A'+26 ;
}
inline char ch(int id)
{
    return id<26 ? id+'a' : id-26+'A' ;
}

int cal(const vector<int> &v1,const vector<int> &v2)
{
    int ret=0 ;
    for(int i=0,j=0;i<v1.size()&&j<v2.size();)
    {
        if(v1[i]==v2[j]){ret++ ; i++ ; j++ ;}
        else if(v1[i]>v2[j]) j++ ;
        else i++ ;
    }
    return ret ;
}

char s[maxm],t[maxm] ;
vector<int> v1[52],v2[52] ;
main()
{
    int m ; scanf("%d%d%s%s",&m,&n,s,t) ;
    for(int i=0;i<m;i++)
        v1[id(s[i])].push_back(i) ,
        v2[id(t[i])].push_back(i) ;
    for(int i=0;i<n;i++) for(int j=0;j<n;j++)
        adj[i][j]=cal(v1[i],v2[j]) ;
    printf("%d\n",Hungarian()) ;
    for(int i=0;i<n;i++) printf("%c",ch(mx[i])) ;
    printf("\n") ;
}
