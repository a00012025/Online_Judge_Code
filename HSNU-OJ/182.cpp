#include<stdio.h>
#include<string.h>
using namespace std;
const int maxn=300000+10 ;

char s[maxn] ;
int n,sa[maxn],rank[maxn],pri[maxn],cnt[maxn],rank2[maxn] ;

struct SuffixArray
{
    void build(int m)
    {
        memset(cnt,0,sizeof(cnt)) ;
        for(int i=0;i<n;i++) cnt[ rank[i]=s[i] ]++ ;
        for(int i=1;i<m;i++) cnt[i]+=cnt[i-1] ;
        for(int i=n-1;i>=0;i--) sa[ --cnt[s[i]] ]= i ;
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
            num=0 ;
            rank[sa[0]]=num++ ;
            for(int i=1;i<n;i++) rank[sa[i]]=
                (rank2[sa[i-1]]==rank2[sa[i]] && rank2[sa[i-1]+len]==rank2[sa[i]+len])
                    ? num-1 : num++ ;
            if(num>=n) break ;
            m=num ;
        }
    }

    int lower_bound(int len,char *t)
    {
        int l=0 , r=n ;
        while(r-l>1)
        {
            int mid=(r+l)/2 ;
            if(strncmp(s+sa[mid],t,len)>=0) r=mid ;
            else l=mid ;
        }
        return r ;
    }
    int upper_bound(int len,char *t)
    {
        int l=0 , r=n ;
        while(r-l>1)
        {
            int mid=(r+l)/2 ;
            if(strncmp(s+sa[mid],t,len)>0) r=mid ;
            else l=mid ;
        }
        return r ;
    }
}SA;

char t[6000] ;
int ST[8*maxn] ;
bool tag[8*maxn] ;
void modify(int l,int r,int L,int R,int id)
{
    if(l==L && r==R){ ST[id]=R-L+1 ; tag[id]=1 ; return ; }
    int mid=(L+R)/2 ;
    if(tag[id]) return ;
    if(r<=mid) modify(l,r,L,mid,2*id) ;
    else if(l>mid) modify(l,r,mid+1,R,2*id+1) ;
    else
    {
        modify(l,mid,L,mid,2*id) ;
        modify(mid+1,r,mid+1,R,2*id+1) ;
    }
    ST[id]=ST[2*id]+ST[2*id+1] ;
}

main()
{
    scanf("%d%s",&n,s) ; n++ ;
    SA.build('z'+1) ;
    memset(tag,0,sizeof(tag)) ;
    int Q ; scanf("%d",&Q) ;
    while(Q--)
    {
        scanf("%s",t) ;
        int len=strlen(t) ;
        int lo=SA.lower_bound(len,t) , hi=SA.upper_bound(len,t) ;
        for(int i=lo;i<hi;i++)
            modify(sa[i],sa[i]+len-1,0,n-1,1) ;
    }
    printf("%d\n",n-1-ST[1]) ;
}
