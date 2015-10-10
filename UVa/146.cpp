#include<stdio.h>
#include<algorithm>
#include<string.h>
using namespace std;
main()
{
    char s[100] ;
    while(gets(s))
    {
        if(s[0]=='#') break;
        int i ;
        for(i=0;i<strlen(s)-1 && s[i]>=s[i+1];i++) ;
        if(i==strlen(s)-1) printf("No Successor\n") ;
        else
        {
            next_permutation(&s[0],&s[strlen(s)]) ;
            for(int j=0;j<strlen(s);j++) printf("%c",s[j]) ;
            printf("\n") ;
        }
    }
}
