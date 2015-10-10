#include<stdio.h>
main()
{
    int T,tc=0;
    scanf("%d",&T);
    while(T--)
    {
        int n,ans=0;
        char s[200] ;
        scanf("%d %s",&n,s) ;
        for(int i=0;i<n;i++) if(s[i]=='.') {ans++ ; i+=2 ;}
        printf("Case %d: %d\n",++tc,ans) ;
    }
}
