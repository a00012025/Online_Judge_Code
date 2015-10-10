#include<bits/stdc++.h>
#define LL long long
#define F first
#define S second
#define M 4321
#define MOD (1LL<<52)
using namespace std;
const int maxn=12+1 ;
int thr[]={0,3,6,9,12,15,18,21,24,27,30,33,36,39} ;

struct node
{
    node *nex ;
    LL key,val ;
    node(LL _key,LL _val){nex=NULL ; key=_key ; val=_val ;}
};
struct Hash
{
    node *head[M] ;
    void add(LL key,LL val)
    {
        bool found=0 ; LL h=key%M ;
        for(node *u=head[h];u;u=u->nex) if(u->key==key)
            {u->val=(u->val+val)%MOD ; found=1 ; break ;}
        if(!found)
        {
            node *v=head[h] ;
            head[h]=new node(key,val) ;
            head[h]->nex=v ;
        }
    }
    LL find(LL key)
    {
        LL h=key%M ;
        for(node *u=head[h];u;u=u->nex) if(u->key==key)
            return u->val ;
        return 0LL ;
    }
}dp[2];

int n,m,lasx,lasy ;
char G[maxn][maxn] ;
LL encode(LL *a)
{
    LL ret=0 ;
    for(int i=0;i<=m;i++) ret^=(a[i]<<thr[m-i]) ;
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

LL t[maxn] ;
void trans(int cur,int i,int j,LL S,LL add)
{
    if(G[i][j]=='X')
    {
        dp[cur].add(S,add) ;
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
        dp[cur].add(encode(t),add) ;
    }
    else if(x&&!y)
    {
        if(i!=n-1 && G[i+1][j]!='X') dp[cur].add(S,add) ;
        swap(t[j],t[j+1]) ;
        if(j!=m-1 && G[i][j+1]!='X') dp[cur].add(encode(t),add) ;
    }
    else if(y&&!x)
    {
        if(j!=m-1 && G[i][j+1]!='X') dp[cur].add(S,add) ;
        swap(t[j],t[j+1]) ;
        if(i!=n-1 && G[i+1][j]!='X') dp[cur].add(encode(t),add) ;
    }
    else if(i!=n-1 && j!=m-1 && G[i+1][j]!='X' && G[i][j+1]!='X')
    {
        t[j]=t[j+1]=7 ;
        norm(t) ;
        dp[cur].add(encode(t),add) ;
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

    int cur=0 ; dp[1].add(0,1) ;
    for(int i=0;i<n;i++) for(int j=0;j<=m;j++,cur^=1)
    {
        if(j==m) for(int h=0;h<M;h++)
            for(node *u=dp[cur^1].head[h];u;u=dp[cur^1].head[h])
        {
            dp[cur].add(u->key>>3,u->val) ;
            dp[cur^1].head[h]=u->nex ;
            delete(u) ;
        }
        else for(int h=0;h<M;h++)
            for(node *u=dp[cur^1].head[h];u;u=dp[cur^1].head[h])
        {
            trans(cur,i,j,u->key,u->val) ;
            dp[cur^1].head[h]=u->nex ;
            delete(u) ;
        }
    }
    printf("%lld\n",dp[cur^1].find(0)) ;
    for(int h=0;h<M;h++) dp[cur^1].head[h]=NULL ;
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

