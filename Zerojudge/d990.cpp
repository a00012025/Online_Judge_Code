#include<bits/stdc++.h>
using namespace std;
const int maxn=100000+10 ;

char s[maxn] ;
int sa[maxn],rank[maxn],rank2[maxn],pri[maxn],cnt[maxn] ;
int n ;
struct SuffixArray
{
    void build_sa(int m)
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

    int comp_suffix(char *p,int x,int len)
    {
        return strncmp(p,s+sa[x],len) ;
    }

    int find(char *p,int len)
    {
        int l=0 , r=n , low , upp ;
        while(r-l>1)
        {
            int mid=(r+l)/2 ;
            if(comp_suffix(p,mid,len)>0) l=mid ;
            else r=mid ;
        }
        low=r ;
        l=0 , r=n ;
        while(r-l>1)
        {
            int mid=(r+l)/2 ;
            if(comp_suffix(p,mid,len)>=0) l=mid ;
            else r=mid ;
        }
        upp=r ;
        return upp-low ;
    }
};

char t[maxn] ;
main()
{
    scanf("%s",s) ;
    SuffixArray SA ;
    n=strlen(s)+1 ;
    SA.build_sa('z'+1) ;
    int T ; scanf("%d",&T) ;
    int ans=0 ;
    while(T--)
    {
        scanf("%s",t) ;
        int len=strlen(t) ;
        printf("%d\n",SA.find(t,len)) ;
    }
}
