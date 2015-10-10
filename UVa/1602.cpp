#include<stdio.h>
#include<set>
#include<algorithm>
#define FOR_CELL(c, p) for(Polyomino::iterator c = (p).begin(); c != (p).end(); ++c)
using namespace std;
struct Cell
{
    int x,y;
    bool operator < (const struct Cell &rhs) const
    {
        if(x!=rhs.x) return x<rhs.x ;
        else return y<rhs.y ;
    }
};
typedef set<Cell> Polyomino ;
set<Polyomino> poly[11] ;
int ans[11][11][11] ;

const int dx[]={1,-1,0,0} , dy[]={0,0,1,-1} ;

inline Polyomino normalize(const Polyomino& p)
{
    int min1=1000 , min2=1000 ;
    FOR_CELL(it,p)
    {
        min1=min(min1,it->x) ;
        min2=min(min2,it->y) ;
    }
    Polyomino ret ;
    FOR_CELL(it,p)
        ret.insert((Cell){it->x - min1,it->y - min2}) ;
    return ret ;
}

inline Polyomino Rotate(const Polyomino& p)
{
    Polyomino ret ;
    FOR_CELL(it,p)
        ret.insert((Cell){it->y , -(it->x)}) ;
    return normalize(ret) ;
}

inline Polyomino Flip(const Polyomino& p)
{
    Polyomino ret ;
    FOR_CELL(it,p)
        ret.insert((Cell){it->x , -(it->y)}) ;
    return normalize(ret) ;
}

void check(const Polyomino& p,const Cell& c)
{
    Polyomino p2=p ;
    p2.insert(c) ;
    p2=normalize(p2) ;
    int n=p2.size() ;
    for(int i=0;i<4;i++)
    {
        if(poly[n].count(p2)) return ;
        p2=Rotate(p2) ;
    }
    p2=Flip(p2) ;
    for(int i=0;i<4;i++)
    {
        if(poly[n].count(p2)) return ;
        p2=Rotate(p2) ;
    }
    poly[n].insert(p2) ;
}

void pre_calculate()
{
    Polyomino p ;
    p.insert((Cell){0,0}) ;
    poly[1].insert(p) ;
    for(int n=2;n<=10;n++)
        for(set<Polyomino>::iterator it=poly[n-1].begin();it!=poly[n-1].end();it++)
            FOR_CELL(it2,*it)
            for(int i=0;i<4;i++)
            {
                Cell nc=(Cell){it2->x + dx[i],it2->y + dy[i]} ;
                if(!(*it).count(nc)) check(*it , nc) ;
            }
    for(int n=1;n<=10;n++)
        for(int w=1;w<=10;w++)
            for(int h=1;h<=10;h++)
    {
        ans[n][w][h]=0 ;
        for(set<Polyomino>::iterator it=poly[n].begin();it!=poly[n].end();it++)
        {
            int max1=0 , max2=0 ;
            FOR_CELL(it2,*it)
            {
                max1=max(max1,it2->x) ;
                max2=max(max2,it2->y) ;
            }
            if(min(max1,max2)<min(w,h) && max(max1,max2)<max(w,h))
                ans[n][w][h]++ ;
        }
    }
}

main()
{
    pre_calculate() ;
    int n,w,h ;
    while(scanf("%d%d%d",&n,&w,&h)==3)
    {
        printf("%d\n",ans[n][w][h]) ;
    }
}
