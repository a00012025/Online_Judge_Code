#include<bits/stdc++.h>
#define LL long long
using namespace std;
const int maxn=500001 ;

bool vis[maxn] ;
int pcnt,p[maxn] ;
void make_prime()
{
    pcnt=0 ;
    for(int i=2;i*i<maxn;i++) if(!vis[i])
        for(int j=i*i;j<maxn;j+=i) vis[j]=1 ;
    for(int i=2;i<maxn;i++) if(!vis[i])
        p[++pcnt]=i ;
}

int now1[maxn],now2[maxn] ;
int MOD ;
void mul(int *now,int val,int d)
{
    if(!vis[val]) { now[val]+=d ; return ; }
    for(int i=1;val!=1 && i<=pcnt;i++) if((val%p[i])==0)
    {
        while((val%p[i])==0) val/=p[i] , now[p[i]]+=d ;
        if(!vis[val]) { now[val]+=d ; break ; }
    }
}

LL get_val(int *now)
{
    LL ret=1LL ;
    for(int i=1;i<=pcnt;i++) for(int j=1;j<=now[p[i]];j++)
        ret = (ret * p[i]) % MOD ;
    return ret ;
}

struct P
{
    int len,x ;
    bool operator < (const P &rhs) const
    {
        if(len!=rhs.len) return len>rhs.len ;
        else return x>rhs.x ;
    }
}a[maxn];

bool vis2[maxn] ;
int num[maxn],M[maxn] ;
main()
{
    make_prime() ;
    int n,k ; scanf("%d%d%d",&n,&k,&MOD) ;
    for(int i=1;i<=n;i++) scanf("%d%d",&a[i].len,&a[i].x) , num[a[i].x]++ ;
    sort(a+1,a+n+1) ;
    int j=1 ;
    while( j<=n && 2*a[j].len>a[1].len ) num[a[j].x]-- , j++ ;
    for(int i=1;i<=k;i++) mul(now1,num[i]+1,1) , mul(now2,num[i]+1,1) ;

    int cnt=0 ; LL ans=0LL ;
    for(int i=1;i<=n;i++) if(!vis2[a[i].x])
    {
        vis2[a[i].x]=1 ; cnt++ ;
        mul(now2,num[a[i].x]+1,-1) ;
        while( j<=n && 2*a[j].len>a[i].len )
        {
            mul(now1,num[a[j].x]+1,-1) ;
            mul(now1,num[a[j].x],1) ;
            if(!vis2[a[j].x])
            {
                mul(now2,num[a[j].x]+1,-1) ;
                mul(now2,num[a[j].x],1) ;
            }
            num[a[j].x]-- ; j++ ;
        }
        //printf("now1=%d , now2=%d\n",get_val(now1),get_val(now2));

        if(i==1)
        {
            for(int z=1;z<=k;z++) M[z]=num[z] ;
            ans=(ans+get_val(now1))%MOD ; //printf("ans=%d\n",ans) ;
            continue ;
        }

        if(num[a[i].x]<M[a[i].x])
        {
            ans+=(get_val(now2)*(num[a[i].x]+1))%MOD ; ans%=MOD ;
            //printf("~ans=%d\n",ans) ;
        }
        else
        {
            mul(now1,num[a[i].x]+1,-1) ;
            ans+=get_val(now1) ; ans%=MOD ;
            mul(now1,num[a[i].x]+1,1) ;
            ans+=get_val(now2)*num[a[i].x] ; ans%=MOD ;
            //printf("ans=%d\n",ans) ;
        }
    }
    printf("%d\n",ans) ;
}
