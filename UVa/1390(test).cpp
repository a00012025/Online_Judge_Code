#include<bits/stdc++.h>
using namespace std;
int cnt=0 ;

void dfs(int last,int x)
{
    if(x==30) {cnt++ ; return ; }
    for(int i=last;x+i<=30;i++) dfs(i,x+i) ;
}
main()
{
    dfs(1,0) ;
    printf("%d\n",cnt) ;
}
