#include<stdio.h>
int ans[550000] ;
main()
{
    ans[1]=1 ; ans[2]=2 ; ans[3]=2 ; ans[4]=4 ;
    for(int i=5;i<=500000;i++)
    {
        if(i%2==0) ans[i]=2*ans[i/2] ;
        else if(ans[(i+1)/2]==1) ans[i]=i ;
        else ans[i]=(2*ans[(i+1)/2])-2 ;
    }
    int n;
    while(scanf("%d",&n)==1 && n) printf("%d\n",ans[n]) ;
}
