#define NDEBUG
#ifdef NDEBUG
#define debugf(...) ((void)0)
#else
#define debugf(...) printf(__VA_ARGS__)
#endif // NDEBUG
#include<bits/stdc++.h>
#define LL long long
using namespace std;
const int maxn=1000000 + 50 ;

LL X ;
int C,a[maxn],n ;
int ST[5*maxn] ;

void build(int l,int r,int id)
{
    ST[id]=r-l+1 ;
    if(l==r) return ;
    int mid=(l+r)/2 ;
    build(l,mid,2*id) ;
    build(mid+1,r,2*id+1) ;
}

int query(int k,int l,int r,int id)
{
    if(l==r) return l ;
    int mid=(l+r)/2 ;
    if(k<=ST[2*id]) return query(k,l,mid,2*id) ;
    else return query(k-ST[2*id],mid+1,r,2*id+1) ;
}

void modify(int l,int r,int id,int pos,int val)
{
    if(l==r) {ST[id]+=val ; return ; }
    int mid=(l+r)/2 ;
    if(pos<=mid) modify(l,mid,2*id,pos,val) ;
    else modify(mid+1,r,2*id+1,pos,val) ;
    ST[id]=ST[2*id]+ST[2*id+1] ;
}

int last[maxn],nex[maxn] ;
set<int> st ;
main()
{
    int T ; scanf("%d",&T) ;
    while(T--)
    {
        int M,A,B ;
        scanf("%d%d%lld%d%d",&n,&M,&X,&A,&B) ;
        build(1,n,1) ;

        for(int i=1;i<=n;i++)
        {
            X=(X*A+B)%M ; C=1+(X+n-i)%(n-i+1) ;
            int nv=query(C,1,n,1) ;
            a[i]=nv ;
            modify(1,n,1,nv,-1) ;
        }
        debugf("a : ") ;
        for(int i=1;i<=n;i++) debugf("%d%c",a[i],i==n?'\n':' ') ;
        for(int i=1;i<=n;i++)
            { last[i]= (i==1 ? n : i-1) ; nex[i]= (i==n ? 1 : i+1) ; }
        st.clear() ; for(int i=1;i<=n;i++) if(a[nex[i]]>a[i]) st.insert(i) ;
        int now=n ;
        LL ANS=0LL ;
        for(int i=1;i<=n;i++)
        {
            now=nex[now] ;
            if(i==n) { ANS+=((LL)now)*((LL)n) ; break ; }
            set<int>::iterator it=st.lower_bound(now) ;
            if(it==st.end()) it=st.begin() ;
            int newv=*it , tmp1=last[newv] , tmp2=nex[newv] ;
            ANS+=((LL)i)*((LL)newv) ;
            if(st.count(tmp1) && a[tmp1]>a[tmp2]) st.erase(tmp1) ;
            else if(!st.count(tmp1) && a[tmp1]<a[tmp2]) st.insert(tmp1) ;
            st.erase(newv) ; nex[tmp1]=tmp2 ; last[tmp2]=tmp1 ;
            now=newv ;
        }
        debugf("ans : ") ;
        //for(int i=1;i<=n;i++) debugf("%d,",ans[i]) ; debugf("\n") ;
        printf("%lld\n",ANS) ;
    }
}
