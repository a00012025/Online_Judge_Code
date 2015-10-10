#include<bits/stdc++.h>
#define LL long long
#define INF (1LL<<60)
using namespace std;
const int maxn=200000+10 ;

void gcd(LL a,LL b,LL &x,LL &y,LL d)
{
    if(b==0){x=d/a ; y=0 ; return ;}
    gcd(b,a%b,y,x,d) ;
    y-=(a/b)*x ;
}

LL cal(LL a,LL b,LL c,LL d) /// a*x+b = c*y+d , return min a*x+b or INF
{
    LL g=__gcd(a,c) ;
    if((b-d)%g) return INF ;
    LL x,y ; gcd(a,-c,x,y,d-b) ;

    LL dx=c/g , dy=a/g ;
    if(a*x+b>0)
    {
        LL t=(a*x+b-1)/(a*dx)+1 ;
        x-=t*dx , y-=t*dy ;
    }
    if(a*x+b<0)
    {
        LL t=(-a*x-b-1)/(a*dx)+1 ;
        x+=t*dx , y+=t*dy ;
    }
    return a*x+b ;
}

LL solve(LL a,LL b,LL y,LL M) /// find min x s.t. a <= (x*y)%M <= b
{
    if(a==0) return 0 ;
    else if(y*((a-1)/y+1)<=b) return (a-1)/y+1 ;
    else if(M%y==0) return INF ;
    LL r=solve( ((-b)%y+y)%y , ((-a)%y+y)%y , M%y , y ) ;
    return r==INF ? INF : (a+r*M-1)/y+1 ;
}

vector<int> v[maxn] ;
int tin[maxn],tout[maxn],tick ;
int d[maxn],anc[18][maxn] ;
void dfs(int x,int f,int dep)
{
    anc[0][x]=f ; d[x]=dep ;
    tin[x]=tick++ ;
    for(int i=1;i<18;i++) anc[i][x]=anc[i-1][anc[i-1][x]] ;
    for(auto i : v[x]) if(i!=f)
        dfs(i,x,dep+1) ;
    tout[x]=tick++ ;
}

inline bool isfa(int x,int y) /// x is fa of y
{
    return tin[x]<=tin[y] && tout[x]>=tout[y] ;
}
int LCA(int x,int y)
{
    if(isfa(x,y)) return x ;
    if(isfa(y,x)) return y ;
    for(int i=17;i>=0;i--) if(!isfa(anc[i][x],y))
        x=anc[i][x] ;
    return anc[0][x] ;
}

