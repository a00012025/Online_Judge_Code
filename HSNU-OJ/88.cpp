#include<bits/stdc++.h>
#define INF 10000000
using namespace std;

char s[1000001] ;
int a[1000001],last[3000001] ;
int vis[3000001] ;
main()
{
    int n,Q ; scanf("%d%d%s",&n,&Q,s+1) ;
    for(int i=1;i<=n;i++) a[i]= s[i]=='T' ? 2 : 1 ;
    int fir ;
    for(fir=1 ; a[fir]==2 ; fir++) ;
    int sum=0 ;// vis[0]=fir-1 ;
    for(int i=fir;i<=n;i++) {sum+=a[i] ; if(sum<=3000000) vis[sum]=i ;}
    for(int i=1;i<=3000000;i++)
    {
        if(vis[i]) { last[i]=0 ; continue ; }
        if(i<=2) { last[i]=INF ; continue ; }
        last[i]=last[i-2]+1 ;
    }
    while(Q--)
    {
        int val ; scanf("%d",&val) ;
        if(val<=sum)
        {
            if(vis[val]) printf("%d %d\n",fir,vis[val]) ;
            else printf("%d %d\n",fir+1,vis[val+1]) ;
            continue ;
        }
        int las=last[val] ;
        if(las > fir-1) { printf("NIE\n") ; continue ; }
        int val2=val-2*las ;
        printf("%d %d\n",fir-las,vis[val2]) ;
    }
}
