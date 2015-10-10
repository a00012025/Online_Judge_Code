#include<bits/stdc++.h>
using namespace std;
const int maxn=5000+10,maxm=5000+10 ;

struct SuffixArray
{
    char s[maxn] ;
    int n,sa[maxn],rank[maxn],pri[maxn],cnt[maxm] ;
    int rank2[maxn] ;
    int height[maxn] ;

    void build_sa(int m)
    {
        memset(cnt,0,sizeof(cnt)) ;
        for(int i=0;i<n;i++) cnt[rank[i]=s[i]]++ ;
        for(int i=1;i<m;i++) cnt[i]+=cnt[i-1] ;
        for(int i=n-1;i>=0;i--) sa[--cnt[rank[i]]]=i ;
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
            rank[sa[0]]=0 ; num=1 ;
            for(int i=1;i<n;i++)
                rank[sa[i]]= ((rank2[sa[i]]==rank2[sa[i-1]] && rank2[sa[i]+len]==rank2[sa[i-1]+len])
                            ? num-1 : num++ ) ;
            if(num>=n) break ;
            m=num ;
        }
    }

    void build_height()
    {
        int now=0 ;
        for(int i=0;i<n;i++)
        {
            if(now) now-- ;
            if(!rank[i]) continue ; /// i==n-1
            int j=sa[rank[i]-1] ;
            while(s[i+now]==s[j+now]) now++ ;
            height[rank[i]]=now ;
        }
    }
};

main()
{
    int T ; scanf("%d",&T) ;
    while(T--)
    {
        SuffixArray SA ;
        scanf("%s",SA.s) ;
        SA.n=strlen(SA.s)+1 ;
        SA.build_sa('z'+1) ;
        SA.build_height() ;
        int ans=-1 ;
        //for(int i=0;i<SA.n;i++) printf("%d,",SA.sa[i]) ; printf("\n") ;
        //for(int i=0;i<SA.n;i++) printf("%d,",SA.rank[i]) ; printf("\n") ;
        for(int i=1;i<SA.n;i++) if(SA.height[i]>ans) ans=SA.height[i] ; //printf("%d,",SA.height[i]) ; printf("\n") ;
        printf("%d\n",ans) ;
    }
}
