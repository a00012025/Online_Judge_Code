#include<stdio.h>
main()
{
    int T,n,cnt=0;
    scanf("%d",&T) ;
    while(++cnt && cnt<=T)
    {
        scanf("%d",&n) ;
        int a,b ;
        for(int i=1;i<n;i++) scanf("%d%d",&a,&b) ;
        if(n>1)printf("Case #%d: 2\n",cnt) ;
        else printf("Case #%d: 1\n",cnt);
    }
}
