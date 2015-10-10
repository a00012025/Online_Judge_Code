#include<stdio.h>
main()
{
    int n,a[101];
    while(scanf("%d",&n)!=EOF)
    {
        for(int i=1;i<=n;i++) scanf("%d",&a[i]) ;
        int last=0 ;
        for(int i=1;i<=n;i++)
        {
            if(a[i]>=last+31) break ;
            if(a[i]<=last) last+=5 ;
            else last=a[i]+4 ;
        }
        printf("%d\n",last==0 ? 30 : last+31) ;
    }
}
