#include<stdio.h>
#include<algorithm>
using namespace std;
main()
{
    int n,fir=1 ;
    char s[20],t[20] ;
    while(scanf("%d",&n)==1 && n)
    {
        int l=1,r=10,lie=0 ;
        scanf("%s %s",s,t) ;
        if(t[0]=='o') {printf("Stan may be honest\n") ; continue ;}
        if(t[0]=='h') r=n-1 ;
        else if(t[0]=='l') l=n+1 ;
        while(1)
        {
            int m;
            scanf("%d %s %s",&m,s,t) ;
            if(t[0]=='o') {if(m>r || m<l) lie=1 ; break ;}
            if(m>=r && t[0]=='l') lie=1 ;
            else if(m<=l && t[0]=='h') lie=1 ;
            else
            {
                if(t[0]=='l') l=max(l,m+1) ;
                else r=min(r,m-1) ;
            }
        }
        if(lie) printf("Stan is dishonest\n") ;
        else printf("Stan may be honest\n") ;
    }
}
