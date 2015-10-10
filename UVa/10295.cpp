#include<stdio.h>
#include<string>
#include<map>
using namespace std;
map< string,int > mp ;
main()
{
    int n,m ;
    scanf("%d %d",&n,&m) ;
    for(int i=1;i<=n;i++)
    {
        char c[100] ;
        int a ;
        scanf("%s %d",c,&a) ;
        mp[c]=a ;
    }
    for(int i=1;i<=m;i++)
    {
        char c[100] ;
        int ans=0 ;
        while(1)
        {
            scanf("%s",c) ;
            if(c[0]=='.') break ;
            if(mp.count(c)) ans+=mp[c] ;
        }
        printf("%d\n",ans) ;
    }
}
