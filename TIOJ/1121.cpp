#include<bits/stdc++.h>
using namespace std;

string st[50] ;
char s[50] ;

main()
{
    int n ;
    while(scanf("%d%s",&n,s)!=EOF)
    {
        st[1]=string(s,s+n) ;
        for(int i=2;i<=n;i++) st[i]= string(s+i-1,s+n)+string(s,s+i-1) ;
        string tmp=st[2] ;
        sort(st+1,st+n+1) ;
        int ans ;
        for(int i=1;i<=n;i++)
        {
            printf("%c",st[i][n-1]) ;
            if(st[i]==tmp) ans=i ;
        }
        printf("\n%d\n",ans) ;
    }
}
