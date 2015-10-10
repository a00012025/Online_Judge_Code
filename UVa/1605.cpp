#include<stdio.h>
char ch[60] ;
main()
{
    for(int i=1;i<=26;i++) ch[i]=i+'A'-1 ;
    for(int i=27;i<=52;i++) ch[i]=i+'a'-27 ;
    int n,fir=1;
    while(scanf("%d",&n)!=EOF)
    {
        printf("2 %d %d\n",n,n) ;
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=n;j++) printf("%c",ch[i]);
            printf("\n");
        }
        printf("\n");
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=n;j++) printf("%c",ch[j]);
            printf("\n");
        }
        printf("\n");
    }
}
