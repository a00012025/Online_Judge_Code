#include<bits/stdc++.h>
using namespace std;

int cal(int x,int y)
{
    if(x%y==0) return x/y ;
    return cal(y,x%y)+x/y ;
}

main()
{
    int a,b ;
    while(scanf("%d%d",&a,&b)!=EOF) printf("%d\n",cal(a,b)) ;
}
