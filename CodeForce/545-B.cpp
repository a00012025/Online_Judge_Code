#include<bits/stdc++.h>
using namespace std;
const int maxn=100000+10 ;

char s[maxn],t[maxn],p[maxn] ;
main()
{
    scanf("%s%s",s+1,t+1) ;
    int n=strlen(s+1),now=0 ;
    for(int i=1;i<=n;i++)
    {
        if(s[i]==t[i]) p[i]='0' ;
        else
        {
            if(now==0) p[i]=s[i] ;
            else p[i]=t[i] ;
            now^=1 ;
        }
    }
    printf("%s\n",now?"impossible":p+1) ;
}
