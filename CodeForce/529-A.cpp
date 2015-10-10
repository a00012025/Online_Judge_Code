#include<bits/stdc++.h>
using namespace std;
const int maxn=2000000+10 ;

char s[maxn] ;
int sa[maxn],Rank[maxn],rank2[maxn],cnt[maxn],pri[maxn] ;

struct SuffixArray
{
    int n ;
    void build_sa(int m)
    {
        memset(cnt,0,sizeof(cnt)) ;
        for(int i=0;i<n;i++) cnt[Rank[i]=s[i]]++ ;
        for(int i=1;i<m;i++) cnt[i]+=cnt[i-1] ;
        for(int i=n-1;i>=0;i--) sa[--cnt[s[i]]]=i ;
        for(int len=1;len<=n;len*=2)
        {
            int num=0 ;
            for(int i=n-len;i<n;i++) pri[num++]=i ;
            for(int i=0;i<n;i++) if(sa[i]>=len) pri[num++]=sa[i]-len ;
            memset(cnt,0,sizeof(cnt)) ;
            for(int i=0;i<n;i++) cnt[Rank[i]]++ ;
            for(int i=1;i<m;i++) cnt[i]+=cnt[i-1] ;
            for(int i=n-1;i>=0;i--) sa[ --cnt[Rank[pri[i]]]]=pri[i] ;
            for(int i=0;i<n;i++) rank2[i]=Rank[i] ;
            num=1 ; Rank[sa[0]]=0 ;
            for(int i=1;i<n;i++) Rank[sa[i]]=
            ((rank2[sa[i]]==rank2[sa[i-1]] &&
              rank2[sa[i]+len]==rank2[sa[i-1]+len])
                ? num-1 : num++) ;
            if(num>=n) break ;
            m=num ;
        }
    }
};

multiset<int> st ;
int sum[maxn] ;
bool cant[maxn] ;
main()
{
    SuffixArray SA ;
    scanf("%s",s) ;
    int n=strlen(s) ;
    for(int i=n;i<2*n;i++) s[i]=s[i-n] ;
    SA.n=2*n+1 ;
    SA.build_sa(128) ;

    for(int i=1;i<=2*n;i++) sum[i]=sum[i-1]+(s[i-1]=='('?1:-1) ;
    int add=-sum[n] ;
    for(int i=1;i<=2*n;i++)
    {
        st.insert(sum[i]) ;
        if(i<n) continue ;
        int val=*st.begin()-sum[i-n] ;
        if(val<-max(add,0)) cant[i-n]=1 ;
        st.erase(st.find(sum[i-n+1])) ;
    }

    for(int i=0;;i++) if(0<=sa[i] && sa[i]<n && !cant[sa[i]])
    {
        while(add>0) printf("(") , add-- ;
        for(int j=sa[i];j<sa[i]+n;j++) printf("%c",s[j]) ;
        while(add<0) printf(")") , add++ ;
        printf("\n") ;
        return 0 ;
    }
}
