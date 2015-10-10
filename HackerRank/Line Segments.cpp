#include<bits/stdc++.h>
using namespace std;
const int maxn=100000+10 ;

struct P
{
    int x,y ;
    void scan(){scanf("%d%d",&x,&y) ;}
    bool operator < (const P &rhs) const
    {
        return x==rhs.x ? y>rhs.y : x<rhs.x ;
    }
};

P a[maxn] ;
int d[maxn] ;
int main()
{
    int n ; scanf("%d",&n) ;
    for(int i=0;i<n;i++) a[i].scan() ;
    sort(a,a+n) ;
    int num=0 ;
    for(int i=0;i<n;i++)
    {
        int x=a[i].y ;
        int id=lower_bound(d,d+num+1,x)-d-1 ;
        d[id+1]=x ;
        if(id==num) num++ ;
    }
    printf("%d\n",num) ;
}
