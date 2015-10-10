#include<bits/stdc++.h>
using namespace std;

int h[2000],now[20000] ;
char s[2000] ;
int n,m ;
main()
{
    scanf("%d%d",&n,&m) ; gets(s) ;
    memset(h,0,sizeof(h)) ;
    memset(now,0,sizeof(now)) ;
    now[0]=n ;
    int maxm=0,ans=0 ;
    for(int i=1;i<=n;i++)
    {
        gets(s) ;
        for(int j=0;j<m;j++)
        {
            now[h[j]]-- ;
            h[j]= s[j]=='1' ? h[j]+1 : 0 ;
            now[h[j]]++ ;
            maxm=max(maxm,h[j]) ;
            if(now[maxm]==0) for(;now[maxm]==0;maxm--) ;
        }
        int x=0 ;
        for(int j=maxm;j>=1;j--) x+=now[j] , ans=max(ans,x*j) ;
    }
    printf("%d\n",ans) ;
}
