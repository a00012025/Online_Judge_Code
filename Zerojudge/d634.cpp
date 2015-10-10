#include<stdio.h>
#include<string.h>
#include<algorithm>
using namespace std;
char a[100001][12];
main()
{
 int n,i,j;
 char s[12];
 while(scanf("%d",&n)==1)
 {
 for(i=1;i<=n;i++) 
    {
    gets(s);
    if(s[0]==0)
        {
        i=i-1;
        continue;
        }
    for(j=0;j<strlen(s);j++) a[i][j]=s[j];
    }
 printf("%s\n",a[1]);
 }
}
