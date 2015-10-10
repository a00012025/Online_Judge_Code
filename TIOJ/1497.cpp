#include<bits/stdc++.h>
const int maxn=100000+10 ;

char s[maxn] ;
int rank[maxn],sa[maxn],cnt[maxn],pri[maxn],rank2[maxn] ;

struct SuffixArray
{
    int n ;
    void build_SA(int m)
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
            for(int i=n-1;i>=0;i--) sa[ --cnt[rank[pri[i]]]]=pri[i] ;

            for(int i=0;i<n;i++) rank2[i]=rank[i] ;
            num=1 ; rank[sa[0]]=0 ;
            for(int i=1;i<n;i++)
                rank[sa[i]]= ((rank2[sa[i]]==rank2[sa[i-1]] && rank2[sa[i]+len]==rank2[sa[i-1]+len])
                    ? num-1 : num++) ;
            if(num>=n) break ;
            m=num ;
        }
    }
}SA;

main()
{
    gets(s) ;
    SA.n=strlen(s)+1 ;
    SA.build_SA('z'+1) ;
    for(int i=1;i<SA.n;i++) printf("%d\n",sa[i]) ;
}
