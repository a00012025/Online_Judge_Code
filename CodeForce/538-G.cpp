#include<bits/stdc++.h>
#define LL long long
#define ABS(x) ((x)>0 ? (x) : (-(x)))
#define INF (1LL<<60)
using namespace std;
const int maxn=200000+10 ;

struct pll{LL x,y;};
pll cal(LL k,LL a,LL b) /// a <= kx <= b  -->  ? <= x <= ? , k>0
{
    pll p ;
    p.x = (a>0  ? (a-1)/k+1 : a/k) ;
    p.y = (b>=0 ? b/k : (b+1)/k-1) ;
    return p ;
}

struct P
{
    int id ; LL a,b,c,d ;
    bool operator < (const P &rhs) const
    {
        return id<rhs.id ;
    }
}p[maxn];

struct cond{LL a,b,c,d,e;}con[maxn] ;
int ccnt ;
pll get_interval(LL x,int &pa) /// parity , 1 : odd ok , 2 : even ok
{
    pll ret=(pll){-INF,INF} ;
    pa=3 ;
    for(int i=0;i<ccnt;i++)
    {
        if(con[i].a%2)
        {
            int z=((con[i].e-x-con[i].d-con[i].b)%2+2)%2 ;
            if(z==0 && (pa&1)) pa^=1 ;
            if(z==1 && (pa&2)) pa^=2 ;
        }
        LL val=con[i].e-ABS(x*con[i].a+con[i].b) ;
        pll tmp=cal(con[i].c,-val-con[i].d,val-con[i].d) ;
        ret.x=max(ret.x,tmp.x) ;
        ret.y=min(ret.y,tmp.y) ;
    }
    return ret ;
}

int n,L ;
void found_ans(LL x,LL y)
{
    for(int i=0;i<n+1;i++)
    {
        if(p[i].id==p[i+1].id) continue ;
        LL x1=x*p[i].a+p[i].b , y1=y*p[i].c+p[i].d ;
        LL x2=x*p[i+1].a+p[i+1].b , y2=y*p[i+1].c+p[i+1].d ;
        LL dx=x2-x1 , dy=y2-y1 , dis=p[i+1].id-p[i].id ;
        dis-=ABS(dx)+ABS(dy) ;
        while(dx<0) putchar('L') , dx++ ;
        while(dx>0) putchar('R') , dx-- ;
        while(dy<0) putchar('D') , dy++ ;
        while(dy>0) putchar('U') , dy-- ;
        while(dis) putchar('L') , putchar('R') , dis-=2 ;
    }
}

main()
{
    scanf("%d%d",&n,&L) ;
    for(int i=1;i<=n;i++)
    {
        LL t,x,y ; scanf("%I64d%I64d%I64d",&t,&x,&y) ;
        if((t+x+y)%2){printf("NO\n") ; return 0 ;}
        LL u=t/L ; int v=t%L ;
        p[i]=(P){v,-u,x,-u,y} ;
    }
    p[0]=(P){0,0,0,0,0} ;
    p[n+1]=(P){L,1,0,1,0} ;
    sort(p,p+n+2) ;
    for(int i=0;i<n+1;i++)
    {
        LL a=p[i].a-p[i+1].a , b=p[i].b-p[i+1].b ;
        LL c=p[i].c-p[i+1].c , d=p[i].d-p[i+1].d ;
        if(!a)
        {
            if(ABS(b)+ABS(d)>p[i+1].id-p[i].id)
                {printf("NO\n") ; return 0 ;}
            continue ;
        }
        if(a<0) a=-a , b=-b , c=-c , d=-d ;
        con[ccnt++]=(cond){a,b,c,d,p[i+1].id-p[i].id} ;
    }

    int mi=L+1 , mid ;
    for(int i=0;i<ccnt;i++) if(con[i].e<mi)
        mi=con[mid=i].e ;
    pll tmp=cal(con[mid].a,-con[mid].e-con[mid].b,con[mid].e-con[mid].b) ;

    for(LL i=tmp.x;i<=tmp.y;i++)
    {
        int pa ;
        pll tmp2=get_interval(i,pa) ;
        if((tmp2.x%2) && !(pa&1)) tmp2.x++ ;
        if((tmp2.x%2==0) && !(pa&2)) tmp2.x++ ;
        if(tmp2.y>=tmp2.x && pa){found_ans(i,tmp2.x) ; return 0 ;}
    }
    printf("NO\n") ;
}
