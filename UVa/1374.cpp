#include<stdio.h>
#include<set>
#include<stdlib.h>
#define LL long long
using namespace std;
int now[20] ;
int n,maxd;

bool iddfs(int num)
{
    if(num==maxd)
    {
        if(now[num+1]==n) return 1;
        else return 0;
    }
    int M=0 ;
    for(int i=1;i<=num+1;i++) M=max(M,now[i]) ;
    if( (M<<(maxd-num)) < n) return 0;
    for(int i=num+1;i>=1;i--)
    {
        int t=now[num+1]+now[i] ;
        if(t<=n || M<=n)
        {
            now[num+2]=t ;
            if(iddfs(num+1)) return 1;
        }
        t=now[num+1]>now[i] ? now[num+1]-now[i] : now[i]-now[num+1] ;
        if(!t) continue ;
        now[num+2]=t ;
        if(iddfs(num+1)) return 1;
    }
    return 0;
}

main()
{
        //freopen("0.txt","r",stdin) ;
        //freopen("2.txt","w",stdout) ;
    while(scanf("%d",&n)==1 && n)
    {
        maxd=0 ;
        for(;;maxd++)
        {
            now[1]=1 ;
            if(iddfs(0)) break ;
        }
        printf("%d\n",maxd) ;
    }
}
