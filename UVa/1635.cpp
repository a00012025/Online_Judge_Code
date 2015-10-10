#include<bits/stdc++.h>
#define LL long long
using namespace std;
const int maxn=100000 + 5 ;
int cnt,pm[maxn],id[maxn],m,n ;
bool vis[maxn] ;
void get_prime()
{
    memset(vis,0,sizeof(vis)) ;
    for(int i=2;i<350;i++) if(!vis[i])
        for(int j=i*i;j<maxn;j+=i) vis[j]=1 ;
    cnt=0 ;
    for(int i=2;i<maxn;i++) if(!vis[i])
        pm[++cnt]=i , id[i]=cnt ;
}

bool ans[maxn] ;
int m2[maxn],a[maxn],maxm2 ;

int ok_num ;
void multi(int x,int type)
{
    for(int i=1;x!=1 && i<=cnt;i=(vis[x]?i+1:id[x])) if(x%pm[i]==0)
    {
        while(x%pm[i]==0)
        {
            x/=pm[i] ;
            a[i]+=type ;
            if(a[i]==m2[i] && type==1) ok_num++ ;
            if(a[i]==m2[i]-1 && type==-1) ok_num-- ;
        }
    }
}

int solve()
{
    if(n==0 && m==1) {ans[0]=1 ; return 1 ;}
    else if(n==0) return 0 ;
    memset(ans,0,sizeof(ans)) ;
    memset(m2,0,sizeof(m2)) ;
    for(int i=1;i<=cnt;i++) if(m%pm[i]==0)
    {
        if(pm[i]>n) return 0 ;
        while(m%pm[i]==0) {m/=pm[i] ; m2[i]++ ;}
    }
    if(m!=1) return 0 ;
    memset(a,0,sizeof(a)) ;
    int num=0 ; ok_num=0 ;
    for(int i=1;i<=cnt;i++) if(m2[i]==0) ok_num++ ;
    for(int k=0;k<=n;k++)
    {
        if(ok_num==cnt) ans[k]=1 , num++ ;
        if(k!=n) {multi(n-k,1) ; multi(k+1,-1) ;}
    }
    return num ;
}

main()
{
    get_prime() ;
    while(scanf("%d%d",&n,&m)!=EOF)
    {
        n-- ; int num=solve() ;
        printf("%d\n",num) ;
        if(!num) printf("\n") ;
        int ct=0 ;
        for(int i=0;i<=n;i++) if(ans[i]) printf("%d%c",i+1,++ct==num ? '\n' : ' ') ;
    }
}
