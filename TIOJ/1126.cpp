#include<bits/stdc++.h>
using namespace std;
char s[100] ;

bool check(int l,int r)
{
    for(int i=l;i<=r;i++) if(s[i]!=s[l+r-i]) return 0 ;
    return 1 ;
}

main()
{
    while(scanf("%s",s)!=EOF)
    {
        int n=strlen(s) ;
        bool ok=0 ;
        for(int i=n;!ok && i>=1;i--)
            for(int j=0;!ok && j+i-1<n;j++)
            if(check(j,j+i-1))
        {
            printf("%d\n",i) ;
            ok=1 ;
        }
    }
}
