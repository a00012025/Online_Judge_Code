#include<bits/stdc++.h>
using namespace std;
const int maxn=100000+10,maxm=10+2 ;

struct P{int x,y;}ST[4*maxn][maxm];
char G[maxn][maxm] ;
int n,m ;

void cal(int x,P *a)
{
    for(int i=1;i<=m;i++)
        a[i]=(G[x][i]=='^' ? (P){x-1,i} : (P){-2,-2}) ;
    if(G[x][1]=='<') a[1]=(P){x,0} ;
    if(G[x][m]=='>') a[m]=(P){x,m+1} ;
    for(int i=1;i<m;i++) if(G[x][i]=='>' && G[x][i+1]=='<')
        a[i]=a[i+1]=(P){-1,-1} ;
    for(int i=1;i<=m;i++) if(G[x][i]=='<' && a[i].x==-2)
        a[i]=a[i-1] ;
    for(int i=m;i>=1;i--) if(G[x][i]=='>' && a[i].x==-2)
        a[i]=a[i+1] ;
}

void pull(int l,int r,P *a,P *b,P *c)
{
    int mid=(l+r)/2 ;
    for(int i=1;i<=m;i++)
        c[i]=(b[i].x==mid ? a[b[i].y] : b[i]) ;
}

void build(int l,int r,int id)
{
    if(l==r){cal(l,ST[id]) ; return ;}
    int mid=(l+r)/2 ;
    build(l,mid,2*id) ;
    build(mid+1,r,2*id+1) ;
    pull(l,r,ST[2*id],ST[2*id+1],ST[id]) ;
}

void modify(int l,int r,int id,int pos)
{
    if(l==r){cal(l,ST[id]) ; return ;}
    int mid=(l+r)/2 ;
    if(pos<=mid) modify(l,mid,2*id,pos) ;
    else modify(mid+1,r,2*id+1,pos) ;
    pull(l,r,ST[2*id],ST[2*id+1],ST[id]) ;
}

struct Q{int l,r,id;};
vector<Q> v ;
void getseg(int l,int r,int L,int R,int id)
{
    if(l==L && r==R){v.push_back((Q){L,R,id}) ; return ;}
    int mid=(L+R)/2 ;
    if(r<=mid) getseg(l,r,L,mid,2*id) ;
    else if(l>mid) getseg(l,r,mid+1,R,2*id+1) ;
    else getseg(l,mid,L,mid,2*id) ,
        getseg(mid+1,r,mid+1,R,2*id+1) ;
}

main()
{
    int q ; scanf("%d%d%d",&n,&m,&q) ;
    for(int i=1;i<=n;i++) scanf("%s",G[i]+1) ;
    build(1,n,1) ;
    while(q--)
    {
        int x,y ;
        char c[3] ; scanf("%s%d%d",c,&x,&y) ;
        if(c[0]=='C')
        {
            scanf("%s",c) ;
            G[x][y]=c[0] ;
            modify(1,n,1,x) ;
        }
        else
        {
            v.clear() ;
            getseg(1,x,1,n,1) ;
            reverse(v.begin(),v.end()) ;
            P now=(P){x,y} ;
            for(auto i : v)
            {
                now=ST[i.id][now.y] ;
                if(now.x != i.l-1) break ;
            }
            printf("%d %d\n",now.x,now.y) ;
        }
    }
}
