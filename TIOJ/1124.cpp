#include<bits/stdc++.h>
#define DB double
using namespace std;

struct P{int from,to ; DB p ;};
vector<P> edge ;
vector<int> v[20] ;

DB d[20] ;

DB dp(int x)
{
    if(d[x]>=0.0) return d[x] ;
    DB &ans=d[x] ; ans=0.0 ;
    for(auto i : v[x])
    {
        P &e=edge[i] ;
        ans+= e.p * dp(e.to) ;
    }
    return ans ;
}

DB cal(int st,int ed)
{
    memset(d,-1,sizeof(d)) ;
    d[ed]=1.0 ;
    return dp(st) ;
}

char s[3],t[3] ;
main()
{
    edge={{0,1,0.3},{0,2,0.67},{0,3,0.5},{1,5,0.33},{2,3,0.42},{2,6,0.1},
          {3,5,0.54},{3,9,0.28},{4,7,0.5},{5,4,0.28},{5,8,0.2},{6,8,0.23},
          {6,9,0.36},{7,11,0.4},{8,11,0.41},{9,11,0.37},{9,13,0.47},{11,13,0.5}};
    for(int i=0;i<edge.size();i++)
        v[edge[i].from].push_back(i) ;

    int m ;
    while(scanf("%s%s%d",s,t,&m)!=EOF)
    {
        P e=edge[m-1] ;
        int st=s[0]-'A' , ed=t[0]-'A' ;
        DB x,y,z ;
        if((x=cal(st,ed))==0.0) { printf("No solution\n") ; continue ; }
        if((y=cal(st,e.from))==0.0 || (z=cal(e.to,ed))==0.0)
            { printf("No solution\n") ; continue ; }
        printf("%.8f\n", y*z*e.p/x ) ;
    }
}
