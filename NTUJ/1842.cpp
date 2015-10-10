#include<bits/stdc++.h>
using namespace std;

int c1[40],c2[40] ;
main()
{
    int n ;
    while(scanf("%d",&n)!=EOF)
    {
        memset(c1,0,sizeof(c1)) ;
        memset(c2,0,sizeof(c2)) ;
        for(int i=1;i<=n;i++)
        {
            int x ; scanf("%d",&x) ;
            for(int j=0;j<31;j++) if(x&(1<<j))
                c1[j]++ ;
        }
        for(int i=1;i<=n;i++)
        {
            int x ; scanf("%d",&x) ;
            for(int j=0;j<31;j++) if(x&(1<<j))
                c2[j]++ ;
        }
        int ans=0 ;
        for(int i=0;i<31;i++)
        {
            if(c1[i]==c2[i]) continue ;
            if(c1[i]+c2[i]==n) ans|=(1<<i) ;
            else{ans=-1 ; break ;}
        }
        printf("%d\n",ans) ;
    }
}
