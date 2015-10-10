#include<bits/stdc++.h>
#define ABS(x) ((x)>0 ? (x) : (-(x)))
using namespace std;
const int maxn=400000+10 , LOG=int(log2(maxn)+1) ;

int n,a[maxn] ;
int rmq[LOG][maxn],log_t[maxn] ;
inline void build_rmq()
{
    for(int i=0;(1<<i)<=n;i++) for(int j=1;j+(1<<i)-1<=n;j++)
        rmq[i][j]=(i ?
        min(rmq[i-1][j],rmq[i-1][j+(1<<(i-1))]) : a[j]) ;
}
inline int rmq_query(int l,int r)
{
    int t=log_t[r-l+1] ;
    return min(rmq[t][l],rmq[t][r-(1<<t)+1]) ;
}

int ST[4*maxn] ;
void modify(int L,int R,int id,int pos,int val)
{
    if(L==R){ST[id]=val ; return ;}
    int mid=(L+R)/2 ;
    if(pos<=mid) modify(L,mid,2*id,pos,val) ;
    else modify(mid+1,R,2*id+1,pos,val) ;
    ST[id]=min(ST[2*id],ST[2*id+1]) ;
}
int query(int l,int r,int L,int R,int id)
{
    if(l==L && r==R) return ST[id] ;
    int mid=(L+R)/2 ;
    if(r<=mid) return query(l,r,L,mid,2*id) ;
    else if(l>mid) return query(l,r,mid+1,R,2*id+1) ;
    else return min(query(l,mid,L,mid,2*id),
                    query(mid+1,r,mid+1,R,2*id+1)) ;
}

int ans[maxn],sta[maxn],stid[maxn] ;
int size ;
void process_query(int x0,int y0,int x1,int y1,int qid)
{
    if(x1>=x0)
    {
        int id1=lower_bound(stid,stid+size,x0)-stid ;
        int id2=lower_bound(sta+id1,sta+size,y1)-sta ;
        if(id2<size) ans[qid]=min(ans[qid],x1-x0+1+sta[id2]-y1) ;
        if(id2>id1) ans[qid]=min(ans[qid],x1-x0+1+y1-sta[id2-1]) ;
    }
    int id1=lower_bound(sta,sta+size,y1)-sta ; /// x >= id1
    int id2=upper_bound(stid,stid+size,x0)-stid-1 ; /// x <= id2

    if(id1<=id2)
        ans[qid]=min(ans[qid],query(id1,id2,0,n-1,1)-y1+x0+x1+1) ;

    int val=y0 ;
    if(x0>x1) val=min(val,rmq_query(x1,x0)) ;
    int id3=upper_bound(sta,sta+size,val)-sta-1 ;
    id3=min(id3,id2) ;
    if(id1<=id3)
        ans[qid]=min(ans[qid],query(id1,id3,0,n-1,1)-y1+x0+x1) ;

    if(id1-1<=id2 && id1) ans[qid]=min(ans[qid],
        (y1-sta[id1-1])-2*stid[id1-1]+x0+x1+(val<sta[id1-1])) ;
}

struct P{int x0,y0,x1,y1,id;};
void process(vector<P> *v)
{
    size=0 ;
    for(int i=1;i<=n;i++)
    {
        while(size && sta[size-1]>=a[i]) size-- ;
        modify(0,n-1,1,size,a[i]-2*i) ;
        sta[size]=a[i] ; stid[size++]=i ;
        for(auto it : v[i]) process_query(it.x0,it.y0,it.x1,it.y1,it.id) ;
    }
}

vector<P> qu[2][maxn] ;
main()
{
    log_t[0]=log_t[1]=0 ;
    for(int i=2;i<maxn;i++) log_t[i]=log_t[i/2]+1 ;

    scanf("%d",&n) ;
    for(int i=1;i<=n;i++) scanf("%d",&a[i]) ;
    int Q ; scanf("%d",&Q) ;

    build_rmq() ;
    for(int i=1;i<=Q;i++)
    {
        int x0,y0,x1,y1 ; scanf("%d%d%d%d",&x0,&y0,&x1,&y1) ;
        qu[0][x1].push_back((P){x0,y0,x1,y1,i}) ;
        qu[1][n+1-x1].push_back((P){n+1-x0,y0,n+1-x1,y1,i}) ;
        ans[i]=ABS(x0-x1)+y1+1 ;
        if(x0==x1) ans[i]=min(ans[i],ABS(y0-y1)) ;
        else
        {
            int mi=(x0>x1 ? rmq_query(x1,x0) : rmq_query(x0,x1)) ;
            mi=min(mi,y0) ;
            ans[i]=min(ans[i],ABS(x0-x1)+ABS(mi-y1)) ;
        }
    }
    process(qu[0]) ;
    for(int i=1;n+1-i>i;i++) swap(a[i],a[n+1-i]) ;
    build_rmq() ;
    process(qu[1]) ;
    for(int i=1;i<=Q;i++) printf("%d\n",ans[i]) ;
}
