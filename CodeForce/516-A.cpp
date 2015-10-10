#include<bits/stdc++.h>
#define LL long long
using namespace std;

int num[5],p[]={2,3,5,7} ;
char s[20] ;
main()
{
    int n ; scanf("%d%s",&n,s+1) ;
    for(int i=1;i<=n;i++)
    {
        int x=s[i]-'0' ;
        if(x>=7)
        {
            num[3]++ ;
            if(x==8) num[0]+=3 ;
            if(x==9) num[1]+=2 , num[0]++ ;
        }
        else if(x>=5)
        {
            num[2]++ ;
            if(x==6) num[1]++ ;
        }
        else if(x>=3)
        {
            num[1]++ ;
            if(x==4) num[0]+=2 ;
        }
        else if(x==2) num[0]++ ;
    }
    for(int i=3;i>=0;i--) while(num[i]--) printf("%d",p[i]) ;
    printf("\n") ;
}
