#include<bits/stdc++.h>
#define LL long long
using namespace std;

main()
{
    int A,B ; scanf("%d%d",&A,&B) ;
    int num1=0 , num2=0 , tmp1=A , tmp2=B ;
    while(tmp1) num1++ , tmp1/=2 ;
    while(tmp2) num2++ , tmp2/=2 ;

    int i ;
    for(i=0;i<min(num1,num2);i++)
    {
        int x= A&(1<<(num1-1-i)) ;
        int y= B&(1<<(num2-1-i)) ;
        if((x&&!y) || (y&&!x)) break ;
    }
    printf("%d\n",num1+num2-2*i) ;
}
