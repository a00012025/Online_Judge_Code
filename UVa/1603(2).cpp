#include<stdio.h>
#include<algorithm>
#include<map>
#include<vector>
#define mkp(x,y) make_pair(x,y)
using namespace std;
vector< vector<int> > square ;
bool now[61] ;
struct int4
{
    int x1,y1,x2,y2;
    bool operator < (const int4 &rhs) const
    {
        if(x1!=rhs.x1) return x1<rhs.x1 ;
        if(y1!=rhs.y1) return y1<rhs.y1 ;
        if(x2!=rhs.x2) return x2<rhs.x2 ;
        if(y2!=rhs.y2) return y2<rhs.y2 ;
        return 0;
    }
};
map< int4 , int > mp ;
int n,maxd;

void init()
{
    mp.clear() ;
    square.clear() ;
    for(int i=1;i<=2*n*(n+1);i++) now[i]=1 ;
    for(int i=0;i<=n;i++) for(int j=0;j<n;j++)
    {
        mp[(int4){i,j,i,j+1}]=i*(2*n+1)+j+1 ;
        mp[(int4){i,j+1,i,j}]=i*(2*n+1)+j+1 ;
    }
    for(int i=0;i<n;i++) for(int j=0;j<=n;j++)
    {
        mp[(int4){i,j,i+1,j}]=(2*n+1)*i+n+1+j ;
        mp[(int4){i+1,j,i,j}]=(2*n+1)*i+n+1+j  ;
    }
    for(int i=0;i<n;i++) for(int j=0;j<n;j++)
    {
        int max_len=min(n-i,n-j) ;
        for(int k=1;k<=max_len;k++)
        {
            vector<int> edge ;
            for(int z=i;z<i+k;z++) edge.push_back(mp[(int4){z,j,z+1,j}]);
            for(int z=j;z<j+k;z++) edge.push_back(mp[(int4){i,z,i,z+1}]);
            for(int z=i;z<i+k;z++) edge.push_back(mp[(int4){z,j+k,z+1,j+k}]);
            for(int z=j;z<j+k;z++) edge.push_back(mp[(int4){i+k,z,i+k,z+1}]);
            square.push_back(edge) ;
        }
    }
}

struct P {int val,id;};
bool comp(P x,P y)
{return x.val>y.val ;}

int estimate(P *d,int square_num)
{
    int ret=1,sum=0 ;
    for(;d[ret].val && sum<square_num;ret++) sum+=d[ret].val ;
    if(sum<square_num) return 1000000 ;
    return ret-1 ;
}

bool iddfs(int num)
{
    P d[61] ; int square_num=0 ;
    for(int i=1;i<=2*n*(n+1);i++) d[i]=(P){0,i} ;
    for(int i=0;i<square.size();i++)
    {
        bool yes=1 ;
        for(int j=0;j<square[i].size();j++)
            if(!now[square[i][j]]) {yes=0 ; break ;}
        if(yes)
        {
            square_num++ ;
            for(int j=0;j<square[i].size();j++)
                d[square[i][j]].val++ ;
        }
    }

    if(num==maxd)
    {
        if(square_num==0) return 1;
        else return 0;
    }

    sort(d+1,d+2*n*(n+1)+1,comp) ;

    if(num+estimate(d,square_num) > maxd) return 0;

    for(int i=1;i<=2*n*(n+1) && d[i].val==d[1].val;i++)
    {
        now[d[i].id]=0 ;
        if(iddfs(num+1)) return 1;
        now[d[i].id]=1 ;
    }
    return 0;
}

main()
{
    int T;
    scanf("%d",&T) ;
    while(T--)
    {
        scanf("%d",&n) ;
        init() ;
        int m ; scanf("%d",&m) ;
        while(m--)
        {
            int x ; scanf("%d",&x) ;
            now[x]=0 ;
        }
        maxd=0 ;
        for(;;maxd++) if(iddfs(0)) break ;
        printf("%d\n",maxd) ;
    }
}
