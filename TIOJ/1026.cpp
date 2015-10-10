#include<bits/stdc++.h>
using namespace std;
char ans[20] ;

void solve(int n,int num,int M)
{
    if(n==0) return ;
    int M2=(M-1)/2 ;
    if(n+M2+1 <= M2 && n+M2+1>=-M2) solve(n+M2+1,num-1,M2) , printf("-") ;
    else solve(n-M2-1,num-1,M2) , printf("+") ;
}

main()
{
    int n ; scanf("%d",&n) ;
    int num=1 , now=1 ;
    while(now<n) now=now*2+1 , num++ ;
    printf("%d\n",num) ;
    solve(n,num,now) ;
    printf("\n") ;
}
