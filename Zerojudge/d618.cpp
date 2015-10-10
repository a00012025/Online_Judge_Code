#include<stdio.h>
#include<string.h>
char s[25];
char f(int a)
    {
    if((s[a-1]=='2')&&(s[a]=='1')) return '1';
    if(s[a-1]=='2') return '2';
    if((s[a-1]=='3')&&(s[a]=='4')) return '4';
    if((s[a-1]=='3')&&(s[a]=='1')) return '1';
    if(s[a-1]=='3') return '3';
    if((s[a-1]=='4')&&(s[a]=='3')) return '3';
    if((s[a-1]=='4')&&(s[a]=='1')) return '1';
    if(s[a-1]=='4') return '4';
    if((s[a-1]=='1')||(s[a-1]=='5')||(s[a-1]=='6')||(s[a-1]=='7')) return s[a];
    }
main()
{
 int i,j,n,zz;
 while(scanf("%d",&n)==1)
 {
 for(zz=1;zz<=n;zz++)
    {
    gets(s);
    if((s[0]>'9')||(s[0]<'0'))
        {
        zz=zz-1;
        continue;
        }
    for(i=1;i<strlen(s);i++) s[i]=f(i);
    printf("%c\n",s[strlen(s)-1]);
    }
 }
}
