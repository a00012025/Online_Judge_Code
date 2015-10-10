#include<bits/stdc++.h>
#define MOD 1000000007
using namespace std;
const int maxn=5000+10 ;

namespace SufArr
{
    int n ;
    char s[maxn] ;
    int sa[maxn],rank[maxn],rank2[maxn],cnt[maxn],pri[maxn] ;
    int height[maxn] ;
    const int LOG=(int)(log2(maxn)+1) ;

    void init(char *_s)
    {
        n=strlen(_s)+1 ;
        for(int i=0;i<n;i++) s[i]=_s[i] ;
    }

    void build_sa(int m='z'+1)
    {
        for(int i=0;i<m;i++) cnt[i]=0 ;
        for(int i=0;i<n;i++) cnt[rank[i]=s[i]]++ ;
        for(int i=1;i<m;i++) cnt[i]+=cnt[i-1] ;
        for(int i=n-1;i>=0;i--) sa[--cnt[s[i]]]=i ;
        for(int len=1;len<=n;len*=2)
        {
            int num=0 ;
            for(int i=n-len;i<n;i++) pri[num++]=i ;
            for(int i=0;i<n;i++) if(sa[i]>=len) pri[num++]=sa[i]-len ;
            for(int i=0;i<m;i++) cnt[i]=0 ;
            for(int i=0;i<n;i++) cnt[rank[i]]++ ;
            for(int i=1;i<m;i++) cnt[i]+=cnt[i-1] ;
            for(int i=n-1;i>=0;i--) sa[--cnt[rank[pri[i]]]]=pri[i] ;
            for(int i=0;i<n;i++) rank2[i]=rank[i] ;
            rank[sa[0]]=0 ; num=1 ;
            for(int i=1;i<n;i++) rank[sa[i]]=
                (rank2[sa[i]]==rank2[sa[i-1]] &&
                rank2[sa[i]+len]==rank2[sa[i-1]+len])
                ? num-1 : num++ ;
            if(num>=n) break ;
            m=num ;
        }
    }

    int log_t[maxn] , *rmq[LOG] ;
    void build_lcp()
    {
        int now=0 ;
        for(int i=0;i<n;i++)
        {
            if(now) now-- ;
            if(!rank[i]) continue ;
            while(s[ sa[rank[i]]+now ]==s[ sa[rank[i]-1]+now ]) now++ ;
            height[rank[i]]=now ;
        }

        log_t[0]=log_t[1]=0 ;
        for(int i=2;i<=n;i++) log_t[i]=log_t[i/2]+1 ;
        for(int i=0;(1<<i)<=n;i++) rmq[i]=new int[n+1] ;
        for(int i=0;(1<<i)<=n;i++) for(int j=0;j+(1<<i)-1<=n;j++)
            rmq[i][j]=(i ?
            min(rmq[i-1][j],rmq[i-1][j+(1<<(i-1))]) :
            height[j]) ;
    }

    int comp_suffix(char *p,int x,int len)
    {
        return strncmp(p,s+sa[x],len) ;
    }

    int lower_bound(char *p,int len)
    {
        int l=0 , r=n ;
        while(r-l>1)
        {
            int mid=(r+l)/2 ;
            if(comp_suffix(p,mid,len)>0) l=mid ;
            else r=mid ;
        }
        return r ;
    }

    int upper_bound(char *p,int len)
    {
        int l=0 , r=n ;
        while(r-l>1)
        {
            int mid=(r+l)/2 ;
            if(comp_suffix(p,mid,len)>=0) l=mid ;
            else r=mid ;
        }
        return r ;
    }

    int find(char *p,int len)
    {
        return upper_bound(p,len)-lower_bound(p,len) ;
    }

    int LCP(int x,int y)
    {
        x=rank[x] ; y=rank[y] ;
        if(x>y) swap(x,y) ;
        if(x==y) return n-sa[x]-1 ;
        x++ ;
        int t=log_t[y-x+1] ;
        return min(rmq[t][x],rmq[t][y-(1<<t)+1]) ;
    }
};

struct P{int val,ways;};
inline P cal(const P &a,const P &b)
{
    return (P){min(a.val,b.val),(a.ways+b.ways)%MOD} ;
}

inline void upd(P &a,const P &b)
{
    a=cal(a,b) ;
}

P dp[maxn][maxn] ;
char s[maxn] ;
main()
{
    int n ; scanf("%s",s) ;
    n=strlen(s) ;
    SufArr::init(s) ;
    SufArr::build_sa() ;
    SufArr::build_lcp() ;
    for(int i=1;i<n;i++) for(int j=i;j<n;j++)
        dp[i][j].val=maxn ;
    for(int i=0;i<n;i++) for(int j=i;j<n;j++)
    {
        if(i==0) dp[i][j]=(P){1,1} ;
        else if(j>i) upd(dp[i][j],dp[i][j-1]) ;
        if(dp[i][j].val==maxn || j==n-1 || s[j+1]=='0') continue ;
        if(2*j+1-i >= n) continue ;

        int len=min(SufArr::LCP(i,j+1),j-i+1) ;
        P ndp=(P){dp[i][j].val+1,dp[i][j].ways} ;
        if(len==j-i+1) upd(dp[j+1][j+len],ndp) ;
        else if(s[i+len]<s[j+len+1])
            upd(dp[j+1][2*j+1-i],ndp) ;
        else if(2*j+2-i<n)
            upd(dp[j+1][2*j+2-i],ndp) ;
    }

    int ways=0 ;
    for(int i=0;i<n;i++) ways=(ways+dp[i][n-1].ways)%MOD ;
    printf("%d\n",ways) ;

    int val=-1 ;
    for(int i=n-1;i>=n-20 && i>=0;i--)
        if(dp[i][n-1].val!=maxn)
    {
        int nval=0 ;
        for(int j=i;j<n;j++) nval=2*nval+s[j]-'0' ;
        nval+=dp[i][n-1].val ;
        val=(val==-1 ? nval : min(val,nval)) ;
    }

    if(val!=-1){printf("%d\n",val) ; return 0 ;}

    for(int i=n-21;i>=0;i--)
        if(dp[i][n-1].val!=maxn)
    {
        val=0 ;
        for(int j=i;j<n;j++) val=(2*val+s[j]-'0')%MOD ;
        val=(val+dp[i][n-1].val)%MOD ;
        printf("%d\n",val) ; return 0 ;
    }
}
