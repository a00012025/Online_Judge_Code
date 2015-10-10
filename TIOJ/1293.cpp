#include<bits/stdc++.h>
#define LL long long
using namespace std;
const int maxn=100000+10 ;

struct P
{
    int pos,val ;
    bool operator < (const P &rhs) const
    {
        return pos==rhs.pos ? val<rhs.val : pos<rhs.pos ;
    }
};

P x[maxn],y[maxn] ;
bool found ;
int n,ansx,ansy ;
LL ans ;

void solve(vector<int> &v,P *p)
{
    LL sum=0LL ;
    for(int i=1;i<=n;i++) sum+=p[i].val ;
    LL now=0LL ;
    for(int i=1;i<=n;i++)
    {
        now+=p[i].val ;
        if(sum%2 && 2*now>sum) { v.push_back(p[i].pos) ; break ; }
        else if(sum%2==0)
        {
            if(2*now==sum)
            {
                v.push_back(p[i].pos) ;
                v.push_back(p[i+1].pos) ;
                break ;
            }
            else if(2*now>sum)
            {
                v.push_back(p[i].pos) ;
                break ;
            }
        }
    }
}

LL cal(int x0,int y0)
{
    LL ret=0LL ;
    for(int i=1;i<=n;i++)
        ret+= ((LL)x[i].val)*
            (x0>=x[i].pos ? (LL)x0-x[i].pos : (LL)x[i].pos-x0 ) ,
        ret+= ((LL)y[i].val)*
            (y0>=y[i].pos ? (LL)y0-y[i].pos : (LL)y[i].pos-y0 ) ;
    return ret ;
}

bool better(int x0,int y0)
{
    if(!found) return 1 ;
    LL tmp=cal(x0,y0) ;
    if(tmp!=ans) return tmp<ans ;

    if(2*ansx!=x0+y0) return x0+y0<2*ansx ;
    if(2*ansy!=x0-y0) return x0-y0<2*ansy ;
    return 0 ;
}

void update(int x0,int y0)
{
    if(better(x0,y0))
        ansx=(x0+y0)/2 , ansy=(x0-y0)/2 ,
        ans=cal(x0,y0) , found=1 ;
}

main()
{
    while(scanf("%d",&n)!=EOF)
    {
        for(int i=1;i<=n;i++)
        {
            int a,b,t ; scanf("%d%d%d",&a,&b,&t) ;
            x[i]=(P){a+b,t} ; y[i]=(P){a-b,t} ;
        }
        sort(x+1,x+n+1) ;
        sort(y+1,y+n+1) ;

        found=0 ;
        vector<int> vx,vy ;
        solve(vx,x) ; solve(vy,y) ;
        for(auto i : vx) for(auto j : vy)
        {
            if((i+j)%2==0) update(i,j) ;
            else
            {
                update(i,j-1) , update(i,j+1) ;
                update(i-1,j) , update(i+1,j) ;
            }
        }
        printf("%d %d\n",ansx,ansy) ;
    }
}
