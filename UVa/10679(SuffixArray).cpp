#include<bits/stdc++.h>
using namespace std;

const int maxn=100000 + 10;

struct SuffixArray
{
    char s[maxn] ;
    int sa[maxn] ;
    int n,cnt[maxn],rank[maxn],rank2[maxn],pri[maxn] ;

    void build_sa(int m)
    {
        memset(cnt,0,sizeof(cnt)) ;
        for(int i=0;i<n;i++) cnt[rank[i]=s[i]]++ ;
        for(int i=1;i<m;i++) cnt[i]+=cnt[i-1] ;
        for(int i=n-1;i>=0;i--) sa[--cnt[s[i]]]=i ;
        for(int len=1;len<=n;len*=2)
        {
            int num=0 ;
            for(int i=n-len;i<n;i++) pri[num++]=i ;
            for(int i=0;i<n;i++) if(sa[i]>=len) pri[num++]=sa[i]-len ;
            memset(cnt,0,sizeof(cnt)) ;
            for(int i=0;i<n;i++) cnt[rank[i]]++ ;
            for(int i=1;i<m;i++) cnt[i]+=cnt[i-1] ;
            for(int i=n-1;i>=0;i--) sa[--cnt[rank[pri[i]]]]=pri[i] ;
            for(int i=0;i<n;i++) rank2[i]=rank[i] ;
            num=1 ; rank[sa[0]]=0 ;
            for(int i=1;i<n;i++) rank[sa[i]]=
                (rank2[sa[i]]==rank2[sa[i-1]] &&
                rank2[sa[i]+len]==rank2[sa[i-1]+len])
                ? num-1 : num++ ;
            if(num>=n) break ;
            m=num ;
        }
    }

    int comp(char *t,int x)
    {
        return strcmp(t,s+sa[x]) ;
    }

    int find(char *t)
    {
        if(comp(t,0)<0) return 0;
        if(comp(t,n-1)>0) return 0;
        int l=0 , r=n-1 ;
        while(r-l>1)
        {
            int mid=(r+l)/2 ;
            int res=comp(t,mid) ;
            if(res==0) return 1;
            else if(res<0) r=mid ;
            else l=mid ;
        }
        if(comp(t,l)==0 || comp(t,r)==0) return 1 ;
        return 0 ;
    }
};

char t[maxn] ;
main()
{
    int T ; scanf("%d",&T) ;
    while(T--)
    {
        SuffixArray SA ;
        scanf("%s",SA.s) ;
        SA.n=strlen(SA.s)+1 ;
        SA.build_sa('z'+1) ;
        int Q ; scanf("%d",&Q) ;
        while(Q--)
        {
            scanf("%s",t) ;
            if(SA.find(t)) printf("y\n") ;
            else printf("n\n") ;
        }
    }
}
