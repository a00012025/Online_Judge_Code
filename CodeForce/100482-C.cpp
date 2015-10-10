#include<stdio.h>
#include<algorithm>
#include<string.h>
using namespace std;
char s[200010] ;
main()
{
    int T,cnt=0,a[30];
    scanf("%d",&T) ;
    while(++cnt && cnt<=T)
    {
        gets(s) ; int q ;
        while(s[0]=='\0' || s[0]==49 || s[0]=='\n') gets(s) ;
        printf("Case #%d:\n",cnt) ;
        scanf("%d",&q) ;
        while(q--)
        {
            char c; int l,r ;
            scanf("%c",&c) ;
            while(c!='g' && c!='s') scanf("%c",&c) ;
            scanf("%d %d",&l,&r) ;
            if(c=='s') sort(s+l,s+r+1) ;
            else
            {
                memset(a,0,sizeof(a)) ;
                for(int i=l;i<=r;i++) a[s[i]-'A'+1]++ ;
                for(int i=1;i<=26;i++) printf("%d ",a[i]);
                printf("\n") ;
            }
        }
    }
}
