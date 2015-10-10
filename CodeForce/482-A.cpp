#include<bits/stdc++.h>
main()
{
    int n,k ; scanf("%d%d",&n,&k) ;
    int now=1 ; printf("1") ;
    for(int i=k;i>=1;i--)
    {
        if(i%2 == k%2) now+=i ;
        else now-=i ;
        printf(" %d",now) ;
    }
    if(k<n-1)
    {
        printf(" %d",k+2) ;
        for(int i=k+3;i<=n;i++) printf(" %d",i) ;
    }
    printf("\n") ;
}
