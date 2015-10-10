#include<stdio.h>
#include<string.h>
#include<queue>
#include<vector>
using namespace std;
main()
{
    vector<int> anc[10001],dec[10001] ; // 祖先,子孫
    queue<int> q ;
    int d[10001],n,m ; // 出度
    bool win[10001] ;
    char s[10] ;
    while(scanf("%d %d",&n,&m)==2)
    {
        if(!n && !m) break ;
        for(int i=0;i<=n;i++){anc[i].clear();dec[i].clear();}
        memset(win,0,sizeof(win)) ;
        memset(d,0,sizeof(d)) ;
        while(!q.empty()) q.pop() ;
        for(int i=1;i<=m;i++)
        {
            int a,b ;
            scanf("%d %d",&a,&b) ;
            d[a]++ ;
            anc[b].push_back(a) ; dec[a].push_back(b) ;
        }
        q.push(n) ; win[n]=1 ;
        while(!q.empty())
        {
            int x=q.front() ;
            q.pop() ;
            for(int i=0;i<anc[x].size();i++)
            {
                d[anc[x][i]]-- ;
                if(!d[anc[x][i]]) q.push(anc[x][i]) ;
            }
            if(x==n) continue ;
            bool b=0 ;
            for(int i=0;i<dec[x].size();i++)
                b=b||win[dec[x][i]] ;
            win[x]=!b ;
        }
        gets(s) ;
        while(s[0]!='M') gets(s);
        if(s[1]=='i' && win[1]==1) printf("Mimi\n") ;
        if(s[1]=='i' && win[1]==0) printf("Moumou\n") ;
        if(s[1]=='o' && win[1]==1) printf("Moumou\n") ;
        if(s[1]=='o' && win[1]==0) printf("Mimi\n") ;
    }
}
