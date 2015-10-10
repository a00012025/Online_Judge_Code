#include<bits/stdc++.h>
#define pii pair<int,int>
#define F first
#define S second
#define mkp(x,y) make_pair(x,y)
#define INF 2000000000
using namespace std;
const int maxn=500000+10 ;
int ST[2][8*maxn] ;

void build(int L,int R,int id)
{
    ST[0][id]=ST[1][id]=-INF ;
    if(L==R) return ;
    int mid=(L+R)/2 ;
    build(L,mid,2*id) ;
    build(mid+1,R,2*id+1) ;
}

void modify(int L,int R,int id,int tr,int pos,int val)
{
    if(L==R) { ST[tr][id]=val ; return ; }
    int mid=(L+R)/2 ;
    if(pos<=mid) modify(L,mid,2*id,tr,pos,val) ;
    else modify(mid+1,R,2*id+1,tr,pos,val) ;
    ST[tr][id]=max(ST[tr][2*id],ST[tr][2*id+1]) ;
}

int query(int l,int r,int L,int R,int id,int tr)
{
    if(l==L && r==R) return ST[tr][id] ;
    int mid=(L+R)/2 ;
    if(r<=mid) return query(l,r,L,mid,2*id,tr) ;
    else if(l>mid) return query(l,r,mid+1,R,2*id+1,tr) ;
    else return max(query(l,mid,L,mid,2*id,tr) ,
                    query(mid+1,r,mid+1,R,2*id+1,tr)) ;
}

vector<pii> v[maxn] ;
int tmp1[maxn],tmp2[maxn],sum1[maxn],sum2[maxn] ;
main()
{
    int n,U,D,st ; scanf("%d%d%d%d",&n,&U,&D,&st) ;
    build(1,500001,1) ;
    while(n--)
    {
        int t,pos,w ; scanf("%d%d%d",&t,&pos,&w) ;
        v[t].push_back(mkp(pos,w)) ;
    }

    for(int i=1;i<maxn;i++) sort(v[i].begin(),v[i].end()) ;

    modify(1,500001,1,0,st,D*st) ;
    modify(1,500001,1,1,st,-U*st) ;

    for(int i=1;i<maxn;i++) if(!v[i].empty())
    {
        int sz=v[i].size() ;
        for(int j=0;j<sz;j++)
            sum1[j]= j==0 ? v[i][j].S : sum1[j-1]+v[i][j].S ;
        for(int j=sz-1;j>=0;j--)
            sum2[j]= j==sz-1 ? v[i][j].S : sum2[j+1]+v[i][j].S ;
        for(int j=0;j<sz;j++)
        {
            tmp1[j]=query(1,v[i][j].F,1,500001,1,0) - D*v[i][j].F ;
            int val2=query(v[i][j].F,500001,1,500001,1,1) + U*v[i][j].F ;
            tmp1[j]=v[i][j].S+max(tmp1[j],val2) ;
            tmp2[j]=tmp1[j] ;
        }

        int M=-INF ;
        for(int j=sz-1;j>=0;j--)
        {
            if(j!=sz-1) tmp1[j]=max(tmp1[j],sum2[j]+U*v[i][j].F+M) ;
            M=max(M,tmp1[j]-sum2[j]-U*v[i][j].F) ;
        }

        M=-INF ;
        for(int j=0;j<sz;j++)
        {
            if(j!=0) tmp2[j]=max(tmp2[j],sum1[j]-D*v[i][j].F+M) ;
            M=max(M,tmp2[j]-sum1[j]+D*v[i][j].F) ;
        }

        int dp ;
        for(int j=0;j<sz;j++)
        {
            if(j==0) dp=0 ;
            else dp=max(dp-(U+D)*(v[i][j].F-v[i][j-1].F)+v[i][j-1].S,0) ;
            tmp1[j]+=dp ;
        }

        for(int j=sz-1;j>=0;j--)
        {
            if(j==sz-1) dp=0 ;
            else dp=max(dp-(U+D)*(v[i][j+1].F-v[i][j].F)+v[i][j+1].S,0) ;
            tmp2[j]+=dp ;
        }

        for(int j=0;j<sz;j++)
        {
            modify(1,500001,1,0,v[i][j].F,max(tmp1[j],tmp2[j])+D*v[i][j].F) ;
            modify(1,500001,1,1,v[i][j].F,max(tmp1[j],tmp2[j])-U*v[i][j].F) ;
        }
    }

    int ans=0 ;
    ans=max(ans,query(1,st,1,500001,1,0)-D*st) ;
    ans=max(ans,query(st,500001,1,500001,1,1)+U*st) ;
    printf("%d\n",ans) ;
}
