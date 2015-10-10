#include<bits/stdc++.h>
using namespace std;
const int maxn=200 ;
char s[maxn] ;
main()
{
    int n ; scanf("%d%s",&n,s) ;
    int i ;
    for(i=0;i<n && s[i]=='1';i++) ;
    printf("%d\n",min(i+1,n)) ;
}
