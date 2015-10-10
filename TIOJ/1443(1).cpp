#include<bits/stdc++.h>
#define DB long double
using namespace std;
const int maxn=1000000+10 ;

char s[maxn] ;
main()
{
    scanf("%s",s) ;
    int n=strlen(s),x ;
    for(x=n-1;s[x]=='9' && x>=0;x--) s[x]='0' ;
    if(x>=0) s[x]++ ;
    else
    {
        s[0]='1' ;
        s[n++]='0' ;
    }

    DB a=0.0 ;
    for(int i=0;i<n && i<40;i++) a += (s[i]-'0') * powl( 10.0, -i );
	printf( "%d\n", (int)(log2l(a)+(n-1)*log2l(10)+((DB)1e-10)) );
}

