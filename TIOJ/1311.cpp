#include<bits/stdc++.h>
using namespace std;

main()
{
    int z;
    while(scanf("%d",&z)==1 && z)
    {
        int x1,y1,x2,y2 ;
        scanf("%d%d%d%d",&x1,&x2,&y1,&y2) ;
        for(int i=y1;i<=y2;i++)
        {
            int g=__gcd(i,z) ;
            for(int j=x1;j<=x2;j++)
            {
                if(__gcd(g,j)==1) printf("*") ;
                else printf(".") ;
                if(j==x2) printf("\n") ;
            }
        }
        printf("--\n") ;
    }
}
