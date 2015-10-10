#include<stdio.h>
#include<string.h> 
main()
{
 int n,m,i,j,k,l;
 long long int Z ;
 char s[1000001] ; 
 while(scanf("%d",&n)==1)
    {
    gets(s); 
    for(i=1;i<=n;i++)
        { 
        gets(s);
        Z=0;
        for(j=0;j<strlen(s);)
            {
            m=0; 
            m+=s[j]-'0';
            for(k=j+1;(s[k]>='0')&&(s[k]<='9')&&(k<strlen(s));k++)
                {
                m=m*10;
                m+=s[k]-'0';
                }
            Z+=m ; 
            for(l=k;(s[l]>'9')||(s[l]<'0');l++);
            j=l;
            }
        printf("%lld\n",Z);
        }
    }
}
