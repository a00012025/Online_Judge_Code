#include<stdio.h>
#include<string.h>
#include<string>
#include<algorithm>
#include<iostream>
using namespace std;

int n ;
struct item
{
    string s,rev ;
    bool operator < (const item &rhs) const
    {
        return s.size()<rhs.s.size() ;
    }
}a[20];

bool contain(const string &u,const string &v)
{
    //return u.find(v) != string::npos ;
    int l1=u.size() , l2=v.size() ;
    if(l1<l2) return 0 ;
    for(int i=0;i+l2-1<l1;i++)
    {
        bool yes=1 ;
        for(int j=0;j<l2;j++) if(u[i+j]!=v[j]) {yes=0 ; break ;}
        if(yes) return 1 ;
    }
    return 0 ;
}

int paste(const string &u,const string &v)
{
    int l1=u.size() , l2=v.size() ;
    for(int i=1;i<l1;i++)
    {
        bool yes=1 ;
        for(int j=0;i+j<l1;j++) if(i+j<l1 && v[j]!=u[i+j]) {yes=0 ; break ;}
        if(yes) return l1-i ;
    }
    return 0 ;
}

void delete_contained()
{
    bool ok[20] ;
    for(int i=0;i<n;i++) ok[i]=1 ;
    sort(a,a+n) ;
    for(int i=0;i<n;i++) for(int j=i+1;j<n;j++)
    {
        if(contain(a[j].s,a[i].s)) ok[i]=0 ;
        if(contain(a[j].rev,a[i].s)) ok[i]=0 ;
    }
    int cnt=0 ;
    for(int i=0;i<n;i++) if(ok[i])
    {
        if(cnt==i) {cnt++ ; continue ;}
        a[cnt].s=a[i].s ; a[cnt].rev=a[i].rev ;cnt++ ;
    }
    n=cnt ;
}

int pas[40][40] ;
void find_paste_num()
{
    for(int i=0;i<n;i++) for(int j=0;j<n;j++)
    {
        pas[i][j]=paste(a[i].s,a[j].s) ;
        pas[i][j+n]=paste(a[i].s,a[j].rev) ;
        pas[i+n][j]=paste(a[i].rev,a[j].s) ;
        pas[i+n][j+n]=paste(a[i].rev,a[j].rev) ;
        //printf("pas[%d][%d]=%d\n",i,j,pas[i][j]) ;
    }
    //cout << a[0].s << endl ;
    //printf("%d\n",pas[0][0]) ;
}

int bit_cnt(int x)
{
    if(!x) return 0 ;
    return x%2 ? 1+bit_cnt(x/2) : bit_cnt(x/2) ;
}

void update_ans(int &x,int val)
{
    if(x<0 || x>val) x=val ;
}

int dp[1<<17][40],len[32] ;
const int INF=1000000000 ;
main()
{
    char ss[200] ;
    while(scanf("%d",&n)==1 && n)
    {
        for(int i=0;i<n;i++)
        {
            cin >> a[i].s ;
            a[i].rev=a[i].s ;
            reverse(a[i].rev.begin(),a[i].rev.end()) ;
        }
        delete_contained() ;
        find_paste_num() ;
        for(int i=0;i<n;i++) len[i]=len[i+n]=a[i].s.size() ;

        for(int i=0;i<(1<<n);i++) for(int j=0;j<2*n;j++)
            dp[i][j]=INF ;
        dp[1][0]=len[0] ;

        for(int i=1;i<(1<<n);i++) for(int j=0;j<2*n;j++) if(bit_cnt(i)>1)
        {
            int last=j<n ? j : j-n ;
            if(!(i&(1<<last))) continue ;
            int &ans=dp[i][j] ;
            for(int k=0;k<n;k++) if((i&(1<<k)) && k!=last)
            {
                ans=min(ans,dp[i-(1<<last)][k]+len[last]-pas[k][j]) ;
                ans=min(ans,dp[i-(1<<last)][n+k]+len[last]-pas[n+k][j]) ;
            }
            //printf("dp[%d][%d]=%d\n",i,j,dp[i][j]) ;
        }

        int ans=INF ;
        for(int j=0;j<2*n;j++)
            ans=min(ans,dp[(1<<n)-1][j]-pas[j][0]) ;
        if(ans<=1) ans=2 ;
        printf("%d\n",ans);
    }
}
