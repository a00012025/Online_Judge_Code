#include<stdio.h>
#include<string.h>
main()
{
 int N,NN,n,sum,max,i;
 char s[50010];
 while(scanf("%d",&N)==1)
 {
 for(NN=1;NN<=N;NN++)
 {
 gets(s);
 while(strlen(s)==0) gets(s);
 n=strlen(s);
 max=0 ;
 for(sum=2;sum<=2*n;sum++)
    {
    if(sum%2==0)
        {
        for(i=1;(s[(sum/2)-1-i]==s[(sum/2)-1+i])
        &&((sum/2)-1-i>=0)&&((sum/2)-1+i<=n-1);i++) ;
        if(max<2*i-1) max=2*i-1 ;
        }
    else if(sum%2==1)
        {
        for(i=1;(s[(sum/2)-i]==s[(sum/2)-1+i])
        &&((sum/2)-i>=0)&&((sum/2)-1+i<=n-1);i++) ;
        if(max<2*i-2) max=2*i-2 ;
        }
    }
 printf("%d\n",max);
 }
 }
}
