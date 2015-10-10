#include<bits/stdc++.h>
#include"lib1088.h"

main()
{
    int a[4] ;
    Initialize(&a[1],&a[2],&a[3]) ;
    while(1)
    {
        int p,num ;
        for(int i=1;i<=2;i++) for(int j=i+1;j<=3;j++)
            if(!a[i] && !a[j])
        {
            Take_Stone(6-i-j,a[6-i-j],&p,&num) ;
            return 0 ;
        }
        bool ok=0 ;
        for(int i=1;!ok && i<=2;i++) for(int j=i+1;!ok && j<=3;j++)
        {
            int x=(a[i]^a[j]) ;
            if(x>=a[6-i-j]) continue ;
            ok=1 ;
            Take_Stone(6-i-j,a[6-i-j]-x,&p,&num) ;
            a[6-i-j]=x ;
            a[p]-=num ;
        }
    }
}
