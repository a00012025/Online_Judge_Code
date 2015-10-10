#include<bits/stdc++.h>
#define FOR(i,l,r) for(int i=l;i<=r;i++)
using namespace std;
bool vis[41][41][41][41] ;
int a[41][4],d1[]={1,0,0,0},d2[]={0,1,0,0},d3[]={0,0,1,0},d4[]={0,0,0,1} ;
set<int> st[41][41][41][41] ;
main()
{
    int n;
    while(scanf("%d",&n)==1 && n)
    {
        for(int i=1;i<=n;i++) scanf("%d%d%d%d",&a[i][0],&a[i][1],&a[i][2],&a[i][3]) ;

        memset(vis,0,sizeof(vis)) ;
        queue<int> q ; FOR(z,1,4) q.push(0) ;
        vis[0][0][0][0]=1 ; st[0][0][0][0].clear() ;
        int ans=0 ;
        while(!q.empty())
        {
            int x=q.front() ; q.pop() ;
            int y=q.front() ; q.pop() ;
            int z=q.front() ; q.pop() ;
            int w=q.front() ; q.pop() ;
            int sz=st[x][y][z][w].size() ;
            ans=max(ans,(x+y+z+w-sz)/2) ;
            if(sz==5) continue ;
            for(int k=0;k<4;k++)
            {
                int nx=x+d1[k] , ny=y+d2[k] , nz=z+d3[k] , nw=w+d4[k] ;
                if(nx>n || ny>n || nz>n || nw>n) continue ;
                if(!vis[nx][ny][nz][nw])
                {
                    int val= k==0?(a[nx][0]):(k==1?(a[ny][1]):(k==2?(a[nz][2]):(a[nw][3]))) ;
                    if(!st[x][y][z][w].count(val))
                    {
                        st[nx][ny][nz][nw]=st[x][y][z][w] ;
                        st[nx][ny][nz][nw].insert(val) ;
                        vis[nx][ny][nz][nw]=1 ;
                        q.push(nx) ; q.push(ny) ; q.push(nz) ; q.push(nw) ;
                    }
                    else
                    {
                        st[nx][ny][nz][nw]=st[x][y][z][w] ;
                        st[nx][ny][nz][nw].erase(val) ;
                        vis[nx][ny][nz][nw]=1 ;
                        q.push(nx) ; q.push(ny) ; q.push(nz) ; q.push(nw) ;
                    }
                }
            }
        }
        printf("%d\n",ans) ;
    }
}
