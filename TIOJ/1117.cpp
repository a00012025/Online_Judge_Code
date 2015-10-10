#include<bits/stdc++.h>
using namespace std;

int cal(int x)
{
    int ret=0 ;
    while(x)
    {
        if(x&1) ret++ ;
        x>>=1 ;
    }
    return ret ;
}

main()
{
    int n,m,a,b ;
    while(scanf("%d%d%d%d",&n,&m,&a,&b)!=EOF)
    {
        m-- ; a-- ; b-- ;
        for(int i=a;i<=b;i++)
        {
            if(cal(i&m)%2) printf("+1") ;
            else printf("-1") ;
            printf("%c",i==b?'\n':' ') ;
        }
    }
}
