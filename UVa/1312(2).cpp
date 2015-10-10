#include<stdio.h>
#include<algorithm>
#include<set>
using namespace std;
struct P
{
    int x,y ;
    bool operator < (const P &rhs) const
    {
        return max(x,y)<max(rhs.x,rhs.y) ;
    }
}pt[101],newp[101];

int k,m,n,ansnum,dx[]={1,-1,-1,1},dy[]={-1,-1,1,1} ;
P ans ;

set<P> st;
void check(int x,int y,int type)
{
    int num ;
    st.clear() ;
    for(int i=1;i<=k;i++) if(pt[i].x!=x && pt[i].y!=y)
    {
        int nx=dx[type]*(pt[i].x-x) , ny=dy[type]*(pt[i].y-y) ;
        if(nx<0 || ny<0) continue ;
        st.insert((P){nx,ny}) ;
    }
    if(type==0) num=min(n-x,y) ;
    if(type==1) num=min(x,y) ;
    if(type==2) num=min(x,m-y) ;
    if(type==3) num=min(n-x,m-y) ;
    if(!st.empty())
    {
        set<P>::iterator it=st.begin() ;
        num=min(num,max(it->x,it->y)) ;
    }
    if(num>ansnum)
    {
        ansnum=num ;
        if(type==0) ans=(P){x,y-num} ;
        if(type==1) ans=(P){x-num,y-num} ;
        if(type==2) ans=(P){x-num,y} ;
        if(type==3) ans=(P){x,y} ;
    }
}

main()
{
    int T;
    scanf("%d",&T) ;
    while(T--)
    {
        scanf("%d%d%d",&k,&n,&m) ;
        for(int i=1;i<=k;i++) scanf("%d%d",&pt[i].x,&pt[i].y) ;
        ansnum=-1 ;
        pt[++k]=(P){0,0} ; pt[++k]=(P){n,0} ; pt[++k]=(P){0,m} ; pt[++k]=(P){n,m} ;
        for(int i=1;i<=k;i++) for(int j=i+1;j<=k;j++)
        {
            if(pt[i].x==pt[j].x || pt[i].y==pt[j].y) continue ;
            if(pt[i].x<pt[j].x && pt[i].y>pt[j].y)
                {check(pt[i].x,pt[j].y,3) ; check(pt[j].x,pt[i].y,1) ;}
            if(pt[i].x<pt[j].x && pt[i].y<pt[j].y)
                {check(pt[i].x,pt[j].y,0) ; check(pt[j].x,pt[i].y,2) ;}
            if(pt[i].x>pt[j].x && pt[i].y>pt[j].y)
                {check(pt[i].x,pt[j].y,2) ; check(pt[j].x,pt[i].y,0) ;}
            if(pt[i].x>pt[j].x && pt[i].y<pt[j].y)
                {check(pt[i].x,pt[j].y,1) ; check(pt[j].x,pt[i].y,3) ;}
        }
        printf("%d %d %d\n",ans.x,ans.y,ansnum) ;
        if(T) printf("\n") ;
    }
}
