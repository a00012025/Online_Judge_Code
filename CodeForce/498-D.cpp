#include<bits/stdc++.h>
using namespace std;
const int maxn=100000+10 ;

int a[maxn],ST[7*maxn][60] ;

void maintain(int id)
{
    for(int i=0;i<60;i++)
        ST[id][i]=ST[2*id][i]+ST[2*id+1][ (i+ST[2*id][i])%60 ] ;
}

void build(int l,int r,int id)
{
    if(r==l+1)
    {
        for(int i=0;i<60;i++) ST[id][i]= (i%a[l]==0 ? 2 : 1) ;
        return ;
    }
    int mid=(r+l)/2 ;
    build(l,mid,2*id) ;
    build(mid,r,2*id+1) ;
    maintain(id) ;
}

void modify(int L,int R,int id,int pos,int val)
{
    if(R==L+1)
    {
        for(int i=0;i<60;i++) ST[id][i]= (i%val==0 ? 2 : 1) ;
        return ;
    }
    int mid=(L+R)/2 ;
    if(pos+1<=mid) modify(L,mid,2*id,pos,val) ;
    else modify(mid,R,2*id+1,pos,val) ;
    maintain(id) ;
}

void query(int l,int r,int L,int R,int id,int &time)
{
    if(l==L && r==R)
    {
        time += ST[id][time%60] ;
        return ;
    }
    int mid=(L+R)/2 ;
    if(r<=mid) query(l,r,L,mid,2*id,time) ;
    else if(l>=mid) query(l,r,mid,R,2*id+1,time) ;
    else
    {
        query(l,mid,L,mid,2*id,time) ;
        query(mid,r,mid,R,2*id+1,time) ;
    }
}

main()
{
    int n ; scanf("%d",&n) ;
    for(int i=1;i<=n;i++) scanf("%d",&a[i]) ;
    build(1,n+1,1) ;
    int Q ; scanf("%d",&Q) ;
    while(Q--)
    {
        char c[3] ; int x,y ;
        scanf("%s%d%d",c,&x,&y) ;
        if(c[0]=='C') modify(1,n+1,1,x,y) ;
        else
        {
            int ans=0 ;
            query(x,y,1,n+1,1,ans) ;
            printf("%d\n",ans) ;
        }
    }
}
