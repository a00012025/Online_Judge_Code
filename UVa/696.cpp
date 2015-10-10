#include<stdio.h>
#include<algorithm>
using namespace std;
main()
{
    int a,b,ans ;
    while(scanf("%d %d",&a,&b)==2)
    {
        if(!a && !b) break;
        if(a==2)
        {
            if(b%4==1) ans=b+1 ;
            else if(b%4==2) ans=b+2 ;
            else if(b%4==3) ans=b+1 ;
            else ans=b ;
        }
        else if(b==2)
        {
            if(a%4==1) ans=a+1 ;
            else if(a%4==2) ans=a+2 ;
            else if(a%4==3) ans=a+1 ;
            else ans=a ;
        }
        else if(a==1) ans=b ;
        else if(b==1) ans=a ;
        else ans=((a*b)+1)/2 ;
        printf("%d knights may be placed on a %d row %d column board.\n",ans,a,b);
    }
}
