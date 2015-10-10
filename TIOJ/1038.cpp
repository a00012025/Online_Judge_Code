#include<bits/stdc++.h>
using namespace std;
const int maxn=300 ;
struct P
{
    char c[10] ;
    void rotate()
    {
        for(int i=0;i<3;i++) swap(c[i],c[3]) ;
        for(int i=7;i>4;i--) swap(c[i],c[4]) ;
    }
};

P p[maxn] ;
int n,m,sz ;
bool used[maxn] ;
char now[maxn][maxn] ;
vector<int> v[30] ;

bool dfs(int x,int y)
{
    if(x==n)
    {
        for(int i=0;i<n;i++) printf("%s\n",now[i]) ;
        return 1 ;
    }

    for(int i=0;i<n*m;i++) if(!used[i])
    {

    }

    return 0 ;
}

main()
{

    while(scanf("%d%d",&n,&m)==2 && n+m)
    {
        gets(p[0].c) ;
        for(int i=1,cnt=0;i<=n;i++) for(int j=1;j<=m;j++)
        {
            gets(p[cnt].c) ;
            for(int k=0;k<4;k++)
            {
                char c=p[cnt].c[k] ;
                if(c>='a' && c<=)
            }
            cnt++ ;
        }
        dfs(0,0) ;
    }
}
