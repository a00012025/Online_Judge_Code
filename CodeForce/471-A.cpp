#include<stdio.h>
#include<algorithm>
using namespace std;

bool comp(int x,int y)
{
    return x>y ;
}

main()
{
    int num[10]={0} ;
    for(int i=1;i<=6;i++)
    {
        int x ;
        scanf("%d",&x) ;
        num[x]++ ;
    }
    sort(num+1,num+10,comp) ;
    if(num[1]==4 && num[2]==2) printf("Elephant\n") ;
    else if(num[1]==6) printf("Elephant\n") ;
    else if(num[1]>=4) printf("Bear\n") ;
    else printf("Alien\n") ;
}
