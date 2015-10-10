#include<bits/stdc++.h>
using namespace std;
const int maxn=20000+10 ;
int ch[5000000][2],ccnt ;
int now[maxn],n ;

void insert()
{
    int u=0 ;
    for(int i=1;i<=n;i++)
    {
        if(!ch[u][now[i]])
        {
            ccnt++ ;
            memset(ch[ccnt],0,sizeof(ch[ccnt])) ;
            ch[u][now[i]]=ccnt ;
        }
        u=ch[u][now[i]] ;
    }
}

void print_ans(int u,int dep)
{
    if(dep==n)
    {
        for(int i=1;i<=n;i++) printf("%d",now[i]) ;
        printf("\n") ;
        return ;
    }
    if(ch[u][0])
    {
        now[dep+1]=0 ;
        print_ans(ch[u][0],dep+1) ;
    }
    if(ch[u][1])
    {
        now[dep+1]=1 ;
        print_ans(ch[u][1],dep+1) ;
    }
}

inline void flip(int x)
{
    for(int i=x;i<=n;i+=x) now[i]^=1 ;
}

main()
{
    int k,m ;
    bool fir=1 ;
    while(scanf("%d%d%d",&n,&k,&m)==3 && n+k+m)
    {
        memset(ch[0],0,sizeof(ch[0])) ; ccnt=0 ;

        for(int i=0;i<(1<<k);i++)
        {
            int num=0 ;
            for(int j=0;j<k;j++) if(i&(1<<j)) num++ ;
            if(num>m || (m-num)%2) continue ;
            fill(now+1,now+n+1,1) ;
            for(int j=0;j<k;j++) if(i&(1<<j)) flip(j+1) ;
            insert() ;
        }
        if(fir) fir=0 ;
        else printf("\n") ;
        print_ans(0,0) ;
    }
}
