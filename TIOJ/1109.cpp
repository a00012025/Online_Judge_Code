#include<bits/stdc++.h>
using namespace std;
char s[200] ;
main()
{
    int n,k ;
    while(scanf("%d%d",&n,&k)!=EOF)
    {
        for(int i=n;i>=1;i--)
        {
            scanf("%s",s) ;
            if(i==k) printf("%s\n",s) ;
        }
    }
}
