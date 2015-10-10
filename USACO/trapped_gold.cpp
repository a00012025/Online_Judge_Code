#include<bits/stdc++.h>
#define pii pair<int,int>
#define F first
#define S second
using namespace std;
const int maxn=100000+10 ;

int ST[4*maxn] ;
void modify(int l,int r,int L,int R,int id)
{
    if(l==L && r==R) { ST[id]=1 ; return ; }
    if(ST[id]) return ;
    int mid=(L+R)/2 ;
    if(r<=mid) modify(l,r,L,mid,2*id) ;
    else if(l>mid) modify(l,r,mid+1,R,2*id+1) ;
    else modify(l,mid,L,mid,2*id) ,
            modify(mid+1,r,mid+1,R,2*id+1) ;
}
int query(int L,int R,int id,int pos)
{
    if(L==R || ST[id]) return ST[id] ;
    int mid=(L+R)/2 ;
    if(pos<=mid) return query(L,mid,2*id,pos) ;
    else return query(mid+1,R,2*id+1,pos) ;
}

pii a[maxn] ;

int n,a0[maxn] ;
inline int getid(int val)
{
    return lower_bound(a0+1,a0+n+1,val)-a0 ;
}

set<int> st ;
main()
{
    if(fopen("trapped.in","r"))
    {
        freopen("trapped.in","r",stdin) ;
        freopen("trapped.out","w",stdout) ;
    }
    scanf("%d",&n) ;
    for(int i=1;i<=n;i++) scanf("%d%d",&a[i].S,&a[i].F) ;
    sort(a+1,a+n+1) ;
    for(int i=1;i<=n;i++) a0[i]=a[i].F ;

    for(int i=1;i<=n;i++) swap(a[i].F,a[i].S) ;
    sort(a+1,a+n+1) ;
    for(int i=n;i>=1;i--)
    {
        int now=a[i].S , h=a[i].F ;
        st.insert(now) ;
        auto it=st.upper_bound(now+h) ; it-- ;
        if(*it != now) modify(getid(now),getid(*it)-1,1,n-1,1) ;
        it=st.lower_bound(now-h) ;
        if(*it != now) modify(getid(*it),getid(now)-1,1,n-1,1) ;
    }

    int ans=0 ;
    for(int i=1;i<n;i++) if(query(1,n-1,1,i))
        ans+=a0[i+1]-a0[i] ;
    printf("%d\n",ans) ;
}
