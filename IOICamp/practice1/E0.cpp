#include<bits/stdc++.h>
#define LL long long
#define MOD (1LL<<52)
#define F first
#define S second
using namespace std;
const int maxn=12+1 ;

int n,m,lasx,lasy ;
char G[maxn][maxn] ;
LL encode(LL *a)
{
    LL ret=0 ;
    for(int i=0;i<=m;i++) ret^=(a[i]<<(3*(m-i))) ;
    return ret ;
}
void decode(LL val,LL *a)
{
    for(int i=m;i>=0;i--) a[i]=val&7 , val>>=3 ;
}

int tmp[8] ;
void norm(LL *a)
{
    memset(tmp,0,sizeof(tmp)) ;
    for(int i=0,j=1;i<=m;i++) if(a[i]>=1)
    {
        if(!tmp[a[i]]) tmp[a[i]]=j++ ;
        a[i]=tmp[a[i]] ;
    }
}

unordered_map<LL,LL> dp[2] ;
LL t[maxn] ;
void trans(int cur,int i,int j,LL S,LL add)
{
    if(G[i][j]=='X')
    {
        dp[cur][S]+=add ;
        return ;
    }

    decode(S,t) ;
    int x=t[j] , y=t[j+1] ;
    if(x&&y)
    {
        if(x==y && (i!=lasx||j!=lasy)) return ;
        if(x==y) t[j]=t[j+1]=0 ;
        else
        {
            for(int k=0;k<=m;k++) if(k!=j+1&&t[k]==y)
                {t[k]=x ; t[j]=t[j+1]=0 ; break ;}
            norm(t) ;
        }
        dp[cur][encode(t)]+=add ;
    }
    else if(x&&!y)
    {
        if(i!=n-1 && G[i+1][j]!='X') dp[cur][S]+=add ;
        swap(t[j],t[j+1]) ;
        if(j!=m-1 && G[i][j+1]!='X') dp[cur][encode(t)]+=add ;
    }
    else if(y&&!x)
    {
        if(j!=m-1 && G[i][j+1]!='X') dp[cur][S]+=add ;
        swap(t[j],t[j+1]) ;
        if(i!=n-1 && G[i+1][j]!='X') dp[cur][encode(t)]+=add ;
    }
    else if(i!=n-1 && j!=m-1 && G[i+1][j]!='X' && G[i][j+1]!='X')
    {
        t[j]=t[j+1]=7 ;
        norm(t) ;
        dp[cur][encode(t)]+=add ;
    }
}

void solve()
{
    scanf("%d%d",&n,&m) ;
    for(int i=0;i<n;i++)
    {
        scanf("%s",G[i]) ;
        for(int j=0;j<m;j++) if(G[i][j]!='X')
            lasx=i , lasy=j ;
    }

    int cur=0 ; dp[1][0]=1 ;
    for(int i=0;i<n;i++) for(int j=0;j<=m;j++,cur^=1)
    {
        dp[cur].clear() ;
        if(j==m) for(auto it : dp[cur^1])
            dp[cur][it.F>>3]+=it.S ;
        else for(auto it : dp[cur^1])
            trans(cur,i,j,it.F,it.S) ;
    }
    printf("%lld\n",dp[cur^1][0]%MOD) ;
}

main()
{
    if(fopen("in","r"))
    {
        freopen("in","r",stdin) ;
        freopen("out1","w",stdout) ;
    }
    int T ; scanf("%d",&T) ;
    while(T--) solve() ;
}
