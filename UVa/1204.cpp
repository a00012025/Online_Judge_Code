#include<stdio.h>
#include<string.h>
#include<algorithm>
using namespace std;

char a[20][200] ;
int n ;

bool contain(const char *u,const char *v)
{
    int l1=strlen(u) , l2=strlen(v) ;
    if(l1<l2) return 0 ;
    for(int i=0;i+l2-1<l1;i++)
    {
        bool yes=1 ;
        for(int j=0;j<l2;j++) if(u[i+j]!=v[j]) {yes=0 ; break ;}
        if(yes) return 1 ;
    }
    return 0 ;
}

int paste(const char *u,const char *v,int type)
{
    int l1=strlen(u) , l2=strlen(v) ;
    int i ;
    for(i=0;i<l1;i++)
    {
        bool no=0 ;
        for(int j=0;j<l2;j++) if(i+j<l1 && v[j]!=u[i+j]) {no=1 ; break ;}
        if(type==1 && i==0) continue ;
        if(!no) break ;
    }
    return l1-i ;
}

void reverse_string(char *v)
{
    int len=strlen(v) ;
    char u[200] ;
    for(int i=len-1;i>=0;i--) u[i]=v[len-1-i] ;
    for(int i=0;i<=len-1;i++) v[i]=u[i] ;
}

void delete_contained()
{
    bool ok[20] ;
    for(int i=0;i<n;i++) ok[i]=1 ;
    for(int i=0;i<n;i++) for(int j=0;j<n;j++) if(i!=j)
    {
        char u[200],v[200] ;
        int l1=strlen(a[i]) , l2=strlen(a[j]) ;
        for(int k=0;k<l1;k++) u[k]=a[i][k] ; u[l1]='\0' ;
        for(int k=0;k<l2;k++) v[k]=a[j][k] ; v[l2]='\0' ;
        if(contain(u,v)) ok[j]=0 ;
        reverse_string(u) ;
        if(contain(u,v)) ok[j]=0 ;
    }
    int cnt=0 ;
    for(int i=0;i<n;i++) if(ok[i])
    {
        if(cnt==i) {cnt++ ; continue ;}
        int l=strlen(a[i]) ;
        for(int j=0;j<l;j++) a[cnt][j]=a[i][j] ;
        a[cnt][l]='\0' ;
        cnt++ ;
    }
    n=cnt ;
}

int pas[40][40] ;
char a_rev[20][200] ;
void find_paste_num()
{
    for(int i=0;i<n;i++)
    {
        int l=strlen(a[i]) ;
        for(int j=0;j<=l;j++) a_rev[i][j]=a[i][j] ;
        reverse_string(a_rev[i]) ;
    }
    for(int i=0;i<n;i++) for(int j=0;j<n;j++)
    {
        pas[i][j]=paste(a[i],a[j],0) ;
        pas[i][j+n]=paste(a[i],a_rev[j],0) ;
        pas[i+n][j]=paste(a_rev[i],a[j],0) ;
        pas[i+n][j+n]=paste(a_rev[i],a_rev[j],0) ;
        //printf("pas[%d][%d]=%d\n",i+n,j,pas[i+n][j]) ;
    }
    pas[0][0]=paste(a[0],a[0],1) ;
}

int bit_cnt(int x)
{
    if(!x) return 0 ;
    return x%2 ? 1+bit_cnt(x/2) : bit_cnt(x/2) ;
}

int dp[1<<17][40],len[32] ;
const int INF=1000000000 ;
main()
{
    while(scanf("%d",&n)==1 && n)
    {
        for(int i=0;i<n;i++) scanf("%s",a[i]) ;
        delete_contained() ;
        find_paste_num() ;
        for(int i=0;i<n;i++) len[i]=len[i+n]=strlen(a[i]) ;

        for(int i=0;i<(1<<n);i++) for(int j=0;j<2*n;j++) dp[i][j]=INF ;
        dp[1][0]=len[0] ;

        for(int i=0;i<(1<<n);i++) if(bit_cnt(i)>1)
        for(int j=0;j<2*n;j++)
        {
            int last= j<n ? j : j-n ;
            if((i & (1<<last))==0) continue ;
            for(int k=0;k<n;k++) if((i & (1<<k))!=0 && k!=last)
            {
                int &ans=dp[i][j] ;
                int l=len[last] ;
                ans=min(ans,dp[i-(1<<last)][k]+l-pas[k][j]) ;
                ans=min(ans,dp[i-(1<<last)][n+k]+l-pas[n+k][j]) ;
            }
            //printf("dp[%d][%d]=%d\n",i,j,dp[i][j]) ;
        }

        int ans=INF ;
        for(int j=0;j<2*n;j++) if(dp[(1<<n)-1][j]!=INF)
            ans=min(ans,dp[(1<<n)-1][j]-pas[j][0]) ;
        if(ans<=1) ans=2 ;
        printf("%d\n",ans);
    }
}
