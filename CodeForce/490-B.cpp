#include<bits/stdc++.h>
#define F first
#define S second
using namespace std;
const int maxn=200000+10,maxc=1000000+10 ;

map<int,int> mp,mp2 ;
int ans[maxn],have[maxc],in[maxc] ;
main()
{
    int n ; scanf("%d",&n) ;
    int a,b ;
    for(int i=1;i<=n;i++)
    {
        int x,y ; scanf("%d%d",&x,&y) ;
        have[x]=have[y]=1 ;
        if(x) mp[x]=y ;
        else b=y ;
        if(y) mp2[y]=x , in[y]=1 ;
    }
    for(int i=0;i<maxc;i++) if(i!=b && have[i] && !in[i]) a=i ;
    for(int i=1,j=a;i<=n;i+=2,j=mp[j]) ans[i]=j ;
    for(int i=2,j=b;i<=n;i+=2,j=mp[j]) ans[i]=j ;
    for(int i=1;i<=n;i++) printf("%d%c",ans[i],i==n?'\n':' ') ;
}
