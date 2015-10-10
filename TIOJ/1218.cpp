#include<bits/stdc++.h>
using namespace std;
char s[10005];

main()
{
    while(scanf("%s",s)!=EOF)
    {
        int n=strlen(s) , i ;
        for(i=0;i<n && s[i]=='0';i++) ;
        if(i==n) return 0 ;
        if(i==n-1)
        {
            int x=s[i]-'0' ;
            if(x==1 || x==3) printf("LOSE WIN\n") ;
            else if(x==2) printf("WIN LOSE\n") ;
            else printf("WIN WIN\n") ;
        }
        else if((s[n-1]-'0')%2) printf("LOSE LOSE\n") ;
        else printf("WIN WIN\n") ;
    }
}
