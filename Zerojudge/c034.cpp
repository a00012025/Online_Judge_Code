#include<stdio.h>
#include<string.h>
main()
{
 int a[2000],i,j;
 char s[1001];
 memset(a,0,sizeof(a));
 while(1)
    {
    gets(s);
    if((s[0]=='0')&&(s[1]=='\0')) break;
    for(i=0;(s[i]>='0')&&(s[i]<='9');i++);
    i=i-1;
    for(j=0;j<=i;j++) a[i+1-j]+=s[j]-'0';
    }
 for(i=1;i<=1999;i++)
    {
    if(a[i]>=10)
        {
        a[i+1]+=a[i]/10;
        a[i]=a[i]%10;
        }
    }
 for(i=1999;a[i]==0;i--);
 for(j=i;j>=1;j--)printf("%d",a[j]);
}
