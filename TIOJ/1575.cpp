#include<bits/stdc++.h>
using namespace std;
const int maxn=1000000+10 ;

struct edge{
    int j;
    edge *next;
}*v[maxn],e[maxn*2],*ptr,*nowe;
void Set(int i,int j){
    static int ccnt=0;
    nowe=&e[ccnt++];
    ptr=v[i];
    v[i]=nowe;
    nowe->j=j;
    nowe->next=ptr;
}

int st[maxn] ;
int k ;
int dp[maxn],fa[maxn] ;

bool check(int num)
{
    int sz=1 ; st[0]=1 ; fa[1]=1 ;
    int cnt=0 ;
    while(sz)
    {
        int u=st[sz-1] ; sz-- ;
        if(u>0)
        {
            st[sz++]=-u ;
            for(edge *ptr=v[u];ptr;ptr=ptr->next)
                if(ptr->j!=fa[u])
                st[sz++]=ptr->j , fa[ptr->j]=u ;
            continue ;
        }
        u=-u ;
        int sup=0 , dem=-1 ;
        for(edge *ptr=v[u];ptr;ptr=ptr->next)
            if(ptr->j!=fa[u])
            sup=min(sup,dp[ptr->j]) , dem=max(dem,dp[ptr->j]) ;
        if(dem>=num-1)
        {
            if(++cnt > k) return 0 ;
            dp[u]=-num ;
        }
        else if(dem<0) dp[u]= sup<0 ? sup+1 : 0 ;
        else if(-sup-2>=dem) dp[u]=sup+1 ;
        else dp[u]=dem+1 ;
    }
    if(dp[1]>0 && ++cnt>k) return 0 ;
    return 1 ;
}

main()
{
    int n,m ; scanf("%d%d%d",&n,&m,&k) ;
    while(m--)
    {
        int x,y ; scanf("%d%d",&x,&y) ;
        Set(x,y) ;
        Set(y,x) ;
    }

    if(k==n) { printf("0\n") ; return 0 ; }
    if(k==0) { printf("%d\n",n-1) ; return 0 ; }
    int l=0 , r=n ;
    while(r-l>1)
    {
        int mid=(r+l)/2 ;
        if(check(mid)) r=mid ;
        else l=mid ;
    }
    printf("%d\n",r) ;
}
