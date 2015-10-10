#include<bits/stdc++.h>
#define INF 50000000
using namespace std;
const int maxn=400000+10 ;

int x,y ;
int ans[maxn] ;

int nex[maxn],las[maxn] ;
int size,head ;
void erase(int x)
{
    size-- ;
    if(x==head) head=nex[x] ;
    else nex[las[x]]=nex[x] , las[nex[x]]=las[x] ;
}

main()
{
    int n ; scanf("%d%d%d",&n,&x,&y) ;
    int g=__gcd(x,y) ;
    if(n!=-1 && n>x+y-g-1)
        { printf("Impossible\n") ; return 0 ; }
    else
    {
        n=x+y-g-1 ;
        if(n<x || n<y) { printf("Impossible\n") ; return 0 ; }
    }

    size=0 ; head=0 ;
    for(int i=0;i*g<=n;i++)
    {
        size++ ;
        if((i+1)*g>n) nex[i*g]=0 ;
        else nex[i*g]=(i+1)*g , las[(i+1)*g]=i*g ;
    }

    while(size>0)
    {
        int tmp=head , now=head ;
        ans[now]=0 ; erase(now) ;
        for(int type=0;;type^=1)
        {
            if(now+x > n && now-y < 0) break ;
            if(type==0) while(now+x<=n)
                ans[now+x]=ans[now]+1 , now+=x , erase(now) ;
            else while(now-y>=0)
                ans[now-y]=ans[now]+1 , now-=y , erase(now) ;
        }
        now=tmp ;
        for(int type=0;;type^=1)
        {
            if(now-x < 0 && now+y > n) break ;
            if(type==0) while(now-x>=0)
                ans[now-x]=ans[now]-1 , now-=x , erase(now) ;
            else while(now+y<=n)
                ans[now+y]=ans[now]-1 , now+=y , erase(now) ;
        }
    }

    for(int i=1;i<=n;i++) if(i%g) ans[i]=ans[i/g*g] ;

    printf("%d\n",n) ;
    for(int i=1;i<=n;i++) printf("%d%c",ans[i]-ans[i-1],i==n?'\n':' ') ;
}
