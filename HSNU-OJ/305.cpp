#include<bits/stdc++.h>
using namespace std;
const int maxn=1000000,INF=1000000000 ;
int d[maxn+10],dis[]={0,2,3,2,3,3,3} ;
bool inq[maxn+10] ;

int f(int a,int x)
{
    switch(x)
    {
        case 1 : return a+1 ;
        case 2 : return a+2 ;
        case 3 : return a-1 ;
        case 4 : return a-2 ;
        case 5 : return a*2 ;
        case 6 : return a/2 ;
    }
}

main()
{
    int a,b ; scanf("%d%d",&a,&b) ;
    for(int i=0;i<=maxn;i++) d[i]=INF ;
    memset(inq,0,sizeof(inq)) ;
    d[a]=0 ;
    queue<int> q ; q.push(a) ; inq[a]=1 ;
    while(!q.empty())
    {
        int u=q.front() ; q.pop() ; inq[u]=0 ;
        for(int i=1;i<=6;i++)
        {
            int newu=f(u,i) ;
            if(newu<0 || newu>maxn) continue ;
            if(d[newu]>d[u]+dis[i])
            {
                d[newu]=d[u]+dis[i] ;
                if(!inq[newu]) q.push(newu) ;
                inq[newu]=1 ;
            }
        }
    }
    printf("%d\n",d[b]) ;
}
