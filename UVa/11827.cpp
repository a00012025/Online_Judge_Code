#include<stdio.h>
#include<string.h>
#include<algorithm>
using namespace std;
int gcd(int x,int y)
{
    while(x!=0 && y!=0)
    {
        if(x>y) x=x%y ;
        else y=y%x ;
    }
    if(!x) return y ;
    else return x ;
}
main()
{
    int T,a[200];
    char s[50000] ;
    scanf("%d",&T) ;
    while(T--)
    {
        gets(s) ;
        while(s[0]<'0' || s[0]>'9') gets(s) ;
        int num=0,cnt=0 ;
        for(;num<strlen(s);)
        {
            cnt++ ;
            sscanf(s+num,"%d",&a[cnt]) ;
            for(;num<strlen(s) && s[num]!=' ';num++) ;
            for(;num<strlen(s) && s[num]==' ';num++) ;
        }
        int ans=0 ;
        for(int i=1;i<=cnt;i++) for(int j=i+1;j<=cnt;j++)
            ans=max(ans,gcd(a[i],a[j])) ;
        printf("%d\n",ans) ;
    }
}
