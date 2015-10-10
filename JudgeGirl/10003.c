#include<stdio.h>
int k ;
main()
{
    int n ; scanf("%d",&k) ;
    int x=0,y=0,ans=0 ;
    while(scanf("%d",&n)==1 && n)
    {
        if((x%2==0&&n>0) || (x%2==1&&n<0))
        {
            y++ ;
            if(y==k) x++ , y=0 ;
            if(x>1 && x%2 && x*k>ans) ans=x*k ;
        }
        else if(x%2==1 && !y) x=1 , y=0 ;
        else if(x%2==1) x=0 , y=1 ;
        else x=y=0 ;
    }
    printf("%d\n",ans) ;
}
