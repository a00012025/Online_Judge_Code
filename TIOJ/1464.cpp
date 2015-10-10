#include<bits/stdc++.h>
using namespace std;
const int maxn=1000000+10 ;

char s1[maxn],s2[maxn] ;
int ST[7*maxn] ;

void build(int l,int r,int id)
{
    if(l==r)
    {
        ST[id]= s1[l]==s2[l] ? 0 : 1 ;
        return ;
    }
    int mid=(l+r)/2 ;
    build(l,mid,2*id) ;
    build(mid+1,r,2*id+1) ;
}

int query(int L,int R,int id,int x)
{
    if(L==R) return ST[id] ;
    int mid=(L+R)/2 ;
    if(x<=mid) return ST[id]+query(L,mid,2*id,x) ;
    else return ST[id]+query(mid+1,R,2*id+1,x) ;
}

void modify(int l,int r,int L,int R,int id,int val)
{
    if(l==L && r==R) { ST[id]+=val ; return ; }
    int mid=(L+R)/2 ;
    if(r<=mid) modify(l,r,L,mid,2*id,val) ;
    else if(l>mid) modify(l,r,mid+1,R,2*id+1,val) ;
    else modify(l,mid,L,mid,2*id,val) ,
        modify(mid+1,r,mid+1,R,2*id+1,val) ;
}

main()
{
    int n,m ;
    scanf("%d%d%s%s",&n,&m,s1+1,s2+1) ;
    build(1,n,1);
    int ans=0 ;
    for(int i=1;i<=n-m+1;i++) if(query(1,n,1,i)%2)
        modify(i,i+m-1,1,n,1,1) , ans++ ;
    bool ok=1 ;
    for(int i=n-m+2;i<=n;i++) if(query(1,n,1,i)%2)
        { ok=0 ; break ; }
    if(!ok) printf("No Way!!\n") ;
    else printf("%d\n",ans) ;
}
