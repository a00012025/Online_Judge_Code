#define NDEBUG
#ifdef NDEBUG
#define debugf(...) ((void)0)
#else
#define debugf(...) printf(__VA_ARGS__)
#endif // NDEBUG
#include<bits/stdc++.h>
using namespace std;
int n,m,a[2001],tmp[2001],dp[2001][2001] ;
int ST[2001][4094] ;

void modify(int tree,int l,int r,int L,int R,int id,int val)
{
    if(l==L && r==R) {ST[tree][id]=max(ST[tree][id],val) ; return ;}
    int mid=(L+R)/2 ;
    if(mid>=r) modify(tree,l,r,L,mid,2*id,val) ;
    else if(mid<l) modify(tree,l,r,mid+1,R,2*id+1,val) ;
    else
    {
        modify(tree,l,mid,L,mid,2*id,val) ;
        modify(tree,mid+1,r,mid+1,R,2*id+1,val) ;
    }
}

int query(int tree,int L,int R,int id,int x)
{
    if(L==R) return ST[tree][id] ;
    int mid=(L+R)/2 ;
    if(x<=mid) return max(ST[tree][id],query(tree,L,mid,2*id,x)) ;
    else return max(ST[tree][id],query(tree,mid+1,R,2*id+1,x)) ;
}

inline void insert(int tree,int len,int val)
{
    modify(tree,val,m,0,m,1,len) ;
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
    for(int i=1;i<=n;i++) a[i]=find(tmp,1,m,a[i]) ;
}

int get_int()
{
    char c=getchar() ;
    int x=0 ;
    while(c>'9' || c<'0') c=getchar() ;
    while(1)
    {
        x*=10 ;
        x+=c-'0' ;
        c=getchar() ;
        if(c>'9' || c<'0') break ;
    }
    return x ;
}

main()
{
        //freopen("pe.txt","r",stdin) ;
        //freopen("pe(me).txt","w",stdout) ;
    memset(ST,0,sizeof(ST)) ;
    int T ; T=get_int() ; int tc=0 ;
    while(T--)
    {
        n=get_int() ; tc++ ;
        for(int i=1;i<=n;i++) {a[i]=get_int() ; tmp[i]=a[i] ;}
        discrete() ;
        int ans=0 ;
        for(int i=0;i<=m;i++) modify(i,0,m,0,m,1,2000*tc) ;
        for(int i=0;i<=n;i++)
        {
            if(ans==n) break ;
            for(int j=i+1;j<=n;j++)
            {
                if(ans==n) break ;
                int id=a[j]-1 ;
                dp[i][j]=query(i,0,m,1,id)+1-2000*tc ; ans=max(ans,dp[i][j]) ;
                insert(i,dp[i][j]+2000*tc,a[j]) ;
                insert(j,dp[i][j]+2000*tc,a[i]) ;
            }
        }
        printf("%d\n",ans) ;
    }
}
