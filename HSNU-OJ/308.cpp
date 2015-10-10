#include<bits/stdc++.h>
using namespace std;

char s[300] ;
main()
{
    int T ; scanf("%d",&T) ;
    while(T--)
    {
        scanf("%s",s) ; int len=strlen(s) ;
        int num=0,ans=0 ;
        for(int i=0;i<len;i++) if(s[i]!='.')
        {
            if(s[i]=='p') num++ ;
            if(s[i]=='q' && num) ans++ , num-- ;
        }
        printf("%d\n",ans) ;
    }
}
