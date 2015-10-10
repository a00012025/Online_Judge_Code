#include<stdio.h>
int a[500001],left[500001],right[500001] ;
long long s[500001] ;
main()
{
 int n;
 while(scanf("%d",&n)==1)
 {
 s[0]=0 ;
 for(int i=1;i<=n;i++)
    {
    scanf("%d",&a[i]) ;
    s[i]=s[i-1]+a[i] ;
    }
 if(s[n]%3!=0){printf("0\n") ; continue ;}
 int num1=0,num2=0 ;
 for(int i=1;i<=n;i++)
    {
    if((s[i-1]==s[n]/3) && (i!=1) && (i!=n)) {num1++ ; left[num1]=i ;}
    if((s[i]==2*s[n]/3) && (i!=n) && (i!=1)) {num2++ ; right[num2]=i ;}
    }
 long long ans=0 ; int j=1 ;
 for(int i=1;i<=num1;i++)
    {
    for(;right[j]<left[i];j++) ;
    ans+=num2+1-j ;
    }
 printf("%I64d\n",ans) ;
 }
}
