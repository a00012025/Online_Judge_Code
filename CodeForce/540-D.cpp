#include<bits/stdc++.h>
#define DB double
using namespace std;
const int maxn=100+5 ;

struct P{DB x,y,z;};
P operator * (const P &a,const DB &b){return (P){b*a.x,b*a.y,b*a.z};}
P operator / (const P &a,const DB &b){return a*(1/b);}
P operator + (const P &a,const P &b){return (P){a.x+b.x,a.y+b.y,a.z+b.z};}

P d[maxn][maxn][maxn] ;
P dp(int a,int b,int c)
{
    if(d[a][b][c].x>=-0.5) return d[a][b][c] ;
    P &ans=d[a][b][c] ;

    if(!a && !b) return ans=(P){0,0,1} ;
    if(!b && !c) return ans=(P){1,0,0} ;
    if(!c && !a) return ans=(P){0,1,0} ;
    if(a&&b&&!c) return ans=(P){1,0,0} ;
    if(b&&c&&!a) return ans=(P){0,1,0} ;
    if(c&&a&&!b) return ans=(P){0,0,1} ;
    return ans=(dp(a-1,b,c)*a*c+dp(a,b-1,c)*a*b+dp(a,b,c-1)*b*c)/(a*b+b*c+c*a) ;
}

main()
{
    int x,y,z ; scanf("%d%d%d",&x,&y,&z) ;
    for(int i=0;i<=x;i++) for(int j=0;j<=y;j++)
        for(int k=0;k<=z;k++) d[i][j][k].x=-1 ;
    P ans=dp(x,y,z) ;
    printf("%.10f %.10f %.10f\n",ans.x,ans.y,ans.z) ;
}
