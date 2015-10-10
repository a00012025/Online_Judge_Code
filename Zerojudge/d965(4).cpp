#define NDEBUG
#ifdef NDEBUG
#define debugf(...) ((void)0)
#else
#define debugf(...) printf(__VA_ARGS__)
#endif // NDEBUG
#include<bits/stdc++.h>
#define lowbit(x) (x&(-x))
using namespace std;
int n,m,a[2001],tmp[2001],dp[2001][2001] ;
int bit[2001][4094] ;

int query(int tree,int val)
{
    return !val ? 0 : max(bit[tree][val],query(tree,val-lowbit(val))) ;
}

void insert(int tree,int val,int len)
{
    if(!val) return ;
    while(val<=n)
    {
        bit[tree][val]=max(bit[tree][val],len) ;
        val += lowbit(val) ;
    }
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
    for(int i=0;i<=m;i++) debugf("%d%c",tmp[i],i==m?'\n':' ');
    a[0]=1 ;
    for(int i=1;i<=n;i++) a[i]=find(tmp,0,m,a[i])+1 ;
    debugf("a : ") ;
    for(int i=0;i<=n;i++) debugf("%d%c",a[i],i==n?'\n':' ') ;
}

main()
{
        //freopen("pe.txt","r",stdin) ;
        //freopen("pe(me).txt","w",stdout) ;
    int T ; scanf("%d",&T) ; int tc=0 ;
    while(T--)
    {
        scanf("%d",&n) ;
        for(int i=1;i<=n;i++) {scanf("%d",&a[i]) ; tmp[i]=a[i] ;}
        for(int i=0;i<=n;i++) for(int j=0;j<=n;j++) bit[i][j]=0 ;
        discrete() ;
        int ans=0 ;

        for(int i=1;i<=n;i++) for(int j=0;j<i;j++)
        {
            int len=query(j,a[i]-1)+1 ;
            insert(j,a[i],len) ;
            insert(i,a[j],len) ;
            ans=max(ans,len) ;
        }
        printf("%d\n",ans) ;
    }
}
