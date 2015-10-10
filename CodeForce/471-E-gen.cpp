#include<bits/stdc++.h>
using namespace std;
const int maxn=20 ;

main()
{
    freopen("in","w",stdout) ;
    srand(time(NULL)) ;
    int n=10+rand()%7 ; printf("%d\n",n) ;
    while(n--)
    {
        int t=(rand()&(1<<12))?1:0 ;
        int a=rand()%maxn , b=rand()%maxn , c=rand()%maxn ;
        while(b==c) b=rand()%maxn , c=rand()%maxn ;
        if(!t) printf("%d %d %d %d\n",a,b,a,c) ;
        else printf("%d %d %d %d\n",b,a,c,a) ;
    }
}
