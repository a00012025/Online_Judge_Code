#include<bits/stdc++.h>
using namespace std;
const int maxn=100+10 ;
int p[maxn] ;
char s[maxn],t[maxn] ;
main()
{
    int L,n,m ; scanf("%d%d%d",&L,&n,&m) ;
    for(int i=1;i<=n;i++) scanf("%d",&p[i]) ;
    while(L--)
    {
        scanf("%s",s+1) ;
        int len=strlen(s+1) ;
        if(len<n) for(int i=len+1;i<=n;i++) s[i]='#' ;
        for(int i=1;i<=n;i++)
        {
            int x=i ;
            for(int j=1;j<=m;j++) x=p[x] ;
            t[x]=s[i] ;
        }
        printf("%s\n",t+1) ;
    }
}
