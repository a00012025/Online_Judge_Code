#include<bits/stdc++.h>
using namespace std;
const int maxn=100000+10 ;

struct rec
{
    int x1,y1,x2,y2 ;
    void scan(){scanf("%d%d%d%d",&x1,&y1,&x2,&y2);}
}r[maxn],r2[maxn];

struct P
{
    int x,d,u,val ;
    bool operator < (const P &rhs) const
    {
        return x<rhs.x ;
    }
}ev[maxn];

int ST[4*maxn],tag[4*maxn] ;
vector<int> v ;
void modify(int l,int r,int L,int R,int id,int val)
{
    if(l==L && r==R) { tag[id]+=val ; return ; }
    int mid=(L+R)/2 ;
    if(r<=mid) modify(l,r,L,mid,2*id,val) ;
    else if(l>=mid) modify(l,r,mid,R,2*id+1,val) ;
    else
        modify(l,mid,L,mid,2*id,val) ,
        modify(mid,r,mid,R,2*id+1,val) ;
    ST[id]= (tag[2*id] ? v[mid]-v[L] : ST[2*id]) +
            (tag[2*id+1] ? v[R]-v[mid] : ST[2*id+1]) ;
    ST[id]%=2 ;
}

int getarea(int num)
{
    if(!num) return 0 ;
    memset(ST,0,sizeof(ST)) ;
    memset(tag,0,sizeof(tag)) ;
    v.clear() ;
    for(int i=0;i<num;i++) v.push_back(r2[i].y1) , v.push_back(r2[i].y2+1) ;
    sort(v.begin(),v.end()) ;
    v.resize(unique(v.begin(),v.end())-v.begin()) ;
    for(int i=0;i<num;i++)
    {
        int id1=lower_bound(v.begin(),v.end(),r2[i].y1)-v.begin() ;
        int id2=lower_bound(v.begin(),v.end(),r2[i].y2+1)-v.begin() ;
        ev[2*i]=(P){r2[i].x1,id1,id2,1} ,
        ev[2*i+1]=(P){r2[i].x2+1,id1,id2,-1} ;
    }
    sort(ev,ev+2*num) ;
    int x=0 , val=0 , ret=0 ;
    for(int i=0;i<2*num;i++)
    {
        ret+=(ev[i].x-x)*val ; ret%=2 ;
        modify(ev[i].d,ev[i].u,0,maxn-1,1,ev[i].val) ;
        x=ev[i].x ;
        val=ST[1] ;
    }
    return ret ;
}

int a[60] ;
main()
{
    int n,m,k ; scanf("%d%d%d",&n,&m,&k) ;
    for(int i=0;i<m;i++)  r[i].scan() ;

    int i=0 ;
    for(int j=1;j<=k;i++,j*=2)
    {
        int cnt=0 ;
        for(int z=0;z<m;z++)
        {
            int x1=(r[z].x1-1)/j+1 , y1=(r[z].y1-1)/j+1 ;
            int x2=r[z].x2/j , y2=r[z].y2/j ;
            if(x1>x2 || y1>y2) continue ;
            r2[cnt++]=(rec){x1,y1,x2,y2} ;
        }
        a[i]=getarea(cnt) ;
    }
    for(int j=0;j<i;j++)
    {
        a[j]=(a[j]-a[j+1]+2)%2 ;
        if(a[j]){printf("Hamed\n") ; return 0 ;}
    }
    printf("Malek\n") ;
}
