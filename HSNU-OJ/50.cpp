#include<bits/stdc++.h>
using namespace std;

int a[70000] ;
bool vis[70000]={0} ;
vector<int> v1,v2 ;
main()
{
    int n ; scanf("%d",&n) ;
    for(int i=1;i<=n;i++) scanf("%d",&a[i]) ;
    char s[10] ;
    while(scanf("%s",s)!=EOF)
    {
        if(s[0]=='C') break ;
        int x ; scanf("%d",&x) ;
        if(s[0]=='A') v1.push_back(x) ;
        else v2.push_back(x) ;
        vis[x]=1 ;
    }
    bool fir=1 ;
    for(int i=((int)v1.size())-1;i>=0;i--)
    {
        if(fir) fir=0 ;
        else printf(" ") ;
        printf("%d",v1[i]) ;
    }
    for(int i=1;i<=n;i++) if(!vis[a[i]])
    {
        if(fir) fir=0 ;
        else printf(" ") ;
        printf("%d",a[i]) ;
    }
    for(int i=0;i<v2.size();i++)
    {
        if(fir) fir=0 ;
        else printf(" ") ;
        printf("%d",v2[i]) ;
    }
    printf("\n") ;
}
