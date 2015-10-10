#include<bits/stdc++.h>
using namespace std;
char G[200][200] ;
main()
{
    int n,m ;
    while(scanf("%d%d",&n,&m)!=EOF)
    {
        for(int i=0;i<n;i++) scanf("%s",G[i]) ;
        int ans=0 ;
        for(int i=0;i<n;i++)
        {
            int num=0 ;
            for(int j=0;j<m;j++)
            {
                if(G[i][j]!='.') ans+=1 , num++ ;
                else ans+=2*(num%2) ;
            }
        }
        printf("%d\n",ans/2) ;
    }
}
