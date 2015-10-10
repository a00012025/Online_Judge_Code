#include<stdio.h>
#include<algorithm>
#include<string.h>
using namespace std;
main()
{
    char s[500000] ;
    int a[30]={0} ;
    int i ;
    for(i=0;(s[i]=getchar())!=EOF;i++)
    {
        if(s[i]<'a') break ;
        a[s[i]-'a'+1]++ ;
    }
    int M=0 ;
    for(int j=1;j<=26;j++) M=max(M,a[j]) ;
    if(M>((strlen(s)-1)/2)) printf("NO\n");
    else if(!(strlen(s)%2)) printf("NO\n");
    else printf("YES\n") ;
}
