#include<bits/stdc++.h>
#define LL long long
#define F first
#define S second
using namespace std;
const int maxn=10+2 ;

int n ;
int encode(int *a)
{
    int ret=0 ;
    for(int i=0;i<=n;i++) ret=ret*7+a[i] ;
    return ret ;
}
void decode(int val,int *a)
{
    for(int i=n;i>=0;i--) a[i]=val%7 , val/=7 ;
}

int tmp[8] ;
void norm(int *a)
{
    memset(tmp,0,sizeof(tmp)) ;
    for(int i=0,j=2;i<=n;i++) if(a[i]>1)
    {
        if(!tmp[a[i]]) tmp[a[i]]=j++ ;
        a[i]=tmp[a[i]] ;
    }
}

map<int,LL> dp[2] ;
int t[maxn] ;
void trans(int cur,int i,int j,int S,LL add)
{
    decode(S,t) ;
    int x=t[j] , y=t[j+1] ;
    if(x&&y)
    {
        if(x==y && (i!=n-1||j!=n-1)) return ;
        if(x==y)
        {
            assert(x==1) ;
            t[j]=t[j+1]=0 ;
        }
        else if(x==1)
        {
            for(int k=0;k<=n;k++) if(k!=j+1&&t[k]==y)
                {t[k]=1 , t[j]=t[j+1]=0 ; break ;}
        }
        else if(y==1)
        {
            for(int k=0;k<=n;k++) if(k!=j&&t[k]==x)
                {t[k]=1 , t[j]=t[j+1]=0 ; break ;}
        }
        else
        {
            for(int k=0;k<=n;k++) if(k!=j+1&&t[k]==y)
                {t[k]=x ; t[j]=t[j+1]=0 ; break ;}
        }
        norm(t) ;
        dp[cur][encode(t)]+=add ;
    }
    else if(x&&!y)
    {
        if(i!=n-1) dp[cur][S]+=add ;
        swap(t[j],t[j+1]) ;
        if(j!=n-1) dp[cur][encode(t)]+=add ;
    }
    else if(y&&!x)
    {
        if(j!=n-1) dp[cur][S]+=add ;
        swap(t[j],t[j+1]) ;
        if(i!=n-1) dp[cur][encode(t)]+=add ;
    }
    else if(i!=n-1 && j!=n-1)
    {
        t[j]=t[j+1]=7 ;
        norm(t) ;
        dp[cur][encode(t)]+=add ;
    }
}

void solve()
{
    int cur=0 ;
    for(int i=0;i<n;i++) for(int j=0;j<=n;j++,cur^=1)
    {
        dp[cur].clear() ;
        if(i==0 && j==0)
        {
            memset(t,0,sizeof(t)) ;
            t[0]=1 ; dp[cur][encode(t)]=1 ; t[0]=0 ;
            t[1]=1 ; dp[cur][encode(t)]=1 ;
        }
        else if(j==n) for(auto it : dp[cur^1])
            dp[cur][it.F/7]+=it.S ;
        else if(i==n-1&&j==0) for(auto it : dp[cur^1])
        {
            decode(it.F,t) ;
            if(t[1]==1) continue ;
            if(!t[1]) t[1]=1 ;
            else for(int k=2;k<=n;k++) if(t[k]==t[1])
                {t[1]=0 ; t[k]=1 ; break ;}
            norm(t) ;
            dp[cur][encode(t)]+=it.S ;
        }
        else for(auto it : dp[cur^1])
            trans(cur,i,j,it.F,it.S) ;
    }
    printf("%lld\n",dp[cur^1][0]) ;
}

main()
{
    while(scanf("%d",&n)!=EOF) solve() ;
}
