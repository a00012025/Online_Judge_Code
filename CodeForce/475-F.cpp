#include<stdio.h>
#include<stdlib.h>
#include<vector>
#include<map>
#include<algorithm>
#define LL long long
#define MAXN 1000001000
using namespace std;
typedef struct {LL x,y ;} pt ;
map<LL,int> mpx ;
vector<LL> vx[100001] ;
LL cor_x[100001] ;
int x_num ;

bool cmp1(pt a,pt b)
{
    if(a.x != b.x) return a.x<b.x ;
    else return a.y<b.y ;
}

pt P[100001] ;

bool check(LL x1,LL y1,LL x2,LL y2)
{
    int a,b,id ;
    a=lower_bound(cor_x+1,cor_x+x_num+1,x1) - cor_x ;
    if(a==x_num+1 || cor_x[a]>x2) return false ;
    id=mpx[cor_x[a]] ;
    for(int i=id;i<=x_num;i++)
    {
        if(cor_x[i]>x2) break ;
        int l=0,r=vx[i].size()-1 ;
        if(vx[i][l]>=y1 && vx[i][l]<=y2) return true ;
        if(vx[i][r]>=y1 && vx[i][r]<=y2) return true ;
        if(vx[i][r]==y1 || vx[i][l]==y2) return true ;
        if(vx[i][r]<y1 || vx[i][l]>y2) continue ;
        while(r-l>1)
        {
            int mid=(r+l)/2 ;
            if(vx[i][mid]<y1) l=mid ;
            else r=mid ;
        }
        if(vx[i][r]<=y2) return true ;
    }
    return false ;
}

LL solve(LL x1,LL y1,LL x2,LL y2)
{
    if(!check(x1,y1,x2,y2)) return 0 ;
    LL midx=(x1+x2)/2 , midy=(y1+y2)/2 , nx , ny;
    for(LL i=1;i<=x2+y2-x1-y1+10;i++)
    {
        if(i%4==1 || i%4==0)
        {
            if(i%4==0) nx=midx+(i/4) ;
            else nx=midx-(i/4) ;
            if(nx<=x1 || nx>=x2) continue ;
            if(!check(nx,y1,nx,y2))
                return solve(x1,y1,nx-1,y2)+solve(nx+1,y1,x2,y2) ;
        }
        else
        {
            if(i%4==2) ny=midy+(i/4) ;
            else ny=midy-(i/4)-1 ;
            if(ny<=y1 || ny>=y2) continue ;
            if(!check(x1,ny,x2,ny))
                return solve(x1,y1,x2,ny-1)+solve(x1,ny+1,x2,y2) ;
        }
    }
    return 1 ;
}

main()
{
    int n ;
    scanf("%d",&n) ;
    for(int i=1;i<=n;i++) scanf("%I64d %I64d",&P[i].x,&P[i].y) ;
    sort(P+1,P+n+1,cmp1) ;
    int cnt=0 ;
    for(int i=1;i<=n;i++)
    {
        if(i>=2 && P[i].x==P[i-1].x)
            {vx[cnt].push_back(P[i].y) ; continue ;}
        cnt++ ;
        mpx[P[i].x]=cnt ;
        cor_x[cnt]=P[i].x ;
        vx[cnt].push_back(P[i].y) ;
    }
    x_num=cnt ;
    printf("%I64d\n",solve(-MAXN,-MAXN,MAXN,MAXN)) ;
}
