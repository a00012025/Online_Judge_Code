#include<bits/stdc++.h>
using namespace std;
const int maxn=1000000+10 ;

struct P
{
    int x,y,id ;
    bool operator < (const P &rhs) const
    {
        return y==rhs.y ? (x==rhs.x ? id>rhs.id : x>rhs.x) : y>rhs.y ;
    }
};

void normalize(vector<int> &v)
{
    sort(v.begin(),v.end()) ;
    v.resize(unique(v.begin(),v.end())-v.begin()) ;
}

int A,B,n ;
int x[50001],y[50001] ;
vector<int> vx,vy ;
set<P> st[50010] ;
P a[maxn] ;
bool used[maxn] ;

bool check(int num)
{
    memset(used,0,sizeof(used)) ;
    int nownum=0 , j=vx.size() ;
    for(int i=A;i>=1;i--)
    {
        nownum+=num ;
        while(i>1 && x[i-1]==x[i]) nownum+=num , i-- ;
        j-- ;
        for(set<P>::iterator it=st[j].begin();it!=st[j].end();it++)
        {
            used[it->id]=1 ;
            if(!(--nownum)) break ;
        }
    }

    j=B+1 ; nownum=0 ;
    for(int i=1;i<=n;i++)
    {
        while(j>1 && y[j-1]>a[i].y) nownum+=num , j-- ;
        if(!used[i] && (!(nownum--))) return 0 ;
    }
    return 1 ;
}

main()
{
    scanf("%d%d%d",&A,&B,&n) ;
    for(int i=1;i<=A;i++) scanf("%d",&x[i]) , vx.push_back(x[i]) ;
    for(int i=1;i<=B;i++) scanf("%d",&y[i]) , vy.push_back(y[i]) ;
    sort(x+1,x+A+1) ;
    sort(y+1,y+B+1) ;
    normalize(vx) ; normalize(vy) ;
    for(int i=1;i<=n;i++) scanf("%d%d",&a[i].x,&a[i].y) ;
    sort(a+1,a+n+1) ;
    for(int i=1;i<=n;i++)
    {
        a[i].id=i ;
        int id=upper_bound(vx.begin(),vx.end(),a[i].x)-vx.begin() ;
        st[id].insert(a[i]) ;
    }

    int l=0 , r=2*n+1 ;
    while(r-l>1)
    {
        int mid=(r+l)/2 ;
        if(check(mid)) r=mid ;
        else l=mid ;
    }
    printf("%d\n",r==2*n+1 ? -1 : r) ;
}
