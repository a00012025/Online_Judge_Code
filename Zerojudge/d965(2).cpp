#define NDEBUG
#ifdef NDEBUG
#define debugf(...) ((void)0)
#else
#define debugf(...) printf(__VA_ARGS__)
#endif // NDEBUG
#include<bits/stdc++.h>
using namespace std;
int n,m,a[2001],tmp[2001],dp[2001][2001] ;
int ST[20000],tag[20000] ;

void modify(int l,int r,int L,int R,int id,int val)
{
    if(l==L && r==R) {ST[id]=max(ST[id],val) ; return ;}
    int mid=(L+R)/2 ;
    if(mid>=r) modify(l,r,L,mid,2*id,val) ;
    else if(mid<l) modify(l,r,mid+1,R,2*id+1,val) ;
    else
    {
        modify(l,mid,L,mid,2*id,val) ;
        modify(mid+1,r,mid+1,R,2*id+1,val) ;
    }
}

int query(int L,int R,int id,int x)
{
    if(L==R) return ST[id] ;
    int mid=(L+R)/2 ;
    if(x<=mid) return max(ST[id],query(L,mid,2*id,x)) ;
    else return max(ST[id],query(mid+1,R,2*id+1,x)) ;
}

inline void insert(int len,int val)
{
    modify(val,m,0,m,1,len) ;
}

int find(int *arr,int L,int R,int x)
{
    if(arr[L]>=x) return L ;
    int l=L , r=R ;
    while(r-l>1)
    {
        int mid=(r+l)/2 ;
        if(arr[mid]>=x) r=mid ;
        else l=mid ;
    }
    return r ;
}

void discrete()
{
    tmp[0]=0 ;
    sort(tmp+1,tmp+n+1) ;
    m=unique(tmp+1,tmp+n+1)-tmp-1 ; /// tmp : 1 ~ m
    for(int i=1;i<=m;i++) debugf("%d%c",tmp[i],i==m?'\n':' ') ;
    for(int i=1;i<=n;i++) a[i]=find(tmp,1,m,a[i]) ;
}

main()
{
        freopen("pe.txt","r",stdin) ;
        //freopen("pe(me).txt","w",stdout) ;
    int T ;scanf("%d",&T) ;
    while(T--)
    {
        scanf("%d",&n) ;
        for(int i=1;i<=n;i++) {scanf("%d",&a[i]) ; tmp[i]=a[i] ;}
        discrete() ; for(int i=1;i<=n;i++) debugf("%d%c",a[i],i==n?'\n':' ') ;
        int ans=0 ;
        for(int i=0;i<=n;i++)
        {
            if(ans==n) break ;
            memset(ST,0,sizeof(ST)) ;
            for(int j=0;j<i;j++) insert(dp[j][i],a[j]) ;
            for(int j=i+1;j<=n;j++)
            {
                if(ans==n) break ;
                int id=a[j]-1 ;
                dp[i][j]=query(0,m,1,id)+1 ; ans=max(ans,dp[i][j]) ;
                insert(dp[i][j],a[j]) ;
            }
        }
        printf("%d\n",ans) ;
    }
}

