#include<stdio.h>
#include<string.h>
#include<algorithm>
using namespace std;
main()
{
    char s[10000],t[10000] ;
    while(scanf("%s%s",s,t)!=EOF)
    {
        int n=strlen(s) , m=strlen(t) ;
        int cnt1,cnt2 ;
        for(cnt1=0;cnt1<n;cnt1++)
        {
            bool yes=1 ;
            for(int i=0;i<m;i++) if(i+cnt1<n && s[i+cnt1]=='2' && t[i]=='2')
                yes=0 ;
            if(yes) break ;
        }
        for(cnt2=0;cnt2<m;cnt2++)
        {
            bool yes=1 ;
            for(int i=0;i<n;i++) if(i+cnt2<m && t[i+cnt2]=='2' && s[i]=='2')
                yes=0 ;
            if(yes) break ;
        }
        int ans=max(m+cnt1,n) ;
        ans=min(ans,max(n+cnt2,m)) ;
        printf("%d\n",ans) ;
    }
}