int u1,v1,u2,v2 ;
int f1,f2,dis ;
int t1,t2,t3,t4 ;
bool getpath()
{
    int p1=LCA(u1,v1) , p2=LCA(u2,v2) ;
    int p3=LCA(u1,u2) , p4=LCA(v1,v2) ;
    int p5=LCA(u1,v2) , p6=LCA(u2,v1) ;
    f1=2*(d[u1]+d[v1]-2*d[p1]) ;
    f2=2*(d[u2]+d[v2]-2*d[p2]) ;
    if(p1==p3 && p3==p5) /// u1
    {
        if(p2==p4) /// v2
        {
            dis=d[p6]-d[p2] ;
            t1=d[u1]+d[p2]-2*d[p3] ; t2=f1/2+d[v1]-d[p6] ;
            t3=f2/2+d[v2]-d[p2] ; t4=d[u2]-d[p6] ;
        }
        else if(p2==p6) /// u2
        {
            dis=d[p4]-d[p2] ;
            t1=d[u1]+d[p2]-2*d[p3] ; t2=f1/2+d[v1]-d[p4] ;
            t3=d[u2]-d[p2] ; t4=f2/2+d[v2]-d[p4] ;
        }
        else return 0 ;
    }
    else if(p1==p4 && p4==p6) /// v1
    {
        if(p2==p5) /// v2
        {
            dis=d[p3]-d[p2] ;
            t1=d[u1]-d[p3] ; t2=f1/2+d[p2]+d[v1]-2*d[p1] ;
            t3=d[u2]-d[p3] ; t4=f2/2+d[v2]-d[p2] ;
        }
        else if(p2==p3) /// u2
        {
            dis=d[p5]-d[p3] ;
            t1=d[u1]-d[p5] ; t2=f1/2+d[p3]+d[v1]-2*d[p1] ;
            t3=f2/2+d[v2]-d[p5] ; t4=d[u2]-d[p3] ;
        }
        else return 0 ;
    }
    else if(p2==p3 && p3==p6) /// u2
    {
        if(p1==p4) /// v1
        {
            dis=d[p5]-d[p1] ;
            t1=d[u1]-d[p5] ; t2=f1/2+d[v1]-d[p1] ;
            t3=f2/2+d[v2]-d[p5] ; t4=d[p1]+d[u2]-2*d[p3] ;
        }
        else if(p1==p5) /// u1
        {
            dis=d[p4]-d[p1] ;
            t1=d[u1]-d[p1] ; t2=f1/2+d[v1]-d[p4] ;
            t3=d[p1]+d[u2]-2*d[p3] ; t4=f2/2+d[v2]-d[p4] ;
        }
        else return 0 ;
    }
    else if(p2==p4 && p4==p5) /// v2
    {
        if(p1==p3) /// u1
        {
            dis=d[p6]-d[p3] ;
            t1=d[u1]-d[p3] ; t2=f1/2+d[v1]-d[p6] ;
            t3=f2/2+d[v2]+d[p3]-2*d[p2] ; t4=d[u2]-d[p6] ;
        }
        else if(p1==p6) /// v1
        {
            dis=d[p3]-d[p1] ;
            t1=d[u1]-d[p3] ; t2=f1/2+d[v1]-d[p1] ;
            t3=d[u2]-d[p3] ; t4=f2/2+d[p1]+d[v2]-2*d[p2] ;
        }
        else return 0 ;
    }
    else if(!isfa(p3,p4) && !isfa(p4,p3))
    {
        dis=d[p3]+d[p4]-2*d[p1] ;
        t1=d[u1]-d[p3] ; t2=f1/2+d[v1]-d[p4] ;
        t3=d[u2]-d[p3] ; t4=f2/2+d[v2]-d[p4] ;
    }
    else if(!isfa(p5,p6) && !isfa(p6,p5))
    {
        dis=d[p5]+d[p6]-2*d[p1] ;
        t1=d[u1]-d[p5] ; t2=f1/2+d[v1]-d[p6] ;
        t3=f2/2+d[v2]-d[p5] ; t4=d[u2]-d[p6] ;
    }
    else return 0 ;
    return 1 ;
}

void update(LL &ans,int type)
{
    int T1=(type==1 ? t1 : t2) ;
    int T2=(type==1 ? t4 : t3) ;
    if((dis+T1+T2)%2) return ;
    int a=T2-T1-dis , b=T2-T1+dis ;

    int x0=(a-1)/f1+1 , y0=(-b-1)/f2+1 ;
    if(a<=0 && b>=0){ans=min(ans,(LL)(dis+T1+T2)/2) ; return ;}
    if(a>=0 && x0*f1<=b)
        ans=min(ans,(LL)(dis+T1+T2+x0*f1)/2) ;
    else if(a<=0 && y0*f2+a<=0)
        ans=min(ans,(LL)(dis+T1+T2+y0*f2)/2) ;
    else
    {
        LL x=solve((a%f2+f2)%f2,(b%f2+f2)%f2,f1,f2) ;
        LL y=(x*f1-b-1)/f2+1 ;
        if(x!=INF) ans=min(ans,(dis+T1+T2+x*f1+y*f2)/2) ;
    }
}

main()
{
    int n ; scanf("%d",&n) ;
    for(int i=1;i<n;i++)
    {
        int x,y ; scanf("%d%d",&x,&y) ;
        v[x].push_back(y) ;
        v[y].push_back(x) ;
    }
    dfs(1,1,0) ;
    int Q ; scanf("%d",&Q) ;
    while(Q--)
    {
        scanf("%d%d%d%d",&u1,&v1,&u2,&v2) ;
        if(!getpath()){printf("-1\n") ; continue ;}
        LL ans=INF ;
        ans=min(ans,cal(f1,t1,f2,t3)) ;
        ans=min(ans,cal(f1,t2,f2,t4)) ;
        update(ans,1) ;
        update(ans,2) ;
        printf("%I64d\n",ans==INF ? -1 : ans) ;
    }
}
