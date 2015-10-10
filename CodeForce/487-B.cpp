#include<bits/stdc++.h>
#define INF 100000000
using namespace std;
const int maxn=100000+10 ;

inline int get_dif(const multiset<int> &mst)
{
    multiset<int>::iterator it=mst.end() ; it-- ;
    return (*it) - (*(mst.begin())) ;
}

int a[maxn],ST[8*maxn] ;

void build(int l,int r,int id)
{
    ST[id]=INF ;
    if(l==r)
    {
        if(l==0) ST[id]=0 ;
        return ;
    }
    int mid=(l+r)/2 ;
    build(l,mid,2*id) ;
    build(mid+1,r,2*id+1) ;
}

void modify(int l,int r,int L,int R,int id,int val)
{
    if(l==L && r==R) { ST[id]=min(ST[id],val) ; return ; }
    int mid=(L+R)/2 ;
    if(r<=mid) modify(l,r,L,mid,2*id,val) ;
    else if(l>mid) modify(l,r,mid+1,R,2*id+1,val) ;
    else
    {
        modify(l,mid,L,mid,2*id,val) ;
        modify(mid+1,r,mid+1,R,2*id+1,val) ;
    }
}

int query(int L,int R,int id,int x)
{
    if(L==R) return ST[id] ;
    int mid=(L+R)/2 ;
    if(x<=mid) return min(ST[id],query(L,mid,2*id,x)) ;
    else return min(ST[id],query(mid+1,R,2*id+1,x)) ;
}

multiset<int> st ;
int r[maxn] ;
main()
{
    int n,dif,len ; scanf("%d%d%d",&n,&dif,&len) ;
    for(int i=1;i<=n;i++) scanf("%d",&a[i]) ;
    build(0,n,1) ;
    int now=1 ;
    for(int i=1;i<=n;i++)
    {
        while(now<=n)
        {
            st.insert(a[now]) ;
            if(get_dif(st)>dif) { st.erase(st.find(a[now])) ; break ; }
            else now++ ;
        }
        st.erase(st.find(a[i])) ;
        r[i]=now-1 ;
    }
    for(int i=1;i<=n;i++)
    {
        int val=query(0,n,1,i-1) ;
        if(val==INF || r[i]-i+1 < len) continue ;
        modify(i+len-1,r[i],0,n,1,val+1) ;
    }
    int ans=query(0,n,1,n) ;
    printf("%d\n",ans==INF ? -1 : ans) ;
}
