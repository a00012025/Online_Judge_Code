#include<bits/stdc++.h>
using namespace std;
const int maxn=200000+10 ;

int ST[4*maxn][2] ;
int a[2][maxn] ;

inline int cal(int pos,int x,int y)
{
    if(pos>y) return -1 ;
    if(pos>x) return 1 ;
    return 0 ;
}

void pull(int l,int r,int id)
{
    int mid=(l+r)/2 ;
    for(int i=0;i<2;i++)
    {
        if(ST[2*id][i]==-1) ST[id][i]=-1 ;
        else
        {
            int tmp=cal(a[ST[2*id][i]][mid],a[0][mid+1],a[1][mid+1]) ;
            ST[id][i]= (tmp==-1 ? -1 : ST[2*id+1][tmp]) ;
        }
    }
}

void build(int l,int r,int id)
{
    if(l==r)
    {
        ST[id][0]=0 ;
        ST[id][1]=1 ;
        return ;
    }
    int mid=(l+r)/2 ;
    build(l,mid,2*id) ;
    build(mid+1,r,2*id+1) ;
    pull(l,r,id) ;
}

void modify(int L,int R,int id,int pos)
{
    if(L==R) return ;
    int mid=(L+R)/2 ;
    if(pos<=mid) modify(L,mid,2*id,pos) ;
    else modify(mid+1,R,2*id+1,pos) ;
    pull(L,R,id) ;
}

main()
{
    int n ; scanf("%d",&n) ;
    for(int i=1;i<=n;i++)
    {
        scanf("%d%d",&a[0][i],&a[1][i]) ;
        if(a[0][i]>a[1][i]) swap(a[0][i],a[1][i]) ;
    }

    build(1,n,1) ;
    int Q ; scanf("%d",&Q) ;
    while(Q--)
    {
        int l,r ; scanf("%d%d",&l,&r) ;
        swap(a[0][l],a[0][r]) ;
        swap(a[1][l],a[1][r]) ;
        modify(1,n,1,l) ;
        modify(1,n,1,r) ;
        printf("%s\n",ST[1][0]==-1 ? "NIE" : "TAK") ;
    }
}
