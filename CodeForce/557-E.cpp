#include<bits/stdc++.h>
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

    bool build_h=0 ;
    int log_t[maxn] , *rmq[LOG] ;
    void build_height(bool buildrmq=1)
    {
        int now=0 ;
        for(int i=0;i<n;i++)
        {
            if(now) now-- ;
            if(!rank[i]) continue ;
            while(s[ sa[rank[i]]+now ]==s[ sa[rank[i]-1]+now ]) now++ ;
            height[rank[i]]=now ;
        }
        build_h=1 ;
        if(!buildrmq) return ;

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
        if(!build_h) build_height() ;
        x=rank[x] ; y=rank[y] ;
        if(x>y) swap(x,y) ;
        if(x==y) return n-sa[x]-1 ;
        x++ ;
        int t=log_t[y-x+1] ;
        return min(rmq[t][x],rmq[t][y-(1<<t)+1]) ;
    }
};

int num[maxn][maxn] ;
int getnum(char *s)
{
    int len=strlen(s) , ret=0 ;
    int l=SufArr::lower_bound(s,len) ;
    int r=SufArr::upper_bound(s,len) ;
    for(int i=l;i<r;i++)
    {
        int x=SufArr::sa[i] ;
        ret+=num[x][x+len-1] ;
    }
//    printf("%s : %d\n",s,ret) ;
    return ret ;
}

bool check(char *t)
{
//    printf("%s : ",t) ;
    int n=strlen(t) ;
    for(int i=0;n-1-i>=i;i+=2) if(t[i]!=t[n-1-i])
        return 0 ;
    return 1 ;
}
char s[maxn],ans[maxn] ;
main()
{
    int k ; scanf("%s%d",s,&k) ;
    SufArr::init(s) ;
    SufArr::build_sa() ;
    int n=strlen(s) ;
    for(int i=0;i<2*n-1;i++)
    {
        int x=i/2 , y=i-x ;
        for(int j=1;x-j+1>=0 && y+j-1<n && s[x-j+1]==s[y+j-1];j+=2)
            num[x-j+1][y+j-1]=1 ;
        for(int j=2;x-j+1>=0 && y+j-1<n && s[x-j+1]==s[y+j-1];j+=2)
            num[x-j+1][y+j-1]=1 ;
    }
    for(int i=0;i<n;i++) for(int j=n-1;j>=i;j--)
        num[i][j]+=num[i][j+1] ;
    for(int i=0,last=0;;i++)
    {
        if(k<=last){printf("%s\n",ans) ; return 0 ;}
        k-=last ;
        int num1,num2 ;
        ans[i]='a' ; num1=getnum(ans) ;
        ans[i]='b' ; num2=getnum(ans) ;
        if(k>num1) k-=num1 ;
        else ans[i]='a' ;
        last=(check(ans) ? SufArr::find(ans,i+1) : 0) ;
    }
}
