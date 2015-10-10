#include<bits/stdc++.h>
using namespace std;
const int maxn=200 ;

char s[maxn] ;
int a[26] ;
main()
{
    int n ; scanf("%d%s",&n,s+1) ;
    for(int i=1;i<=n;i++)
    {
        if(s[i]>='a') a[s[i]-'a']=1 ;
        else a[s[i]-'A']=1 ;
    }
    printf("%s\n",count(a,a+26,1)==26?"YES":"NO") ;
}
