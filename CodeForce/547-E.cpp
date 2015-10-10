#include<bits/stdc++.h>
using namespace std;
const int maxn=400000+10 ;

namespace PerST
{
    struct node
    {
        node *l,*r ;
        int val ;
        node(){l=r=NULL;val=0;}
        node(int _v){l=r=NULL;val=_v;}
    };

    node *build(int l,int r)
    {
        if(l==r) return new node() ;
        int mid=(l+r)/2 ;
        node *u=new node() ;
        u->l=build(l,mid) ;
        u->r=build(mid+1,r) ;
        return u ;
    }

    inline void pull(node *u){u->val=u->l->val+u->r->val;}

    node *modify(int L,int R,int pos,node *u)
    {
        if(L==R) return new node(u->val+1) ;
        node *v=new node() ;
        int mid=(L+R)/2 ;
        if(pos<=mid)
            v->l=modify(L,mid,pos,u->l) ,
            v->r=u->r ;
        else
            v->r=modify(mid+1,R,pos,u->r) ,
            v->l=u->l ;
        pull(v) ; return v ;
    }

    int query(int l,int r,int L,int R,node *u)
    {
        if(l==L&&r==R) return u->val ;
        int mid=(L+R)/2 ;
        if(r<=mid) return query(l,r,L,mid,u->l) ;
        else if(l>mid) return query(l,r,mid+1,R,u->r) ;
        else return query(l,mid,L,mid,u->l)+
                    query(mid+1,r,mid+1,R,u->r) ;
    }
}

using namespace PerST ;

namespace SufArr
{
    int n ;
    char s[maxn] ;
    int sa[maxn],rank[maxn],rank2[maxn],cnt[maxn],pri[maxn] ;
    int height[maxn] ;

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

    int comp_suffix(char *p,int x,int len)
    {
        return strncmp(p,s+sa[x],len) ;
    }

    void find(char *p,int len,int &low,int &upp)
    {
        int l=0 , r=n ;
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
    }
};

char s[maxn] ;
int pos[maxn] ; /// start position
int L[maxn],R[maxn] ;
node *root[maxn] ;
main()
{
    int n,Q,len=0 ; scanf("%d%d",&n,&Q) ;
    for(int i=0,j=0;i<n;i++)
    {
        scanf("%s",s+j) ; pos[i]=j ;
        while(s[j]) j++ ;
        if(i!=n-1) s[j++]='$' ;
        else pos[n]=j+1 , len=j ;
    }

    SufArr::init(s) ;
    SufArr::build_sa() ;
    for(int i=0;i<n;i++)
    {
        if(i!=n-1) s[pos[i+1]-1]=0 ;
        SufArr::find(s+pos[i],pos[i+1]-pos[i]-1,L[i],R[i]) ;
        R[i]-- ;
    }

    root[0]=build(0,len) ;
    for(int i=1;i<=len;i++)
        root[i]=modify(0,len,SufArr::sa[i],root[i-1]) ;

    while(Q--)
    {
        int l,r,k ; scanf("%d%d%d",&l,&r,&k) ;
        l-- ; r-- ; k-- ;
        int klen=pos[k+1]-pos[k]-1 ;
        int lo=pos[l] , hi=pos[r+1]-klen-1 ;
        if(hi<lo) printf("0\n") ;
        else printf("%d\n",query(lo,hi,0,len,root[R[k]]) -
                            query(lo,hi,0,len,root[L[k]-1])) ;
    }
}
