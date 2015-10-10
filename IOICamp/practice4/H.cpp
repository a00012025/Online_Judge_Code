#include<stdio.h>
#include<string.h>
#define LL long long
using namespace std;
const int maxn=100000+10 ;

char s[maxn],u[maxn] ;
int sa[maxn] ;
int n,cnt[maxn],rank[maxn],rank2[maxn],pri[maxn] ;

struct SuffixArray
{
    void build_sa(int m)
    {
        memset(cnt,0,sizeof(cnt)) ;
        for(int i=0;i<n;i++) cnt[ rank[i]=s[i] ]++ ;
        for(int i=1;i<m;i++) cnt[i]+=cnt[i-1] ;
        for(int i=n-1;i>=0;i--) sa[--cnt[s[i]]]=i ;
        for(int len=1;len<=n;len*=2)
        {
            int num=0 ;
            for(int i=n-len;i<n;i++) pri[num++]=i ;
            for(int i=0;i<n;i++) if(sa[i]>=len) pri[num++]=sa[i]-len ;
            memset(cnt,0,sizeof(cnt)) ;
            for(int i=0;i<n;i++) cnt[ rank[pri[i]] ]++ ;
            for(int i=1;i<m;i++) cnt[i]+=cnt[i-1] ;
            for(int i=n-1;i>=0;i--) sa[--cnt[ rank[pri[i]] ]] = pri[i] ;
            for(int i=0;i<n;i++) rank2[i]=rank[i] ;
            num=0 ;
            for(int i=0;i<n;i++)
            {
                if(i && rank2[sa[i]]==rank2[sa[i-1]]
                    && rank2[sa[i]+len]==rank2[sa[i-1]+len])
                   rank[sa[i]]=num-1 ;
                else rank[sa[i]]=num++ ;
            }
            if(num>=n) break ;
            m=num ;
        }
    }

    int comp(char *t,int x,int L)
    {
        return strncmp(t,s+sa[x],L) ;
    }

    int lower_bound(char *t,int L)
    {
        if(comp(t,0,L)<=0) return 0 ;
        int l=0 , r=n ;
        while(r-l>1)
        {
            int mid=(r+l)/2 ;
            if(comp(t,mid,L)<=0) r=mid ;
            else l=mid ;
        }
        return r ;
    }

    int upper_bound(char *t,int L)
    {
        if(comp(t,0,L)<0) return 0 ;
        int l=0 , r=n ;
        while(r-l>1)
        {
            int mid=(r+l)/2 ;
            if(comp(t,mid,L)<0) r=mid ;
            else l=mid ;
        }
        return r ;
    }
}SA;

vector<int> v ;
main()
{
    int T ; scanf("%d",&T) ;
    while(T--)
    {
        scanf("%s%s",s,u) ;
        n=strlen(s)+1 ;
        SA.build_sa('z'+1) ;

        int L=strlen(u) ;
        int l=SA.lower_bound(u,L) , r=SA.upper_bound(u,L) ;

//        for(int i=0;i<n;i++) printf("suffix : %s\n",s+sa[i]) ;
//        printf("l=%d , r=%d\n",l,r) ;

        v.clear() ;
        for(int i=l;i<r;i++) v.push_back(sa[i]) ;
        sort(v.begin(),v.end()) ;

        LL ans=0LL ;

        int now=0 ;
        for(int i=1;i<l;i++)
        {
            while(s[sa[i]+now]==u[now]) now++ ;
            int le=sa[i]+now ;
        }
        now=0 ;
        for(int i=n-1;i>=r;i--)
        {
            while(s[sa[i]+now]==u[now]) now++ ;
            ans+=n-1-sa[i]-now ;
        }
        printf("%lld\n",ans) ;
    }
}
